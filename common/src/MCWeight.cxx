#include "UHH2/common/include/BTagCalibrationStandalone.h"
#include "UHH2/common/include/MCWeight.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/core/include/Utils.h"

#include "TFile.h"
#include "TH1F.h"

#include <stdexcept>

using namespace uhh2;
using namespace std;

MCLumiWeight::MCLumiWeight(Context & ctx){
    use_sframe_weight = string2bool(ctx.get("use_sframe_weight", "true"));
    if(use_sframe_weight){
        return;
    }
    auto dataset_type = ctx.get("dataset_type");
    bool is_mc = dataset_type == "MC";
    if(!is_mc){
        cout << "Warning: MCLumiWeight will not have an effect on this non-MC sample (dataset_type = '" + dataset_type + "')" << endl;
        return;
    } else {
        double dataset_lumi = string2double(ctx.get("dataset_lumi"));
        double reweight_to_lumi = string2double(ctx.get("target_lumi"));
        if(reweight_to_lumi <= 0.0){
            throw runtime_error("MCLumiWeight: target_lumi <= 0.0 not allowed");
        }
        factor = reweight_to_lumi / dataset_lumi;
    }
}

bool MCLumiWeight::process(uhh2::Event & event){
    if(!use_sframe_weight){
        event.weight *= factor;
    }
    return true;
}



MCPileupReweight::MCPileupReweight(Context & ctx){

   auto dataset_type = ctx.get("dataset_type");
   bool is_mc = dataset_type == "MC";
   if(!is_mc){
       cout << "Warning: MCPileupReweight will not have an effect on this non-MC sample (dataset_type = '" + dataset_type + "')" << endl;
       return;
   }

   TString pileup_directory_data = ctx.get("pileup_directory_data");
   TString pileup_directory_50ns;
   TString pileup_directory_25ns;
   if (ctx.get("dataset_version").find("50ns")!=std::string::npos) pileup_directory_50ns = ctx.get("pileup_directory_50ns"); 
   else pileup_directory_25ns = ctx.get("pileup_directory_25ns");

   if(pileup_directory_data == ""){
      throw runtime_error("MCPileupReweight: not yet implemented!");
   }
   TFile *file_mc;
   if (ctx.get("dataset_version").find("50ns")!=std::string::npos) file_mc = new TFile(pileup_directory_50ns);
   else file_mc = new TFile(pileup_directory_25ns);
   TFile *file_data =  new TFile(pileup_directory_data);
   
   h_npu_mc=(TH1F*) file_mc->Get("input_Event/N_TrueInteractions");
   h_npu_data=(TH1F*) file_data->Get("pileup");
   
   
   if(h_npu_mc->GetNbinsX() != h_npu_data->GetNbinsX()){
      std::cerr << "ERROR: pile-up histograms for data and MC have different numbers of bins" <<std::endl;
      exit(-1);
   }
   if( (h_npu_mc->GetXaxis()->GetXmax() != h_npu_data->GetXaxis()->GetXmax()) || (h_npu_mc->GetXaxis()->GetXmin() != h_npu_data->GetXaxis()->GetXmin())){
      std::cerr << "ERROR: pile-up histograms for data and MC have different axis ranges" <<std::endl;
      exit(-1);
   }
   
   h_npu_mc->Scale(1./h_npu_mc->Integral());
   h_npu_data->Scale(1./h_npu_data->Integral());
}

bool MCPileupReweight::process(Event &event){

   if (event.isRealData) {
      return true;
   }

   double weight =0;
   int binnumber = h_npu_mc->GetXaxis()->FindBin(event.genInfo->pileup_TrueNumInteractions());
   
   if(h_npu_mc->GetBinContent(binnumber)!=0){
      weight = h_npu_data->GetBinContent(binnumber)/h_npu_mc->GetBinContent(binnumber);
   }
   
   event.weight *= weight;       
   return true;
}

MCScaleVariation::MCScaleVariation(Context & ctx){

  auto dataset_type = ctx.get("dataset_type");
  bool is_mc = dataset_type == "MC";
  if(!is_mc){
    cout << "Warning: MCScaleVariation will not have an effect on this non-MC sample (dataset_type = '" + dataset_type + "')" << endl;
    return;
  }
  auto s_mu_r = ctx.get("ScaleVariationMuR");
  auto s_mu_f = ctx.get("ScaleVariationMuF");

  if(s_mu_r == "up") {i_mu_r = 1;}
  else if(s_mu_r == "down"){i_mu_r = 2;}

  if(s_mu_f == "up"){i_mu_f = 1;}
  else if(s_mu_f == "down"){i_mu_f = 2;}

}

