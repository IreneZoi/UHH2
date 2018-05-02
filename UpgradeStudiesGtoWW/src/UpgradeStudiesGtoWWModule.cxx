#include <iostream>
#include <memory>

#include "UHH2/core/include/AnalysisModule.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/common/include/CommonModules.h"
#include "UHH2/common/include/CleaningModules.h"
#include "UHH2/common/include/ElectronHists.h"
#include <UHH2/common/include/JetIds.h>
#include "UHH2/common/include/JetHists.h"
#include "UHH2/common/include/GenJetsHists.h"
#include <UHH2/common/include/JetCorrections.h>
#include "UHH2/common/include/NSelections.h"
#include "UHH2/UpgradeStudiesGtoWW/include/UpgradeStudiesGtoWWSelections.h"
#include "UHH2/UpgradeStudiesGtoWW/include/UpgradeStudiesGtoWWHists.h"
#include "UHH2/UpgradeStudiesGtoWW/include/UpgradeGenTopJetHists.h"
using namespace std;
using namespace uhh2;

namespace uhh2examples {

/** \brief Basic analysis example of an AnalysisModule (formerly 'cycle') in UHH2
 * 
 * This is the central class which calls other AnalysisModules, Hists or Selection classes.
 * This AnalysisModule, in turn, is called (via AnalysisModuleRunner) by SFrame.
 */
class UpgradeStudiesGtoWWModule: public AnalysisModule {
public:
    
    explicit UpgradeStudiesGtoWWModule(Context & ctx);
    virtual bool process(Event & event) override;

private:
  std::string phase_;    
  std::unique_ptr<CommonModules> common;
  
  std::unique_ptr<JetCleaner> jetcleaner;
  std::unique_ptr<TopJetCleaner> topjetcleaner;
   
  std::unique_ptr<JetCorrector> jet_corrector;
  std::unique_ptr<TopJetCorrector> topjet_corrector;

    // declare the Selections to use. Use unique_ptr to ensure automatic call of delete in the destructor,
    // to avoid memory leaks.
  std::unique_ptr<Selection> SDmass_sel, ptLow_sel, ptMedium_sel, ptHigh_sel, barrel_sel, endcap_sel, ptMin_qcd, ptMed_qcd, ptMax_qcd;
    
    // store the Hists collection as member variables. Again, use unique_ptr to avoid memory leaks.
  std::unique_ptr<Hists> h_Qstar, h_Qstar_barrel, h_Qstar_endcap;
  std::unique_ptr<Hists> h_qcd_lowPt, h_qcd_lowPt_barrel, h_qcd_lowPt_endcap, h_qcd_mediumPt, h_qcd_mediumPt_barrel, h_qcd_mediumPt_endcap, h_qcd_highPt, h_qcd_highPt_barrel, h_qcd_highPt_endcap;
  std::unique_ptr<Hists> h_qcd_minPt, h_qcd_minPt_barrel, h_qcd_minPt_endcap, h_qcd_medPt, h_qcd_medPt_barrel, h_qcd_medPt_endcap, h_qcd_maxPt, h_qcd_maxPt_barrel, h_qcd_maxPt_endcap;
  std::unique_ptr<Hists> h_start_ak8; //irene for w mass
  std::unique_ptr<Hists> h_input_slimmedGenJet; //irene for w mass                                                                                                                                  
  std::unique_ptr<Hists> h_input_slimmedJet; //irene for w mass
  std::unique_ptr<Hists> h_ptLow_slimmedJetAK8_SoftDrop; //irene for w mass                                                                                                                          
  std::unique_ptr<Hists> h_ptMedium_slimmedJetAK8_SoftDrop; //irene for w mass                                                                                                                          
  std::unique_ptr<Hists> h_ptHigh_slimmedJetAK8_SoftDrop; //irene for w mass                                                                                                                          

  std::unique_ptr<Hists> h_ptLow_Barrel_slimmedJetAK8_SoftDrop; //irene for w mass                                                                                                                          
  std::unique_ptr<Hists> h_ptMedium_Barrel_slimmedJetAK8_SoftDrop; //irene for w mass
  std::unique_ptr<Hists> h_ptHigh_Barrel_slimmedJetAK8_SoftDrop; //irene for w mass

  std::unique_ptr<Hists> h_ptLow_Endcap_slimmedJetAK8_SoftDrop; //irene for w mass                                                                                                                          
  std::unique_ptr<Hists> h_ptMedium_Endcap_slimmedJetAK8_SoftDrop; //irene for w mass 
  std::unique_ptr<Hists> h_ptHigh_Endcap_slimmedJetAK8_SoftDrop; //irene for w mass 

