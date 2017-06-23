#include "UHH2/UpgradeStudiesGtoWW/include/UpgradeGenTopJetHists.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/core/include/GenTopJet.h"


#include "TH1F.h"
#include <iostream>

using namespace uhh2;


UpgradeGenTopJetHists::UpgradeGenTopJetHists(Context & ctx, 
					     const std::string & dirname)  : Hists(ctx, dirname){
  
  //mass
  book<TH1F>("Mass_1","Mass [GeV/c^{2}]",100,0,300);

  //PT    
  book<TH1F>("PT_1","P_{T} [GeV/c]",100,0,1500);

  
  // Phi 
  book<TH1F>("Phi_1"," Phi ",100,-M_PI,M_PI);
  
  //Eta 
  book<TH1F>("Eta_1","Eta",100,-4,4);

  //substructure
  book<TH1F>("SoftDropMass_Gen", "GenJetSoftDropMass [GeV/c^2]", 100,0,300);
  book<TH1F>("CHF_1","CHF",50,0,1);
  book<TH1F>("TAU1_1","#tau_{1}",50,0,1); 
  book<TH1F>("TAU2_1","#tau_{2}",50,0,1);
  book<TH1F>("Tau21_Gen1", "#tau_{2}/#tau_{1}", 50,0,1); 

  h_gentopjets = ctx.get_handle<std::vector <GenTopJet> >("gentopjets");

 }


void UpgradeGenTopJetHists::fill(const uhh2::Event & event){
  assert(event.gentopjets);

 //Generator-Teilchen
  if(!event.is_valid(h_gentopjets)){
    return;
  }
  

    //Weightning
  double weight = event.weight;
  
  const std::vector<GenTopJet> &  jet = event.get(h_gentopjets);
       

  if(jet.size() < 1) return;

      float Mass = jet.at(0).v4().M();
      hist("Mass_1")->Fill(Mass, weight);
      float PT = jet.at(0).v4().pt();
      hist("PT_1")->Fill(PT, weight);
      float Phi = jet.at(0).v4().phi();
      hist("Phi_1")->Fill(Phi, weight);
      float Eta = jet.at(0).v4().eta();
      hist("Eta_1")->Fill(Eta, weight);





      std::vector<GenTopJet> GTjets = *event.gentopjets;
      if(GTjets.size()<1) return;
      const auto & gjet = GTjets[0];
      LorentzVector gsubjet_sum;
      for (const auto sg : gjet.subjets()) {
	gsubjet_sum += sg.v4();
      }
      
      //auto GenJetSDMass1 = event.gentopjets->at(0).v4().M();                                                                                                                                                   
      auto GenJetSDMass1 = gsubjet_sum.M();
   
      //      auto GenJetSDMass1 = event.gentopjets->at(0).v4().M();
      hist("SoftDropMass_Gen")->Fill(GenJetSDMass1, weight);


       
      float chf = jet.at(0).chf();
      hist("CHF_1")->Fill(chf, weight);
      float tau1 = jet.at(0).tau1();
      hist("TAU1_1")->Fill(tau1, weight);
      float tau2 = jet.at(0).tau2();
      hist("TAU2_1")->Fill(tau2, weight);
      float tau21 = tau2/tau1;
      hist("Tau21_Gen1")->Fill(tau21, weight);
}