bool MCScaleVariation::process(Event & event){
  if (event.isRealData) {return true;}
  if(event.genInfo->systweights().size() == 0) return true;

  if(i_mu_r == 0 && i_mu_f == 0) return true;
  else if(i_mu_r == 0 && i_mu_f == 1) syst_weight = event.genInfo->systweights().at(1);
  else if(i_mu_r == 0 && i_mu_f == 2) syst_weight = event.genInfo->systweights().at(2);
                                      
  else if(i_mu_r == 1 && i_mu_f == 0) syst_weight = event.genInfo->systweights().at(3);
  else if(i_mu_r == 1 && i_mu_f == 1) syst_weight = event.genInfo->systweights().at(4);
  else if(i_mu_r == 1 && i_mu_f == 2) syst_weight = event.genInfo->systweights().at(5);
                                      
  else if(i_mu_r == 2 && i_mu_f == 0) syst_weight = event.genInfo->systweights().at(6);
  else if(i_mu_r == 2 && i_mu_f == 1) syst_weight = event.genInfo->systweights().at(7);
  else if(i_mu_r == 2 && i_mu_f == 2) syst_weight = event.genInfo->systweights().at(8);

  event.weight *= syst_weight/event.genInfo->originalXWGTUP();

  return true;
}



MCBTagScaleFactor::MCBTagScaleFactor(uhh2::Context & ctx,
                                     const CSVBTag::wp & working_point,
                                     std::string jets_handle_name,
                                     std::string sysType,
                                     std::string measType_bc,
                                     std::string measType_udsg):
  btag_(CSVBTag(working_point)),
  h_jets_(ctx.get_handle<std::vector<Jet>>(jets_handle_name)),
  h_topjets_(ctx.get_handle<std::vector<TopJet>>(jets_handle_name)),
  sysType_(sysType),
  h_btag_weight_(ctx.declare_event_output<float>("btag_weight")),
  h_btag_weight_up_(ctx.declare_event_output<float>("btag_weight_up")),
  h_btag_weight_down_(ctx.declare_event_output<float>("btag_weight_down"))
{
  auto dataset_type = ctx.get("dataset_type");
  bool is_mc = dataset_type == "MC";
  if (!is_mc) {
    cout << "Warning: MCBTagScaleFactor will not have an effect on "
         <<" this non-MC sample (dataset_type = '" + dataset_type + "')" << endl;
    return;
  }

  TFile eff_file(ctx.get("MCBtagEfficiencies").c_str());
  if (eff_file.IsZombie()) {
    cout << "Warning: MCBTagScaleFactor will not have an effect because the root-file "
         << "with MC-efficiencies not found: " << ctx.get("MCBtagEfficiencies") << endl;
    eff_file.Close();
    return;
  }
  eff_b_.reset((TH2*) eff_file.Get("BTagMCEffFlavBEff"));
  eff_c_.reset((TH2*) eff_file.Get("BTagMCEffFlavCEff"));
  eff_udsg_.reset((TH2*) eff_file.Get("BTagMCEffFlavUDSGEff"));
  eff_b_->SetDirectory(0);
  eff_c_->SetDirectory(0);
  eff_udsg_->SetDirectory(0);
  eff_file.Close();

  // https://twiki.cern.ch/twiki/bin/viewauth/CMS/BTagCalibration
  BTagCalibration calib_data("CSVv2", ctx.get("BTagCalibration"));
  auto op = working_point == CSVBTag::WP_LOOSE ? BTagEntry::OP_LOOSE : (
                working_point == CSVBTag::WP_MEDIUM ? BTagEntry::OP_MEDIUM :
                    BTagEntry::OP_TIGHT);

  calib_up_.reset(new BTagCalibrationReader(op, "up"));
  calib_.reset(new BTagCalibrationReader(op, "central"));
  calib_down_.reset(new BTagCalibrationReader(op, "down"));

  calib_up_->load(calib_data, BTagEntry::FLAV_B, measType_bc);
  calib_up_->load(calib_data, BTagEntry::FLAV_C, measType_bc);
  calib_up_->load(calib_data, BTagEntry::FLAV_UDSG, measType_udsg);
  calib_->load(calib_data, BTagEntry::FLAV_B, measType_bc);
  calib_->load(calib_data, BTagEntry::FLAV_C, measType_bc);
  calib_->load(calib_data, BTagEntry::FLAV_UDSG, measType_udsg);
  calib_down_->load(calib_data, BTagEntry::FLAV_B, measType_bc);
  calib_down_->load(calib_data, BTagEntry::FLAV_C, measType_bc);
  calib_down_->load(calib_data, BTagEntry::FLAV_UDSG, measType_udsg);
}

bool MCBTagScaleFactor::process(Event & event) {

  if (!calib_) {
    event.set(h_btag_weight_up_, 1.);
    event.set(h_btag_weight_, 1.);
    event.set(h_btag_weight_down_, 1.);
    return true;
  }

  float weight, weightErr;
  if (event.is_valid(h_topjets_)) {
    std::tie(weight, weightErr) = get_weight_btag(event.get(h_topjets_), event);
  } else {
    assert(event.is_valid(h_jets_));
    TopJet tj;
    tj.set_subjets(event.get(h_jets_));
    std::tie(weight, weightErr) = get_weight_btag(vector<TopJet>({tj}), event);
  }

  float weight_up = weight + weightErr;
  float weight_down = weight - weightErr;
  event.set(h_btag_weight_up_, weight_up);
  event.set(h_btag_weight_, weight);
  event.set(h_btag_weight_down_, weight_down);

  if (sysType_ == "up") {
    event.weight *= weight_up;
  } else if (sysType_ == "down") {
    event.weight *= weight_down;
  } else {
    event.weight *= weight;
  }

  return true;
}