  std::unique_ptr<Hists> h_input_slimmedJetAK8_SoftDrop; //irene for w mass                                                                                                                          
  std::unique_ptr<Hists> h_SDmass_slimmedJetAK8_SoftDrop; //irene for w mass                                                                                                                          
  std::unique_ptr<Hists> h_input_ak8GenJetsSoftDrop; //irene for w mass
  //    std::unique_ptr<Hists> h_input_GenParticles; //irene for VBF
};


UpgradeStudiesGtoWWModule::UpgradeStudiesGtoWWModule(Context & ctx){
    // In the constructor, the typical tasks are to initialize the
    // member variables, in particular the AnalysisModules such as
    // CommonModules or some cleaner module, Selections and Hists.
    // But you can do more and e.g. access the configuration, as shown below.
    
    cout << "Hello World from UpgradeStudiesGtoWWModule!" << endl;
    
    // If needed, access the configuration of the module here, e.g.:
    string testvalue = ctx.get("TestKey", "<not set>");
    cout << "TestKey in the configuration was: " << testvalue << endl;
    
    // If running in SFrame, the keys "dataset_version", "dataset_type", "dataset_lumi",
    // and "target_lumi" are set to the according values in the xml file. For CMSSW, these are
    // not set automatically, but can be set in the python config file.
    for(auto & kv : ctx.get_all()){
        cout << " " << kv.first << " = " << kv.second << endl;
    }
    

    phase_ = ctx.get("phase");

    // 1. setup other modules. CommonModules and the JetCleaner:
    
    common.reset(new CommonModules());
    // TODO: configure common here, e.g. by 
    // calling common->set_*_id or common->disable_*
    common->disable_mcpileupreweight(); //irene
    common->disable_metfilters(); //irene
    common->disable_jec(); //irene


   
    // TopJet correctors                     
    std::vector<std::string> JEC_AK4, JEC_AK8;
    if(phase_=="phase2")
      {
	// JEC_AK4 = JERFiles::PhaseIIFall17_V2_MC_L2Relative_AK4PUPPI;
	// JEC_AK8 = JERFiles::PhaseIIFall17_V2_MC_L2Relative_AK8PUPPI; 
	JEC_AK4 = JERFiles::PhaseIIFall17_V3_MC_L2Relative_AK4PUPPI;
	JEC_AK8 = JERFiles::PhaseIIFall17_V3_MC_L2Relative_AK8PUPPI; 
      }
    if(phase_=="phase0")
      {
        JEC_AK4 = JERFiles::Summer16_23Sep2016_V4_L123_AK4PFPuppi_MC;
        JEC_AK8 = JERFiles::Summer16_23Sep2016_V4_L123_AK8PFPuppi_MC;
      }

    jet_corrector.reset(new JetCorrector(ctx, JEC_AK4));
    topjet_corrector.reset(new TopJetCorrector(ctx, JEC_AK8));
   

    common->init(ctx);

    // jetcleaner.reset(new JetCleaner(ctx, 30.0, 2.4)); 
    // topjetcleaner.reset(new TopJetCleaner(ctx,TopJetId(PtEtaCut(0., 2.5))));    

    jetcleaner.reset(new JetCleaner(ctx, 30.0, 5)); 
    topjetcleaner.reset(new TopJetCleaner(ctx,TopJetId(PtEtaCut(0., 5))));    

    // note that the JetCleaner is only kept for the sake of example;
    // instead of constructing a jetcleaner explicitly,
    // the cleaning can also be achieved with less code via CommonModules with:
    // common->set_jet_id(PtEtaCut(30.0, 2.4));
    // before the 'common->init(ctx)' line.
    
    // 2. set up selections
    ptLow_sel.reset(new PtSelection(700.0f,1300.0f)); // see UpgradeStudiesGtoWWSelections
    ptMedium_sel.reset(new PtSelection(1500.0f,2500.0f)); // see UpgradeStudiesGtoWWSelections
    ptHigh_sel.reset(new PtSelection(2500.0f,3500.0f)); // see UpgradeStudiesGtoWWSelections
    ptMin_qcd.reset(new PtSelection(100.0f,200.0f)); // see UpgradeStudiesGtoWWSelections
    ptMed_qcd.reset(new PtSelection(200.0f,400.0f)); // see UpgradeStudiesGtoWWSelections
    ptMax_qcd.reset(new PtSelection(400.0f,600.0f)); // see UpgradeStudiesGtoWWSelections
    barrel_sel.reset(new EtaBarrelSelection()); // see UpgradeStudiesGtoWWSelections
    endcap_sel.reset(new EtaEndcapSelection()); // see UpgradeStudiesGtoWWSelections
    SDmass_sel.reset(new SDMassSelection()); // see UpgradeStudiesGtoWWSelections

    // 3. Set up Hists classes:
    h_start_ak8.reset(new TopJetHists(ctx, "start_ak8")); //irene for w mass                           
    h_Qstar.reset(new UpgradeStudiesGtoWWHists(ctx, "Qstar"));
    h_Qstar_barrel.reset(new UpgradeStudiesGtoWWHists(ctx, "Qstar_barrel"));
    h_Qstar_endcap.reset(new UpgradeStudiesGtoWWHists(ctx, "Qstar_endcap"));

    h_qcd_lowPt.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_lowPt"));
    h_qcd_lowPt_barrel.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_lowPt_barrel"));
    h_qcd_lowPt_endcap.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_lowPt_endcap"));
    h_qcd_mediumPt.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_mediumPt"));
    h_qcd_mediumPt_barrel.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_mediumPt_barrel"));
    h_qcd_mediumPt_endcap.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_mediumPt_endcap"));
    h_qcd_highPt.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_highPt"));
    h_qcd_highPt_barrel.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_highPt_barrel"));
    h_qcd_highPt_endcap.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_highPt_endcap"));

    h_qcd_minPt.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_minPt"));
    h_qcd_minPt_barrel.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_minPt_barrel"));
    h_qcd_minPt_endcap.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_minPt_endcap"));
    h_qcd_medPt.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_medPt"));
    h_qcd_medPt_barrel.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_medPt_barrel"));
    h_qcd_medPt_endcap.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_medPt_endcap"));
    h_qcd_maxPt.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_maxPt"));
    h_qcd_maxPt_barrel.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_maxPt_barrel"));
    h_qcd_maxPt_endcap.reset(new UpgradeStudiesGtoWWHists(ctx, "qcd_maxPt_endcap"));


    h_input_slimmedGenJet.reset(new GenJetsHists(ctx, "slimmedGenJet_nocuts")); //irene for w mass                                                                                                         
    h_input_slimmedJet.reset(new JetHists(ctx, "slimmedJet_nocuts")); //irene for w mass
    h_input_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_nocuts")); //irene for w mass                                                                                
    h_ptLow_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptLow")); //irene for w mass                                                                                
    h_ptMedium_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptMedium")); //irene for w mass                                                                                
    h_ptHigh_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptHigh")); //irene for w mass                                                                                

    h_ptLow_Barrel_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptLow_Barrel")); //irene for w mass                                           
    h_ptMedium_Barrel_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptMedium_Barrel")); //irene for w mass
    h_ptHigh_Barrel_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptHigh_Barrel")); //irene for w mass

    h_ptLow_Endcap_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptLow_Endcap")); //irene for w mass  
    h_ptMedium_Endcap_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptMedium_Endcap")); //irene for w mass  
    h_ptHigh_Endcap_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptHigh_Endcap")); //irene for w mass 

    h_SDmass_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_SDmass")); //irene for w mass                                                                                
    h_input_ak8GenJetsSoftDrop.reset(new UpgradeGenTopJetHists(ctx, "GenJetAK8_SoftDrop_nocuts"));
    //    h_input_GenParticles(new (ctx, "GenParticles"));

    cout << "UpgradeStudiesGtoWWModule  " <<  endl;
    
}


bool UpgradeStudiesGtoWWModule::process(Event & event) {
    // This is the main procedure, called for each event. Typically,
    // do some pre-processing by calling the modules' process method
    // of the modules constructed in the constructor (1).
    // Then, test whether the event passes some selection and -- if yes --
    // use it to fill the histograms (2).
    // Finally, decide whether or not to keep the event in the output (3);
    // this is controlled by the return value of this method: If it
    // returns true, the event is kept; if it returns false, the event
    // is thrown away.
    
    cout << "UpgradeStudiesGtoWWModule: Starting to process event (runid, eventid) = (" << event.run << ", " << event.event << "); weight = " << event.weight << endl;
    
    // 1. run all modules other modules.
    h_start_ak8->fill(event);

    common->process(event);
    
    
    topjet_corrector->process(event);
    //    subjet_corrector->process(event);
    //    jet_corrector->process(event);
    jet_corrector->correct_met(event);
    
    sort_by_pt<Jet>(*event.jets);
    sort_by_pt<TopJet>(*event.topjets);


    jetcleaner->process(event);
    topjetcleaner->process(event);
    // 2. test selections and fill histograms
    h_Qstar->fill(event);
    h_input_slimmedGenJet->fill(event);     //irene for w mass
    h_input_slimmedJet->fill(event);     //irene for w mass
    h_input_slimmedJetAK8_SoftDrop->fill(event);     //irene for w mass                                                                                                                                  
    h_input_ak8GenJetsSoftDrop->fill(event);     //irene for w mass 
    //    h_input_GenParticles->fill(event);     //irene for w VBF 

    bool barrel_selection = barrel_sel->passes(event);
    bool endcap_selection = endcap_sel->passes(event);

    if(barrel_selection)
      h_Qstar_barrel->fill(event);
    if(endcap_selection)
      h_Qstar_endcap->fill(event);

    bool ptLow_selection = ptLow_sel->passes(event);
    if(ptLow_selection){
      h_ptLow_slimmedJetAK8_SoftDrop->fill(event);
      h_qcd_lowPt->fill(event);
      if(barrel_selection)
	{
	  h_ptLow_Barrel_slimmedJetAK8_SoftDrop->fill(event);
	  h_qcd_lowPt_barrel->fill(event);
	}
      if(endcap_selection)
	{
	  h_ptLow_Endcap_slimmedJetAK8_SoftDrop->fill(event);
	  h_qcd_lowPt_endcap->fill(event);
	}
    }
    bool ptMedium_selection = ptMedium_sel->passes(event);
    if(ptMedium_selection){
      h_ptMedium_slimmedJetAK8_SoftDrop->fill(event);
      h_qcd_mediumPt->fill(event);

      if(barrel_selection)
	{
	  h_ptMedium_Barrel_slimmedJetAK8_SoftDrop->fill(event);
	  h_qcd_mediumPt_barrel->fill(event);
	}
      if(endcap_selection)
	{
	  h_ptMedium_Endcap_slimmedJetAK8_SoftDrop->fill(event);
	  h_qcd_mediumPt_endcap->fill(event);
	}
    }
    bool ptHigh_selection = ptHigh_sel->passes(event);
    if(ptHigh_selection){
      h_ptHigh_slimmedJetAK8_SoftDrop->fill(event);
      h_qcd_highPt->fill(event);

      if(barrel_selection)
	{
	  h_ptHigh_Barrel_slimmedJetAK8_SoftDrop->fill(event);
	  h_qcd_highPt_barrel->fill(event);
	}
      if(endcap_selection)
	{
	  h_ptHigh_Endcap_slimmedJetAK8_SoftDrop->fill(event);
	  h_qcd_highPt_endcap->fill(event);
	}
    }


    bool ptMin_selection = ptMin_qcd->passes(event);
    if(ptMin_selection){
      h_qcd_minPt->fill(event);
      if(barrel_selection)
	{
	  h_qcd_minPt_barrel->fill(event);
	}
      if(endcap_selection)
	{
	  h_qcd_minPt_endcap->fill(event);
	}
    }
    bool ptMed_selection = ptMed_qcd->passes(event);
    if(ptMed_selection){
      h_qcd_medPt->fill(event);

      if(barrel_selection)
	{
	  h_qcd_medPt_barrel->fill(event);
	}
      if(endcap_selection)
	{
	  h_qcd_medPt_endcap->fill(event);
	}
    }
    bool ptMax_selection = ptMax_qcd->passes(event);
    if(ptMax_selection){
      h_qcd_maxPt->fill(event);

      if(barrel_selection)
	{
	  h_qcd_maxPt_barrel->fill(event);
	}
      if(endcap_selection)
	{
	  h_qcd_maxPt_endcap->fill(event);
	}
    }




    bool SDmass_selection = SDmass_sel->passes(event);
    if(SDmass_selection){
      h_SDmass_slimmedJetAK8_SoftDrop->fill(event);
    }
    // 3. decide whether or not to keep the current event in the output:
}

// as we want to run the ExampleCycleNew directly with AnalysisModuleRunner,
// make sure the UpgradeStudiesGtoWWModule is found by class name. This is ensured by this macro:
UHH2_REGISTER_ANALYSIS_MODULE(UpgradeStudiesGtoWWModule)

}
