#pragma once

#include "UHH2/core/include/Hists.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/core/include/LorentzVector.h"
//#include "UHH2/common/include/JetHists.h"
#include <vector>
#include <string>

#include "TH1F.h"

class GenJetsHists : public uhh2::Hists {
 public:
  struct ParticleHist{
      TH1F* pt, *eta, *phi, *mass; 
  };
  GenJetsHists(uhh2::Context & ctx, const std::string & dirname,  const unsigned int NumberOfPlottedJets=4, const std::string & collection_="");
  GenJetsHists::ParticleHist book_ParticleHist(const std::string & axisSuffix, const std::string & histSuffix, double minPt, double maxPt);
  void fill_ParticleHist(const Particle & jet, ParticleHist & particle_hist, double  weight);
  virtual void fill(const uhh2::Event & ev) override;
 private:
  std::string collection;
  std::vector<ParticleHist> single_ParticleHists;
  ParticleHist alljets;
  TH1F* number;
  uhh2::Event::Handle<std::vector<Particle> > h_jets;
};

//irene
/*class GenJetHistsBase: public uhh2::Hists {
 protected:
  struct jetHist{
    TH1F* pt, *eta, *phi, *mass, *CHF, *tau21;//*mvahiggsdiscr, *prunedmass, *subjet_sum_mass, *CHF, *tau21; //irene added CHF and tau21                                                                              
  };

  GenJetHistsBase(uhh2::Context & ctx, const std::string & dirname);

  jetHist book_jetHist(const std::string & axisSuffix, const std::string & histSuffix, double minPt, double maxPt);
  void fill_jetHist(const GenTopJet & jet, jetHist & jet_hist, double  weight);
  template<typename T>
    bool passes_id(const T & object, const uhh2::Event & event, const boost::optional<std::function<bool (const T &, const uhh2::Event & )>> & object_id);
};
*/



/*
//class GenTopJetHists: public GenJetHistsBase{
class GenTopJetHists : public GenJetsHists {
 public:
  GenTopJetHists(uhh2::Context & ctx,
              const std::string & dirname,
              const unsigned int NumberOfPlottedJets=4,
              const std::string & collection = "");

  virtual void fill(const uhh2::Event & ev) override;
                                                                                                                                                               
  //UserJet defines the i-th Jet to be plotted. The other variables are needed for plotting and to have different histogram names/axis. For each TopJet all its SubJets are also plotted.                   
  void add_iTopJetHists(unsigned int UserJet, double minPt=0, double maxPt=800, double minPt_sub=0, double maxPt_sub=500, const std::string & axisSuffix="userjet", const std::string & histSuffix="userjet"
			);
 protected:
  GenJetsHists::ParticleHist book_topJetHist(const std::string & axisSuffix, const std::string & histSuffix, double minPt, double maxPt);
  void fill_topJetHist(const GenTopJet & jet, GenJetsHists::ParticleHist & jet_hist, double  weight);

  struct subjetHist {
    TH1F* number, *sum4Vec, *pt, *eta, *phi, *mass;//,  *subjet_sum_mass;
  };
  subjetHist book_subjetHist(const std::string & axisSuffix, const std::string & histSuffix, double minPt, double maxPt);
  void fill_subjetHist(const GenTopJet & topjet, subjetHist & subjet_hist, double weight);
  std::string collection;
  std::vector<unsigned int> m_usertopjet;
  std::vector<ParticleHist> usertopjets;
  std::vector<subjetHist> usersubjets;
  TH1F *number;
  TH1F *deltaRmin_1, *deltaRmin_2, *tau32,*tau21,*deltaR_ak4jet,*invmass_topjetak4jet,*HTT_mass,*fRec,*deltaR_lepton;

  ParticleHist alljets;
  subjetHist allsubjets;
  std::vector<ParticleHist> single_jetHists;
  std::vector<subjetHist> subjets;
  uhh2::Event::Handle<std::vector<GenTopJet> > h_gentopjets;

};



*/