// originally taken from https://twiki.cern.ch/twiki/pub/CMS/BTagSFMethods/Method1aExampleCode_CSVM.cc.txt
std::pair<float, float> MCBTagScaleFactor::get_weight_btag(const vector<TopJet> &jets, Event & event) {

  float mcTag = 1.;
  float mcNoTag = 1.;
  float dataTag = 1.;
  float dataNoTag = 1.;

  float err1 = 0.;
  float err2 = 0.;
  float err3 = 0.;
  float err4 = 0.;

  //Here we loop over all selected jets
  for (const auto & topjet : jets) { for (const auto & jet : topjet.subjets()) {

    int hadronFlavor = abs(jet.hadronFlavor());
    float abs_eta = fabs(jet.eta());
    float pt = jet.pt();

    if(abs_eta > 2.4) {
      continue;
    }

    TH2* eff_hist;
    if (hadronFlavor == 5) {
      ///here one need to provide the pt/eta dependent efficiency for b-tag for "b jet"
      eff_hist = eff_b_.get();
    }else if( hadronFlavor==4){
      ///here one need to provide the pt/eta dependent efficiency for b-tag for "c jet"
      eff_hist = eff_c_.get();
    }else{
      ///here one need to provide the pt/eta dependent efficiency for b-tag for "light jet"
      eff_hist = eff_udsg_.get();
    }
    const auto eff_pt_axis = eff_hist->GetXaxis();
    float pt_low_edge = eff_pt_axis->GetBinLowEdge(eff_pt_axis->GetFirst());
    float pt_high_edge = eff_pt_axis->GetBinUpEdge(eff_pt_axis->GetLast());
    float pt_for_eff = (pt > pt_low_edge) ? pt : pt_low_edge + 1e-5;
    pt_for_eff = (pt_for_eff < pt_high_edge) ? pt_for_eff : pt_high_edge - 1e-5;
    float eff = eff_hist->GetBinContent(eff_hist->FindFixBin(pt_for_eff, abs_eta));

    float SF = 0.;
    float SFerr = 0.;
    std::tie(SF, SFerr) = get_SF_btag(pt, abs_eta, hadronFlavor);

    if (btag_(jet, event)) {
      mcTag *= eff;
      dataTag *= eff*SF;

      if(hadronFlavor==5 || hadronFlavor ==4)  err1 += SFerr/SF; ///correlated for b/c
      else err3 += SFerr/SF; //correlated for light

    }else{
      mcNoTag *= (1- eff);
      dataNoTag *= (1- eff*SF);

      if(hadronFlavor==5 || hadronFlavor ==4 ) err2 += (-eff*SFerr)/(1-eff*SF); /// /correlated for b/c
      else err4 +=  (-eff*SFerr)/(1-eff*SF);  ////correlated for light

    }

  }}

  float wtbtag = (dataNoTag * dataTag ) / ( mcNoTag * mcTag ); 
  float wtbtagErr = sqrt( pow(err1+err2,2) + pow( err3 + err4,2)) * wtbtag;  ///un-correlated for b/c and light

  return std::make_pair(wtbtag, wtbtagErr);
}


// originally taken from https://twiki.cern.ch/twiki/pub/CMS/BTagSFMethods/Method1aExampleCode_CSVM.cc.txt
// (only the purpose of the function is the same, interface and implementation changed)
std::pair<float, float> MCBTagScaleFactor::get_SF_btag(float pt, float abs_eta, int flav) {

  auto btagentry_flav = flav == 5 ? BTagEntry::FLAV_B : (
                            flav == 4 ? BTagEntry::FLAV_C : 
                                BTagEntry::FLAV_UDSG);

  auto sf_bounds = calib_->min_max_pt(btagentry_flav, abs_eta);

  float pt_for_eval = pt;
  bool out_of_bounds = false;
  if (pt < sf_bounds.first) {
    pt_for_eval = sf_bounds.first + 1e-5;
    out_of_bounds = true;
  } else if (pt > sf_bounds.second) {
    pt_for_eval = sf_bounds.second - 1e-5;
    out_of_bounds = true;
  }

  float SF_up   = calib_up_->eval(btagentry_flav, abs_eta, pt_for_eval);
  float SF      = calib_->eval(btagentry_flav, abs_eta, pt_for_eval);
  float SF_down = calib_down_->eval(btagentry_flav, abs_eta, pt_for_eval);

  float SFerr_up_ = fabs(SF - SF_up);
  float SFerr_down_ = fabs(SF - SF_down);  // positive value!!

  float SFerr = SFerr_up_ > SFerr_down_ ? SFerr_up_ : SFerr_down_;

  if (out_of_bounds) {
    SFerr *= 2;
  }

  return std::make_pair(SF, SFerr);
}
