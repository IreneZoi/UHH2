#include "UHH2/common/include/GenJetsHists.h"
#include "UHH2/common/include/JetHists.h"
#include "UHH2/common/include/Utils.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/core/include/LorentzVector.h"


using namespace uhh2;
using namespace std;


//Gen Jet Hists
GenJetsHists::GenJetsHists(Context & ctx,
			   const std::string & dname,
			   const unsigned int NumberOfPlottedJets,
			   const std::string & collection_):  Hists(ctx, dname), collection(collection_){
    number = book<TH1F>("number","number of genjets",21, -.5, 20.5);
    alljets = book_ParticleHist("genjet","_genjet",20,1500);
    vector<double> minPt {20,20,20,20};
    vector<double> maxPt {1500,1000,500,350};
    vector<string> axis_suffix {"first jet","second jet","third jet","fourth jet"};
    for(unsigned int i =0; i<NumberOfPlottedJets; i++){
      if(i<4){
        single_ParticleHists.push_back(book_ParticleHist(axis_suffix[i],"_"+to_string(i+1),minPt[i],maxPt[i]));
      }
      else {
        single_ParticleHists.push_back(book_ParticleHist(to_string(i+1)+"-th jet","_"+to_string(i+1),20,500));
      }
    }
    if(!collection.empty()){
        h_jets = ctx.get_handle<std::vector<Particle> >(collection);
    }

}
void GenJetsHists::fill_ParticleHist(const Particle & jet, ParticleHist & particle_hist, double  weight){
  particle_hist.pt->Fill(jet.pt(), weight);
  particle_hist.eta->Fill(jet.eta(), weight);
  particle_hist.phi->Fill(jet.phi(), weight);
  particle_hist.mass->Fill(jet.v4().M(), weight);
}
GenJetsHists::ParticleHist GenJetsHists::book_ParticleHist(const string & axisSuffix, const string & histSuffix, double minPt, double maxPt){
  ParticleHist particle_hist;
  particle_hist.pt = book<TH1F>("pt"+histSuffix,"p_{T} "+axisSuffix,50,minPt,maxPt);
  particle_hist.eta = book<TH1F>("eta"+histSuffix,"#eta "+axisSuffix,100,-5,5);
  particle_hist.phi = book<TH1F>("phi"+histSuffix,"#phi "+axisSuffix,50,-M_PI,M_PI);
  particle_hist.mass = book<TH1F>("mass"+histSuffix,"M^{ "+axisSuffix+"} [GeV/c^{2}]", 100, 0, 300);
  return particle_hist;
}

void GenJetsHists::fill(const uhh2::Event & event){
  if(event.isRealData) return;
  auto w = event.weight;
  if (!collection.empty() && !event.is_valid(h_jets)){
    cerr<<collection<<" is invalid. Going to abort from GenJetsHists class"<<endl;
    assert(1==0);
  }
  vector<Particle> jets = collection.empty() ?  *event.genjets : event.get(h_jets);
  number->Fill(jets.size(), w);
  for(unsigned int i = 0; i <jets.size(); i++){
    const auto & jet = jets[i];
    fill_ParticleHist(jet,alljets,w);
    if(i < single_ParticleHists.size()){
      fill_ParticleHist(jet, single_ParticleHists[i], w);
    }
  }
}


