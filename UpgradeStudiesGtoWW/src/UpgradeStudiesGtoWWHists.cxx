#include "UHH2/UpgradeStudiesGtoWW/include/UpgradeStudiesGtoWWHists.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/common/include/JetHists.h"
#include "UHH2/core/include/TopJet.h"
#include "UHH2/core/include/LorentzVector.h"
#include "TH1F.h"
#include "TH2F.h"
#include <iostream>

using namespace std;
using namespace uhh2;
using namespace uhh2examples;

UpgradeStudiesGtoWWHists::UpgradeStudiesGtoWWHists(Context & ctx, const string & dirname): Hists(ctx, dirname){

  //******************* book all histograms here *****************************


  

  // ### top jets & getn top jets ###

  book<TH1F>("Mass_Ratio", "(RecoJetMass-GenJetMass)/GenJetMass", 100, -1, 7); //irene
  book<TH1F>("JEC", "JEC factor", 50,0, 1.4); //irene        
  book<TH1F>("JECreciprocal", "1/JEC factor", 50,0, 1.4); //irene        
  book<TH1F>("JEC_L1", "JEC L1 factor", 50,0, 1.4); //irene        
  
  book<TH1F>("Tau_RatioDiff", "(RecoTau21-GenTau21)/GenTau21", 100,-1, 7); //irene        
  book<TH1F>("Tau_Ratio", "RecoTau21/GenTau21", 100,0, 7); //irene        
  book<TH1F>("GenTau21", "GenTau21", 50,0, 1); //irene        
  book<TH1F>("RecoTau21", "RecoTau21", 50,0, 1); //irene        

  book<TH1F>("NHF_RecoTJet", "NHF", 50,0,1); //irene                                   
  book<TH1F>("PhF_RecoTJet", "PhF", 50,0,1); //irene                                   
  book<TH1F>("CHF_RecoTJet", "CHF", 50,0,1); //irene                                   
  book<TH1F>("NHF_GenJet", "NHF", 50,0,1); //irene                                    
  book<TH1F>("PhF_GenJet", "PhF", 50,0,1); //irene                                    
  book<TH1F>("CHF_GenJet", "CHF", 50,0,1); //irene                                       
  book<TH1F>("CHF_Ratio", "RecoCHF/GenCHF", 100,-1,7); //irene
  book<TH1F>("NHF_Ratio", "RecoNHF/GenNHF", 100,-1,7); //irene
  book<TH1F>("PhF_Ratio", "RecoPhF/GenPhF", 100,-1,7); //irene

  book<TH1F>("SoftDropMass_RECO", "RecoSDMass", 100,0,300);
  book<TH1F>("SoftDropMass_Gen", "GenSDMass", 100,0,300);
  book<TH1F>("SoftDropMass_ratio", "Softdrop jet mass response", 20,0,2);
  book<TH1F>("SoftDropMass_ratioDiff", "(RecoSDMass-GenSDMass)/GenSDMass", 100,-2,2);
  book<TH1F>("SoftDropMass_ratio_range", "(RecoSDMass-GenSDMass)/GenSDMass", 100,-2,2);

  book<TH1F>("Pt_RatioDiff", "(RecoJetPt-GenJetPt)/GenJetPt", 100, -1, 7); //irene
  book<TH1F>("Pt_Ratio", "RecoJetPt/GenJetPt", 70, 0, 7); //irene

  //jets
  book<TH1F>("NHF_RecoJet", "NHF", 50,0,1); //irene                                   
  book<TH1F>("PhF_RecoJet", "PhF", 50,0,1); //irene                                   
  book<TH1F>("CHF_RecoJet", "CHF", 50,0,1); //irene                                   

  book<TH1F>("CHF_Ratio_Up", "(RecoCHF-GenCHF)/GenCHF", 24,-1,1); //irene before 100, -1, 7     
  book<TH1F>("CHF_Ratio_RecoGen", "RecoCHF/GenCHF", 35,0,7); //irene before 100, -1, 7     
  book<TH1F>("NHF_Ratio_RecoGen", "RecoNHF/GenNHF", 35,0,7); //irene before 100, -1, 7     
  book<TH1F>("PhF_Ratio_RecoGen", "RecoPhF/GenPhF", 35,0,7); //irene before 100, -1, 7     

  //qcd 
  book<TH1F>("SoftDropMass_ratioDiff_match_qcd", "(RecoSDMass-GenSDMass)/GenSDMass", 100,-2,2);
  book<TH1F>("SoftDropMass_ratio_match_qcd", "Softdrop jet mass response", 100,0,2);
  book<TH1F>("SoftDropMass_ratioDiff_qcd", "(RecoSDMass-GenSDMass)/GenSDMass", 100,-2,2);
  book<TH1F>("SoftDropMass_ratio_qcd", "Softdrop jet mass response", 100,0,2);
  book<TH1F>("SoftDropMass_ratio_qcd_nojec", "RecoSDMass/GenSDMass", 100,0,2);
  book<TH1F>("SoftDropMass_Gen_qcd", "GenSDMass", 100,0,300);
  book<TH1F>("SoftDropMass_Reco_qcd", "RecoSDMass", 100,0,300);

  book<TH1F>("Tau_RatioDiff_qcd", "(RecoTau21-GenTau21)/GenTau21", 100,-1, 7); //irene        
  book<TH1F>("Tau_Ratio_qcd", "RecoTau21/GenTau21", 100,0, 7); //irene        
  book<TH1F>("GenTau21_qcd", "GenTau21", 50,0, 1); //irene        
  book<TH1F>("RecoTau21_qcd", "RecoTau21", 50,0, 1); //irene        
  book<TH1F>("JEC_qcd", "JEC factor", 50,0, 1.4); //irene        
  book<TH1F>("JECreciprocal_qcd", "1/JEC factor", 50,0, 1.4); //irene        
  book<TH1F>("JEC_L1_qcd", "JEC L1 factor", 50,0, 1.4); //irene        

  book<TH1F>("neutralMulti_RecoJet", "neutral Multiplicity", 100,0,200); //irene
  neutralMulti_vs_eta1 =  book<TH2F>("neutralMulti_vs_eta1", "neutral Multiplicity vs eta",10,-2.5,2.5, 100,0,200); //irene        
  book<TH1F>("chargedMulti_RecoJet", "charged Multiplicity", 100,0,200); //irene                                   
  book<TH1F>("cnMulti_RecoJet", "charged+neutral Multiplicity", 100,0,200); //irene                                   
  book<TH1F>("NHF_RecoJet_qcd", "NHF", 50,0,1); //irene                                   
  book<TH1F>("PhF_RecoJet_qcd", "PhF", 50,0,1); //irene                                   
  book<TH1F>("CHF_RecoJet_qcd", "CHF", 50,0,1); //irene                                   
  book<TH1F>("NHF_RecoTJet_qcd", "NHF", 50,0,1); //irene                                   
  book<TH1F>("PhF_RecoTJet_qcd", "PhF", 50,0,1); //irene                                   
  book<TH1F>("CHF_RecoTJet_qcd", "CHF", 50,0,1); //irene                                   
  book<TH1F>("NHF_GenJet_qcd", "NHF", 50,0,1); //irene                                    
  book<TH1F>("PhF_GenJet_qcd", "PhF", 50,0,1); //irene                                    
  book<TH1F>("CHF_GenJet_qcd", "CHF", 50,0,1); //irene                                       

  book<TH1F>("CHF_Ratio_qcd", "RecoCHF/GenCHF", 100,-1,7); //irene
  book<TH1F>("NHF_Ratio_qcd", "RecoNHF/GenNHF", 100,-1,7); //irene
  book<TH1F>("PhF_Ratio_qcd", "RecoPhF/GenPhF", 100,-1,7); //irene
  book<TH1F>("CHF_Ratio_RecoGen_qcd", "RecoCHF/GenCHF", 35,0,7); //irene before 100, -1, 7     
  book<TH1F>("NHF_Ratio_RecoGen_qcd", "RecoNHF/GenNHF", 35,0,7); //irene before 100, -1, 7     
  book<TH1F>("PhF_Ratio_RecoGen_qcd", "RecoPhF/GenPhF", 35,0,7); //irene before 100, -1, 7     
  book<TH1F>("Pt_RatioDiff_qcd", "(RecoJetPt-GenJetPt)/GenJetPt", 100, -1, 7); //irene
  book<TH1F>("Pt_Ratio_qcd", "RecoJetPt/GenJetPt", 70, 0, 7); //irene

  //QstarToQW histos
  //  book<TH1F>("Qstar_Mass_Ratio", "(RecoJetMass-GenJetMass)/GenJetMass", 100, -1, 7); //irene
  
  //book<TH1F>("Qstar_Tau_Ratio", "(RecoTau21-GenTau21)/GenTau21", 100,-1, 7); //irene          
  book<TH1F>("Qstar_Tau21", "#tau_{21}", 50,0., 1.); //irene                                    
  book<TH1F>("Qstar_Tau21_PT", "#tau_{21}", 50,0., 1.); //irene                                 

  //  book<TH1F>("Qstar_CHF_RecoJet", "CHF", 50,0,1); //irene                                   
  //book<TH1F>("Qstar_CHF_Ratio_Up", "(RecoCHF-GenCHF)/GenCHF", 24,-1,1); //irene before 100, -1, 7     
  //book<TH1F>("Qstar_CHF_Ratio", "(RecoCHF-GenCHF)/GenCHF", 100,-1,7); //irene
  //book<TH1F>("Qstar_CHF_Ratio_RecoGen", "RecoCHF/GenCHF", 24,0,2); //irene before 100, -1, 7     


  book<TH1F>("Qstar_SoftDropMass_RECO", "M_{SD} [GeV/c^{2}]", 100,0,300);
  book<TH1F>("Qstar_SoftDropMass_RECO_PT", "M_{SD} [GeV/c^{2}]", 100,0,300);
  book<TH1F>("Qstar_PT", "p_{T} [GeV/c]", 100,0,3500);
  book<TH1F>("Qstar_PT_cut", "p_{T} [GeV/c]", 100,0,3500);
  //book<TH1F>("Qstar_SoftDropMass_ratio", "(RecoSDMass-GenSDMass)/GenSDMass", 100,-2,2);
  //book<TH1F>("Qstar_SoftDropMass_ratio_range", "(RecoSDMass-GenSDMass)/GenSDMass", 100,-2,2);
  //book<TH1F>("Qstar_PrunedMass_ratio", "(RecoSDMass-GenSDMass)/GenSDMass", 100,-2,2);

 // primary vertices
  book<TH1F>("N_pv", "N^{PV}", 250, 0, 250);

  //event weight
  book<TH1F>("weight", "weight", 100, 0, 0.01);

  h_particles = ctx.get_handle<std::vector <GenParticle> >("genparticles");

}


