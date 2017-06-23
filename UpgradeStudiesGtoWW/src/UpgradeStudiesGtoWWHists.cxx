#include "UHH2/UpgradeStudiesGtoWW/include/UpgradeStudiesGtoWWHists.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/common/include/JetHists.h"
#include "UHH2/core/include/TopJet.h"
#include "UHH2/core/include/LorentzVector.h"
#include "TH1F.h"
#include <iostream>

using namespace std;
using namespace uhh2;
using namespace uhh2examples;

UpgradeStudiesGtoWWHists::UpgradeStudiesGtoWWHists(Context & ctx, const string & dirname): Hists(ctx, dirname){
  //******************* book all histograms here *****************************
  
  //ratios (Reco -Gen)/Gen
  book<TH1F>("Mass_Ratio", "(RecoJetMass-GenJetMass)/GenJetMass", 100, -1, 7); //irene
  
  book<TH1F>("Tau_Ratio", "(RecoTau21-GenTau21)/GenTau21", 100,-1, 7); //irene                                                                                                                

  book<TH1F>("CHF_RecoJet", "CHF", 50,0,1); //irene                                                                                                                                     
  book<TH1F>("CHF_Ratio_Up", "(RecoCHF-GenCHF)/GenCHF", 24,-1,1); //irene before 100, -1, 7     
  book<TH1F>("CHF_Ratio", "(RecoCHF-GenCHF)/GenCHF", 100,-1,7); //irene
  book<TH1F>("CHF_Ratio_RecoGen", "RecoCHF/GenCHF", 24,0,2); //irene before 100, -1, 7     


  book<TH1F>("SoftDropMass_RECO", "RecoSDMass", 100,0,300);
  book<TH1F>("SoftDropMass_ratio", "(RecoSDMass-GenSDMass)/GenSDMass", 100,-2,2);
  book<TH1F>("SoftDropMass_ratio_range", "(RecoSDMass-GenSDMass)/GenSDMass", 100,-2,2);
  book<TH1F>("PrunedMass_ratio", "(RecoSDMass-GenSDMass)/GenSDMass", 100,-2,2);

  // jets
  book<TH1F>("N_jets", "N_{jets}", 20, 0, 20);  
  book<TH1F>("eta_jet1", "#eta^{jet 1}", 40, -2.5, 2.5);
  book<TH1F>("eta_jet2", "#eta^{jet 2}", 40, -2.5, 2.5);
  book<TH1F>("eta_jet3", "#eta^{jet 3}", 40, -2.5, 2.5);
  book<TH1F>("eta_jet4", "#eta^{jet 4}", 40, -2.5, 2.5);

  // leptons
  book<TH1F>("N_mu", "N^{#mu}", 10, 0, 10);
  book<TH1F>("pt_mu", "p_{T}^{#mu} [GeV/c]", 40, 0, 200);
  book<TH1F>("eta_mu", "#eta^{#mu}", 40, -2.1, 2.1);
  book<TH1F>("reliso_mu", "#mu rel. Iso", 40, 0, 0.5);

  // primary vertices
  book<TH1F>("N_pv", "N^{PV}", 250, 0, 250);

}


void UpgradeStudiesGtoWWHists::fill(const Event & event){
  // fill the histograms. Please note the comments in the header file:
  // 'hist' is used here a lot for simplicity, but it will be rather
  // slow when you have many histograms; therefore, better
  // use histogram pointers as members as in 'UHH2/common/include/ElectronHists.h'
  
  // Don't forget to always use the weight when filling.
  double weight = event.weight;
  
  std::vector<Jet>* jets = event.jets;


  int Njets = jets->size();
  if(Njets<1) return;
  hist("N_jets")->Fill(Njets, weight);
  
  // begin irene for ratios histograms

  if(event.gentopjets->size() < 1) return;
  if(event.topjets->size() < 1) return;

  
  auto RecoJetMass = event.topjets->at(0).v4().M();
  auto GenJetMass  = event.gentopjets->at(0).v4().M();
  hist("Mass_Ratio")->Fill((RecoJetMass-GenJetMass)/GenJetMass, weight);
  
  
  auto RecoTau21_1 = event.topjets->at(0).tau2()/event.topjets->at(0).tau1();
  auto GenTau1_1   = event.gentopjets->at(0).tau1();
  auto GenTau2_1   = event.gentopjets->at(0).tau2();
  auto GenTau21_1  = GenTau2_1/GenTau1_1;
  hist("Tau_Ratio")->Fill((RecoTau21_1-GenTau21_1)/GenTau21_1, weight);
 
  auto RecoJCHF_1 = event.jets->at(0).chargedHadronEnergyFraction();
  hist("CHF_RecoJet")->Fill(RecoJCHF_1,weight);
  auto RecoCHF_1 = event.topjets->at(0).chargedHadronEnergyFraction();
  auto GenCHF_1  = event.gentopjets->at(0).chf();
  hist("CHF_Ratio")->Fill((RecoCHF_1-GenCHF_1)/GenCHF_1, weight);
  hist("CHF_Ratio_Up")->Fill((RecoJCHF_1-GenCHF_1)/GenCHF_1, weight);
  hist("CHF_Ratio_RecoGen")->Fill(RecoJCHF_1/GenCHF_1, weight);

  //SoftDrop 
  //auto RecoJetSDMass1 = event.topjets->at(0).softdropmass();
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
  //auto GenJetSDMass1 = event.gentopjets->at(0).v4().M();
  auto GenJetSDMass1 = gsubjet_sum.M();
  hist("SoftDropMass_ratio")->Fill((RecoJetSDMass1-GenJetSDMass1)/GenJetSDMass1, weight);
  if((RecoJetSDMass1>40 && RecoJetSDMass1<120)&&(GenJetSDMass1>40&& GenJetSDMass1<120))
  hist("SoftDropMass_ratio_range")->Fill((RecoJetSDMass1-GenJetSDMass1)/GenJetSDMass1, weight);
  hist("SoftDropMass_RECO")->Fill(RecoJetSDMass1, weight);

  //Puppi 
  auto RecoJetPuppiMass1 = event.topjets->at(0).prunedmass();
  hist("PrunedMass_ratio")->Fill((RecoJetPuppiMass1-GenJetSDMass1)/GenJetSDMass1, weight);
 
//end irene for ratios histograms
 
  if(Njets>=1){
    hist("eta_jet1")->Fill(jets->at(0).eta(), weight);
  }
  if(Njets>=2){
    hist("eta_jet2")->Fill(jets->at(1).eta(), weight);
  }
  if(Njets>=3){
    hist("eta_jet3")->Fill(jets->at(2).eta(), weight);
  }
  if(Njets>=4){
    hist("eta_jet4")->Fill(jets->at(3).eta(), weight);
  }

  int Nmuons = event.muons->size();
  hist("N_mu")->Fill(Nmuons, weight);
  for (const Muon & thismu : *event.muons){
      hist("pt_mu")->Fill(thismu.pt(), weight);
      hist("eta_mu")->Fill(thismu.eta(), weight);
      hist("reliso_mu")->Fill(thismu.relIso(), weight);
  }
  
  int Npvs = event.pvs->size();
  hist("N_pv")->Fill(Npvs, weight);
}

UpgradeStudiesGtoWWHists::~UpgradeStudiesGtoWWHists(){}
