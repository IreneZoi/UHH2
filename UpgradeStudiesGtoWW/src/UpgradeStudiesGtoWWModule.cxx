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
    
    std::unique_ptr<CommonModules> common;
    
    std::unique_ptr<JetCleaner> jetcleaner;
    std::unique_ptr<TopJetCleaner> topjetcleaner;
   
    // declare the Selections to use. Use unique_ptr to ensure automatic call of delete in the destructor,
    // to avoid memory leaks.
  std::unique_ptr<Selection> njet_sel, dijet_sel, SDmass_sel, ptLow_sel, ptMedium_sel, ptHigh_sel;
    
    // store the Hists collection as member variables. Again, use unique_ptr to avoid memory leaks.
  std::unique_ptr<Hists> h_nocuts, h_njet, h_dijet, h_ele, h_Qstar;
  std::unique_ptr<Hists> h_start_ak8; //irene for w mass
  std::unique_ptr<Hists> h_input_slimmedGenJet; //irene for w mass                                                                                                                                  
  std::unique_ptr<Hists> h_input_slimmedJet; //irene for w mass
  std::unique_ptr<Hists> h_ptLow_slimmedJetAK8_SoftDrop; //irene for w mass                                                                                                                          
  std::unique_ptr<Hists> h_ptMedium_slimmedJetAK8_SoftDrop; //irene for w mass                                                                                                                          
  std::unique_ptr<Hists> h_ptHigh_slimmedJetAK8_SoftDrop; //irene for w mass                                                                                                                          
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
    
    // 1. setup other modules. CommonModules and the JetCleaner:
    
    common.reset(new CommonModules());
    // TODO: configure common here, e.g. by 
    // calling common->set_*_id or common->disable_*
    common->disable_mcpileupreweight(); //irene
    common->disable_metfilters(); //irene
    common->init(ctx);
    jetcleaner.reset(new JetCleaner(ctx, 30.0, 2.4)); 
    topjetcleaner.reset(new TopJetCleaner(ctx,TopJetId(PtEtaCut(0., 2.5))));    
    // note that the JetCleaner is only kept for the sake of example;
    // instead of constructing a jetcleaner explicitly,
    // the cleaning can also be achieved with less code via CommonModules with:
    // common->set_jet_id(PtEtaCut(30.0, 2.4));
    // before the 'common->init(ctx)' line.
    
    // 2. set up selections
    njet_sel.reset(new NJetSelection(2)); // see common/include/NSelections.h
    dijet_sel.reset(new DijetSelection()); // see UpgradeStudiesGtoWWSelections
    ptLow_sel.reset(new LowPtSelection()); // see UpgradeStudiesGtoWWSelections
    ptMedium_sel.reset(new MediumPtSelection()); // see UpgradeStudiesGtoWWSelections
    ptHigh_sel.reset(new HighPtSelection()); // see UpgradeStudiesGtoWWSelections
    SDmass_sel.reset(new SDMassSelection()); // see UpgradeStudiesGtoWWSelections

    // 3. Set up Hists classes:
    h_start_ak8.reset(new TopJetHists(ctx, "start_ak8")); //irene for w mass                           
    h_nocuts.reset(new UpgradeStudiesGtoWWHists(ctx, "NoCuts"));
    h_Qstar.reset(new UpgradeStudiesGtoWWHists(ctx, "Qstar"));
    h_njet.reset(new UpgradeStudiesGtoWWHists(ctx, "Njet"));
    h_dijet.reset(new UpgradeStudiesGtoWWHists(ctx, "Dijet"));
    h_ele.reset(new ElectronHists(ctx, "ele_nocuts"));
    h_input_slimmedGenJet.reset(new GenJetsHists(ctx, "slimmedGenJet_nocuts")); //irene for w mass                                                                                                         
    h_input_slimmedJet.reset(new JetHists(ctx, "slimmedJet_nocuts")); //irene for w mass
    h_input_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_nocuts")); //irene for w mass                                                                                
    h_ptLow_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptLow")); //irene for w mass                                                                                
    h_ptMedium_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptMedium")); //irene for w mass                                                                                
    h_ptHigh_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_ptHigh")); //irene for w mass                                                                                
    h_SDmass_slimmedJetAK8_SoftDrop.reset(new TopJetHists(ctx, "slimmedJetAK8_SoftDrop_SDmass")); //irene for w mass                                                                                
    h_input_ak8GenJetsSoftDrop.reset(new UpgradeGenTopJetHists(ctx, "GenJetAK8_SoftDrop_nocuts"));
    //    h_input_GenParticles(new (ctx, "GenParticles"));
    
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
    jetcleaner->process(event);
    topjetcleaner->process(event);
    // 2. test selections and fill histograms
    h_ele->fill(event);
    h_nocuts->fill(event);
    h_input_slimmedGenJet->fill(event);     //irene for w mass
    h_input_slimmedJet->fill(event);     //irene for w mass
    h_input_slimmedJetAK8_SoftDrop->fill(event);     //irene for w mass                                                                                                                                  
    h_input_ak8GenJetsSoftDrop->fill(event);     //irene for w mass 
    //    h_input_GenParticles->fill(event);     //irene for w VBF 

    bool njet_selection = njet_sel->passes(event);
    if(njet_selection){
        h_njet->fill(event);
    }
    bool dijet_selection = dijet_sel->passes(event);
    if(dijet_selection){
        h_dijet->fill(event);
    }
    bool ptLow_selection = ptLow_sel->passes(event);
    if(ptLow_selection){
      h_ptLow_slimmedJetAK8_SoftDrop->fill(event);
    }
    bool ptMedium_selection = ptMedium_sel->passes(event);
    if(ptMedium_selection){
      h_ptMedium_slimmedJetAK8_SoftDrop->fill(event);
    }
    bool ptHigh_selection = ptHigh_sel->passes(event);
    if(ptHigh_selection){
      h_ptHigh_slimmedJetAK8_SoftDrop->fill(event);
      h_Qstar->fill(event);
    }
    bool SDmass_selection = SDmass_sel->passes(event);
    if(SDmass_selection){
      h_SDmass_slimmedJetAK8_SoftDrop->fill(event);
    }
    // 3. decide whether or not to keep the current event in the output:
    return njet_selection && dijet_selection;
}

// as we want to run the ExampleCycleNew directly with AnalysisModuleRunner,
// make sure the UpgradeStudiesGtoWWModule is found by class name. This is ensured by this macro:
UHH2_REGISTER_ANALYSIS_MODULE(UpgradeStudiesGtoWWModule)

}