//----------------------------------------------     irene 
//****************************** GenTopJet Histograms                                                                                                                                                                               
/*

 
GenTopJetHists::subjetHist GenTopJetHists::book_subjetHist(const std::string & axisSuffix, const std::string & histSuffix, double minPt, double maxPt){
  subjetHist subjet_hist;

  subjet_hist.number = book<TH1F>("number"+histSuffix,"number "+axisSuffix,7, -.5, 6.5);

  subjet_hist.pt = book<TH1F>("pt"+histSuffix,"p_{T} "+axisSuffix,50,minPt,maxPt);
  subjet_hist.eta = book<TH1F>("eta"+histSuffix,"#eta "+axisSuffix,100,-5,5);
  subjet_hist.phi = book<TH1F>("phi"+histSuffix,"#phi "+axisSuffix,50,-M_PI,M_PI);
  subjet_hist.mass = book<TH1F>("mass"+histSuffix,"M^{ "+axisSuffix+"} [GeV/c^{2}]", 100, 0, 200);
  subjet_hist.sum4Vec = book<TH1F>("sum_mass"+histSuffix,"Mass sum  "+axisSuffix,100,0,350);

  return subjet_hist;
}

void GenTopJetHists::fill_subjetHist(const GenTopJet & topjet, subjetHist & subjet_hist, double weight){
  auto subjets = topjet.subjets();
  subjet_hist.number->Fill(subjets.size(),weight);
  LorentzVector sumLorenzv4;
  for (auto & subjet : subjets) {
    subjet_hist.pt->Fill(subjet.pt(), weight);
    subjet_hist.eta->Fill(subjet.eta(), weight);
    subjet_hist.phi->Fill(subjet.phi(), weight);
    subjet_hist.mass->Fill(subjet.v4().M(), weight);
    sumLorenzv4 += subjet.v4();
  }
  subjet_hist.sum4Vec->Fill(sumLorenzv4.M(), weight);
}

GenJetsHists::ParticleHist GenTopJetHists::book_topJetHist(const std::string & axisSuffix, const std::string & histSuffix, double minPt, double maxPt) {
  auto jet_hist = book_jetHist(axisSuffix, histSuffix, minPt, maxPt);
  //  jet_hist.mvahiggsdiscr = book<TH1F>("mvahiggsdiscr"+histSuffix,"mva-higgs-disriminator "+axisSuffix,50,0,1);
  //jet_hist.prunedmass = book<TH1F>("mass_pruned"+histSuffix,"M^{ "+axisSuffix+"}_{pruned} [GeV/c^{2}]", 100, 0, 300);
  // jet_hist.subjet_sum_mass = book<TH1F>("mass_subjet_sum"+histSuffix,"M^{ "+axisSuffix+"}_{subjet sum} [GeV/c^{2}]", 100, 0, 300);
  jet_hist.CHF = book<TH1F>("CHF"+histSuffix,"Charged Hadron Energy Fraction"+axisSuffix, 100, 0, 1); //irene for CHF                                                                                        
  jet_hist.tau21 = book<TH1F>("tau21"+histSuffix, "#tau_{2}/#tau_{1}", 50, 0, 1.0); //irene for tau21 for various jets                                                                                       
  return jet_hist;
}

void GenTopJetHists::fill_topJetHist(const GenTopJet & jet, GenJetsHists::jetHist & jet_hist, double  weight) {
  fill_jetHist(jet, jet_hist, weight);
  LorentzVector subjet_sum;
  for (const auto s : jet.subjets()) {
    subjet_sum += s.v4();
  }

  //jet_hist.subjet_sum_mass->Fill(subjet_sum.M(), weight);
  jet_hist.CHF->Fill(jet.chf(), weight); //irene for CHF                                                                                                                             
  jet_hist.tau21->Fill(jet.tau2()/jet.tau1(),weight);  //irene for tau21 for various jets                                                                                                                    
}

GenTopJetHists::GenTopJetHists(Context & ctx,
			 const std::string & dname,
			 const unsigned int NumberOfPlottedJets,
			 const std::string & collection_): GenJetHists(ctx, dname), collection(collection_) {

  number = book<TH1F>("number","number of topjets",21, -.5, 20.5);
  alljets = book_topJetHist("topjet","",20,1500);
  allsubjets = book_subjetHist("subjet","_subjets",0,500);
  vector<double> maxPt {1500,600,400,300}; //irene changed from 900 to 1400                                                                                                                                  
  string axis_suffix = "topjet";
  string axis_subjetSuffix = "subjets ";
  vector<string> axis_singleSubjetSuffix {"first ","second ","third ","fourth "};
  for(unsigned int i =0; i<NumberOfPlottedJets; i++){
    if(i<4){
      single_jetHists.push_back(book_topJetHist(axis_singleSubjetSuffix[i]+axis_suffix,string("_")+to_string(i+1),0,maxPt[i]));
      subjets.push_back(book_subjetHist(axis_subjetSuffix+axis_singleSubjetSuffix[i]+axis_suffix,string("_")+to_string(i+1)+string("_subj"),0,maxPt[i]));
    }
    else{
      single_jetHists.push_back(book_topJetHist(to_string(i+1)+string("-th jet"),string("_")+to_string(i+1),20,500));
      subjets.push_back(book_subjetHist(axis_subjetSuffix+to_string(i+1)+string("-th subjet")+axis_suffix,string("_")+to_string(i+1)+string("_subj"),0,maxPt[i]));
    }
  }
  deltaRmin_1 = book<TH1F>("deltaRmin_1", "#Delta R_{min}(first jet,nearest jet)", 40, 0, 8.0);
  deltaRmin_2 = book<TH1F>("deltaRmin_2", "#Delta R_{min}(2nd jet,nearest jet)", 40, 0, 8.0);
  tau32 = book<TH1F>("tau32", "#tau_{3}/#tau_{2}", 50, 0, 1.0);
  //irene for tau21 for various jets  tau21 = book<TH1F>("tau21", "#tau_{2}/#tau_{1}", 50, 0, 1.0);                                                                                                          
  deltaR_ak4jet= book<TH1F>("deltaR_ak4jet", "#Delta R(jet,ak4 jet)", 40, 0, 8.0);
  invmass_topjetak4jet = book<TH1F>("invmass_topjetak4jet", "invariant mass(jet,ak4 jet)", 100, 0, 1000);
  deltaR_lepton= book<TH1F>("deltaR_lepton", "#Delta R(jet,lepton)", 40, 0, 8.0);
  HTT_mass = book<TH1F>("HTT_mass", "HTT mass", 100, 0, 1000);
  fRec = book<TH1F>("fRec", "fRec", 50,0,1);

  if(!collection.empty()){
    h_gentopjets = ctx.get_handle<std::vector<GenTopJet> >(collection);
  }
}

void GenTopJetHists::add_iTopJetHists(unsigned int UserJet, double minPt, double maxPt, double minPt_sub, double maxPt_sub, const std::string & axisSuffix, const std::string & histSuffix ){
  m_usertopjet.push_back(UserJet);
  usertopjets.push_back(book_topJetHist(axisSuffix,histSuffix, minPt, maxPt));
  usersubjets.push_back(book_subjetHist(axisSuffix+"_sub", histSuffix+"_sub", minPt_sub, maxPt_sub));
}
void GenTopJetHists::fill(const Event & event){
  auto w = event.weight;
  vector<GenTopJet> jets = collection.empty() ? *event.gentopjets : event.get(h_gentopjets);
  vector<Jet> ak4jets = *event.jets;

  //assert(jets);                                                                                                                                                                                          
  number->Fill(jets.size(), w);
  for(unsigned int i = 0; i <jets.size(); i++){
    const auto & jet = jets[i];
    fill_topJetHist(jet,alljets,w);
    fill_subjetHist(jet,allsubjets,w);
    tau32->Fill(jet.tau3()/jet.tau2(),w);
    //irene for tau21 for various jets      tau21->Fill(jet.tau2()/jet.tau1(),w);                                                                                                                          
    for (unsigned int m =0; m<m_usertopjet.size(); ++m){
      if(m_usertopjet[m] == i){
	fill_topJetHist(jet,usertopjets[m],w);
	fill_subjetHist(jet,usersubjets[m],w);
      }
    }
    if(i < single_jetHists.size()){
      fill_topJetHist(jet,single_jetHists[i],w);
      fill_subjetHist(jet,subjets[i],w);
    }
    if(i<2){
      auto next_jet = closestParticle(jet, jets);
      auto drmin = next_jet ? deltaR(jet, *next_jet) : numeric_limits<float>::infinity();
      if(i==0)deltaRmin_1->Fill(drmin, w);
      else deltaRmin_2->Fill(drmin, w);
    }

    for (unsigned int j = 0; j <ak4jets.size(); j++)
      {
	const auto & ak4jet = ak4jets[i];
	double deltaRtopjetak4jet = deltaR(jet, ak4jet);
	deltaR_ak4jet->Fill(deltaRtopjetak4jet,w);
	invmass_topjetak4jet->Fill((jet.v4()+ak4jet.v4()).M(),w);
      }

    vector<Muon> muons = *event.muons;
    for (unsigned int j = 0; j <muons.size(); j++){
      double deltaRtjlepton = deltaR(jet, muons[j]);
      deltaR_lepton->Fill(deltaRtjlepton, w);
    }
    vector<Electron> electrons = *event.electrons;
    for (unsigned int j = 0; j <electrons.size(); j++){
      double deltaRtjlepton = deltaR(jet, electrons[j]);
      deltaR_lepton->Fill(deltaRtjlepton, w);
    }

  }

}
template<typename T>
bool GenJetHistsBase::passes_id(const T & object, const Event & event, const boost::optional<std::function<bool (const T &, const Event & )>> & object_id){
  if((*object_id)(object, event))
    return true;
  return false;
}

*/