void UpgradeStudiesGtoWWHists::fill(const Event & event){
  // fill the histograms. Please note the comments in the header file:
  // 'hist' is used here a lot for simplicity, but it will be rather
  // slow when you have many histograms; therefore, better
  // use histogram pointers as members as in 'UHH2/common/include/ElectronHists.h'
  
  // Don't forget to always use the weight when filling.
  double weight = event.weight;
  hist("weight")->Fill(weight);

  // ### top jets and gen top jets hist ###
  if(event.gentopjets->size() < 2) return;
  if(event.topjets->size() < 2) return;

  auto RecoJetMass = event.topjets->at(0).v4().M();
  auto GenJetMass  = event.gentopjets->at(0).v4().M();
  hist("Mass_Ratio")->Fill((RecoJetMass-GenJetMass)/GenJetMass, weight);

  auto jec = event.topjets->at(0).JEC_factor_raw();
  auto jec_L1 = event.topjets->at(0).JEC_L1factor_raw();
  hist("JEC")->Fill(jec, weight);
  hist("JECreciprocal")->Fill(1./jec, weight);
  hist("JEC_L1")->Fill(jec_L1, weight);
  
  auto RecoTau21_1 = event.topjets->at(0).tau2()/event.topjets->at(0).tau1();
  auto GenTau1_1   = event.gentopjets->at(0).tau1();
  auto GenTau2_1   = event.gentopjets->at(0).tau2();
  auto GenTau21_1  = GenTau2_1/GenTau1_1;
  hist("Tau_RatioDiff")->Fill((RecoTau21_1-GenTau21_1)/GenTau21_1, weight);
  hist("Tau_Ratio")->Fill(RecoTau21_1/GenTau21_1, weight);
  hist("GenTau21")->Fill(GenTau21_1, weight);
  hist("RecoTau21")->Fill(RecoTau21_1, weight);

  auto RecoCHF_1 = event.topjets->at(0).chargedHadronEnergyFraction();
  auto RecoNHF_1 = event.topjets->at(0).neutralHadronEnergyFraction();
  auto RecoPhF_1 = event.topjets->at(0).photonEnergyFraction();
  hist("CHF_RecoTJet")->Fill(RecoCHF_1,weight);
  hist("NHF_RecoTJet")->Fill(RecoNHF_1,weight);
  hist("PhF_RecoTJet")->Fill(RecoPhF_1,weight);

  auto GenCHF_1  = event.gentopjets->at(0).chf();
  auto GenNHF_1  = event.gentopjets->at(0).nhf();
  auto GenPhF_1  = event.gentopjets->at(0).nef();
  hist("CHF_GenJet")->Fill(GenCHF_1,weight);
  hist("NHF_GenJet")->Fill(GenNHF_1,weight);
  hist("PhF_GenJet")->Fill(GenPhF_1,weight);

  hist("CHF_Ratio")->Fill(RecoCHF_1/GenCHF_1, weight);
  hist("NHF_Ratio")->Fill(RecoNHF_1/GenNHF_1, weight);
  hist("PhF_Ratio")->Fill(RecoPhF_1/GenPhF_1, weight);


  //in the new official samples/ UHH932 ntuplewriter  I had to use a jetcollection to access these variables of AK8 jets 
  if(event.jets->size()<1) return;
  auto RecoJCHF_1 = event.jets->at(0).chargedHadronEnergyFraction();
  hist("CHF_RecoJet")->Fill(RecoJCHF_1,weight);
  auto RecoJNHF_1 = event.jets->at(0).neutralHadronEnergyFraction();
  hist("NHF_RecoJet")->Fill(RecoJNHF_1,weight);
  auto RecoJPhF_1 = event.jets->at(0).photonEnergyFraction();
  hist("PhF_RecoJet")->Fill(RecoJPhF_1,weight);

  hist("CHF_Ratio_Up")->Fill((RecoJCHF_1-GenCHF_1)/GenCHF_1, weight);
  hist("CHF_Ratio_RecoGen")->Fill(RecoJCHF_1/GenCHF_1, weight);
  hist("NHF_Ratio_RecoGen")->Fill(RecoJNHF_1/GenNHF_1, weight);
  hist("PhF_Ratio_RecoGen")->Fill(RecoJPhF_1/GenPhF_1, weight);

  //SoftDrop top jets
  vector<TopJet> Tjets = *event.topjets;
  if(Tjets.size()<1) return;
  const auto & jet = Tjets[0];
  LorentzVector subjet_sum;
  for (const auto s : jet.subjets()) {
    subjet_sum += s.v4();
  }
  vector<GenTopJet> GTjets = *event.gentopjets;
  if(GTjets.size()<1) return;
  const auto & gjet = GTjets[0];
  LorentzVector gsubjet_sum;
  for (const auto sg : gjet.subjets()) {
    gsubjet_sum += sg.v4();
  }


  auto RecoJetSDMass1 = subjet_sum.M();
  auto RecoJetSDMass1corrected = subjet_sum.M()*jec_L1;
  auto GenJetSDMass1 = gsubjet_sum.M();

  hist("SoftDropMass_ratio")->Fill(RecoJetSDMass1corrected/GenJetSDMass1, weight);
  hist("SoftDropMass_ratioDiff")->Fill((RecoJetSDMass1-GenJetSDMass1)/GenJetSDMass1, weight);
  if((RecoJetSDMass1>40 && RecoJetSDMass1<120)&&(GenJetSDMass1>40&& GenJetSDMass1<120))
    hist("SoftDropMass_ratio_range")->Fill((RecoJetSDMass1-GenJetSDMass1)/GenJetSDMass1, weight);
  hist("SoftDropMass_RECO")->Fill(RecoJetSDMass1corrected, weight);
  hist("SoftDropMass_Gen")->Fill(GenJetSDMass1, weight);

  auto RecoPt_1 =  event.topjets->at(0).pt();
  auto GenPt_1 =  event.gentopjets->at(0).pt();
  hist("Pt_Ratio")->Fill(RecoPt_1/GenPt_1, weight);
  hist("Pt_RatioDiff")->Fill((RecoPt_1-GenPt_1)/GenPt_1, weight);

  //qcd hists

  LorentzVector subjet_sum_qcd;
  LorentzVector gsubjet_sum_qcd;
  for(unsigned int i=0; i<event.gentopjets->size(); i++)
    {
      const auto & gj = GTjets[i];
      for(unsigned int j=0; j<event.topjets->size(); j++)
	{

	  const TopJet & tj = Tjets[j];

	  if(deltaR(tj,gj)<0.4)
	    {	    
	      for (const auto s : tj.subjets()) {
		subjet_sum_qcd += s.v4();
	      }
	      for (const auto s : gj.subjets()) {
		gsubjet_sum_qcd += s.v4();
	      }
	      auto RecoJetSDMass1_qcd = subjet_sum_qcd.M();
	      auto GenJetSDMass1_qcd = gsubjet_sum_qcd.M();
	      auto RecoJetSDMass1corrected_qcd = subjet_sum_qcd.M()*jec_L1;
	      hist("SoftDropMass_ratioDiff_match_qcd")->Fill((RecoJetSDMass1corrected_qcd-GenJetSDMass1_qcd)/GenJetSDMass1_qcd, weight);
	      hist("SoftDropMass_ratio_match_qcd")->Fill(RecoJetSDMass1corrected_qcd/GenJetSDMass1_qcd, weight);
	    }

	}
    }

      const auto & gj_1 = GTjets[0];
      const TopJet & tj_1 = Tjets[0];

	  if(deltaR(tj_1,gj_1)<0.4)
	    {	    
	      for (const auto s : tj_1.subjets()) {
		subjet_sum_qcd += s.v4();
	      }
	      for (const auto s : gj_1.subjets()) {
		gsubjet_sum_qcd += s.v4();
	      }
	      auto jec_qcd = event.topjets->at(0).JEC_factor_raw();
	      auto jec_L1_qcd = event.topjets->at(0).JEC_L1factor_raw();
	      hist("JEC_qcd")->Fill(jec_qcd, weight);
	      hist("JECreciprocal")->Fill(1./jec_qcd, weight);
	      hist("JEC_L1_qcd")->Fill(jec_L1_qcd, weight);


	      auto RecoJetSDMass1_qcd = subjet_sum_qcd.M();
	      auto GenJetSDMass1_qcd = gsubjet_sum_qcd.M();
	      auto RecoJetSDMass1corrected_qcd = subjet_sum_qcd.M()*jec_L1;
	      hist("SoftDropMass_ratioDiff_qcd")->Fill((RecoJetSDMass1corrected_qcd-GenJetSDMass1_qcd)/GenJetSDMass1_qcd, weight);
	      hist("SoftDropMass_ratio_qcd")->Fill(RecoJetSDMass1corrected_qcd/GenJetSDMass1_qcd, weight);
	      hist("SoftDropMass_ratio_qcd_nojec")->Fill(RecoJetSDMass1_qcd/GenJetSDMass1_qcd, weight);
	      hist("SoftDropMass_Reco_qcd")->Fill(RecoJetSDMass1corrected_qcd, weight);
	      hist("SoftDropMass_Gen_qcd")->Fill(GenJetSDMass1_qcd, weight);

	      
	      //cout<< "jec" << endl;
	      hist("Pt_Ratio_qcd")->Fill(RecoPt_1/GenPt_1, weight);
	      hist("Pt_RatioDiff_qcd")->Fill((RecoPt_1-GenPt_1)/GenPt_1, weight);
  
	      
	      auto RecoTau21_1_qcd = event.topjets->at(0).tau2()/event.topjets->at(0).tau1();
	      auto GenTau1_1_qcd   = event.gentopjets->at(0).tau1();
	      auto GenTau2_1_qcd   = event.gentopjets->at(0).tau2();
	      auto GenTau21_1_qcd  = GenTau2_1_qcd/GenTau1_1_qcd;
	      hist("Tau_RatioDiff_qcd")->Fill((RecoTau21_1_qcd-GenTau21_1_qcd)/GenTau21_1_qcd, weight);
	      hist("Tau_Ratio_qcd")->Fill(RecoTau21_1_qcd/GenTau21_1_qcd, weight);
	      hist("GenTau21_qcd")->Fill(GenTau21_1_qcd, weight);
	      hist("RecoTau21_qcd")->Fill(RecoTau21_1_qcd, weight);


	    }

	  if(event.jets->size()<1) return;
	  std::vector<Jet> Jets = *event.jets;
	  const Jet & j_1 = Jets[0];

	  if(deltaR(j_1,gj_1)<0.4)
	    {	    
     
	      //cout<< "tau" << endl;
	      auto nm = event.jets->at(0).neutralMultiplicity();
	      hist("neutralMulti_RecoJet")->Fill(nm,weight);
	      auto cm = event.jets->at(0).chargedMultiplicity();
	      hist("chargedMulti_RecoJet")->Fill(cm,weight);
	      //	      auto sum = nm+cm;
	      //	      cout << "nm: " << nm << " cm: " << cm << " sum: " << sum <<endl;
	      hist("cnMulti_RecoJet")->Fill(cm+nm,weight);
	      neutralMulti_vs_eta1->Fill(event.jets->at(0).eta(),event.jets->at(0).neutralMultiplicity(),weight);
	      auto RecoJCHF_1_qcd = event.jets->at(0).chargedHadronEnergyFraction();
	      hist("CHF_RecoJet_qcd")->Fill(RecoJCHF_1_qcd,weight);
	      auto RecoJNHF_1_qcd = event.jets->at(0).neutralHadronEnergyFraction();
	      hist("NHF_RecoJet_qcd")->Fill(RecoJNHF_1_qcd,weight);
	      auto RecoJPhF_1_qcd = event.jets->at(0).photonEnergyFraction();
	      hist("PhF_RecoJet_qcd")->Fill(RecoJPhF_1_qcd,weight);
	      auto RecoCHF_1_qcd = event.topjets->at(0).chargedHadronEnergyFraction();
	      auto RecoNHF_1_qcd = event.topjets->at(0).neutralHadronEnergyFraction();
	      auto RecoPhF_1_qcd = event.topjets->at(0).photonEnergyFraction();
	      
	      hist("CHF_RecoTJet_qcd")->Fill(RecoCHF_1_qcd,weight);
	      hist("NHF_RecoTJet_qcd")->Fill(RecoNHF_1_qcd,weight);
	      hist("PhF_RecoTJet_qcd")->Fill(RecoPhF_1_qcd,weight);
	      
	      
	      auto GenCHF_1_qcd  = event.gentopjets->at(0).chf();
	      auto GenNHF_1_qcd  = event.gentopjets->at(0).nhf();
	      auto GenPhF_1_qcd  = event.gentopjets->at(0).nef();

  // //cout << "RecoJCHF_1: " << RecoJCHF_1 << "   GenCHF_1: " << GenCHF_1 <<  " ratio " << RecoJCHF_1/GenCHF_1 << endl;
  // //cout << "RecoJNHF_1: " << RecoJNHF_1 << "   GenNHF_1: " << GenNHF_1 <<  " ratio " << RecoJNHF_1/GenNHF_1 << endl;
  // //cout << "RecoJPhF_1: " << RecoJPhF_1 << "   GenPhF_1: " << GenPhF_1 <<  " ratio " << RecoJPhF_1/GenPhF_1 << endl;


	      
	      hist("CHF_GenJet_qcd")->Fill(GenCHF_1_qcd,weight);
	      hist("NHF_GenJet_qcd")->Fill(GenNHF_1_qcd,weight);
	      hist("PhF_GenJet_qcd")->Fill(GenPhF_1_qcd,weight);
	      hist("CHF_Ratio_qcd")->Fill(RecoCHF_1_qcd/GenCHF_1_qcd, weight);
	      hist("NHF_Ratio_qcd")->Fill(RecoNHF_1_qcd/GenNHF_1_qcd, weight);
	      hist("PhF_Ratio_qcd")->Fill(RecoPhF_1_qcd/GenPhF_1_qcd, weight);
	      hist("CHF_Ratio_RecoGen_qcd")->Fill(RecoJCHF_1_qcd/GenCHF_1_qcd, weight);
	      hist("NHF_Ratio_RecoGen_qcd")->Fill(RecoJNHF_1_qcd/GenNHF_1_qcd, weight);
	      hist("PhF_Ratio_RecoGen_qcd")->Fill(RecoJPhF_1_qcd/GenPhF_1_qcd, weight);
	    }




  //cout<< "qcd" << endl;




// irene: histos for Qstar 
  assert(event.genparticles);

  //Generator-Teilchen                                                                                                                                                                                        
  if(!event.is_valid(h_particles)){
    return;
  }

  const std::vector<GenParticle> &  genp = event.get(h_particles);

  //cout<< "genP" << endl;

  //  int index;
  const auto & tjet_0 = Tjets[0];
  const auto & tjet_1 = Tjets[1];

  //      for(unsigned int j=0; j<event.topjets->size(); j++)
  //     	{
  //		     const auto & tjet = Tjets[j];

      for(unsigned int i=0; i<genp.size(); i++)
       	{
      	  const GenParticle & gp = genp[i];
	  if(abs(gp.pdgId())==24)// && deltaR(tjet,gp)<0.4)
	    {

		     //	      //cout << " W from Qstar" <<endl;
		     // 	     RecoJetMass = ak8.v4().M();
		     // GenJetMass  = event.gentopjets->at(0).v4().M();
		     // hist("Mass_Ratio")->Fill((RecoJetMass-GenJetMass)/GenJetMass, weight);
	      auto pt = tjet_0.pt();	      
	      auto subjets = tjet_0.subjets();
	      if(deltaR(tjet_0,gp)<0.4)
		{
		  RecoTau21_1 = tjet_0.tau2()/tjet_0.tau1();
		  pt = tjet_0.pt();
		  subjets = tjet_0.subjets();
		}
	      if(deltaR(tjet_1,gp)<0.4)
		{
		  RecoTau21_1 = tjet_1.tau2()/tjet_1.tau1();
		  pt = tjet_1.pt();
		  subjets = tjet_1.subjets();

		}
	      //	      RecoTau21_1 = tjet.tau2()/tjet.tau1();
		     // auto GenTau1_1   = event.gentopjets->at(0).tau1();
		     // auto GenTau2_1   = event.gentopjets->at(0).tau2();
		     // auto GenTau21_1  = GenTau2_1/GenTau1_1;
		     hist("Qstar_PT")->Fill(pt, weight);
		     hist("Qstar_Tau21")->Fill(RecoTau21_1, weight);
		     // auto RecoJCHF_1 = event.jets->at(0).chargedHadronEnergyFraction();
		     // hist("CHF_RecoJet")->Fill(RecoJCHF_1,weight);
		     // auto RecoCHF_1 = event.topjets->at(0).chargedHadronEnergyFraction();
		     // auto GenCHF_1  = event.gentopjets->at(0).chf();
		     // hist("CHF_Ratio")->Fill((RecoCHF_1-GenCHF_1)/GenCHF_1, weight);
		     // hist("CHF_Ratio_Up")->Fill((RecoJCHF_1-GenCHF_1)/GenCHF_1, weight);
		     // hist("CHF_Ratio_RecoGen")->Fill(RecoJCHF_1/GenCHF_1, weight);
		     
		     //SoftDrop 
		     // // RecoJetSDMass1 = event.topjets->at(0).softdropmass();
		     // vector<TopJet> Tjets = *event.topjets;
		     // if(Tjets.size()<1) return;
		     // const auto & jet = Tjets[j];
		     LorentzVector subjet_sum;
		     for (const auto s : subjets) {
		      	subjet_sum += s.v4();
		      }
		     // vector<GenTopJet> GTjets = *event.gentopjets;
		     // if(GTjets.size()<1) return;
		     // const auto & gjet = GTjets[0];
		     // LorentzVector gsubjet_sum;
		     // for (const auto sg : gjet.subjets()) {
		     // 	gsubjet_sum += sg.v4();
		     // }
	      
	      
	      
		     RecoJetSDMass1 = subjet_sum.M();
		     // //auto GenJetSDMass1 = event.gentopjets->at(0).v4().M();
		     // auto GenJetSDMass1 = gsubjet_sum.M();
		     hist("Qstar_SoftDropMass_RECO")->Fill(RecoJetSDMass1*jec_L1, weight);
		     // if((RecoJetSDMass1>40 && RecoJetSDMass1<120)&&(GenJetSDMass1>40&& GenJetSDMass1<120))
		     // 	hist("SoftDropMass_ratio_range")->Fill((RecoJetSDMass1-GenJetSDMass1)/GenJetSDMass1, weight);
		     // hist("SoftDropMass_RECO")->Fill(RecoJetSDMass1, weight);
	      
		     if(pt>2500 && pt<3500)
		       {
			 hist("Qstar_Tau21_PT")->Fill(RecoTau21_1, weight);
			 hist("Qstar_PT_cut")->Fill(pt, weight);
			 hist("Qstar_SoftDropMass_RECO_PT")->Fill(RecoJetSDMass1*jec_L1, weight);
		       }
	      
		     // //Puppi 
		     // auto RecoJetPuppiMass1 = event.topjets->at(0).prunedmass();
		     // hist("PrunedMass_ratio")->Fill((RecoJetPuppiMass1-GenJetSDMass1)/GenJetSDMass1, weight);
	      
	    }
       }
      //    }	      
  
  //cout<< "Qstar" << endl;


  int Npvs = event.pvs->size();
  hist("N_pv")->Fill(Npvs, weight);
}

UpgradeStudiesGtoWWHists::~UpgradeStudiesGtoWWHists(){}
