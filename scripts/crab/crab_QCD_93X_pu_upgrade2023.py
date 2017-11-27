# This is a small example how the crab api can easily be used to create something like multi crab.
# It has some additional features like also creating the xml files for you. 
# For it to work you need inputDatasets & requestNames apart from the classical part 
#
# Make sure to have a unique directory where your joboutput is saved, otherwise the script gets confused and you too!!
#
# Usage ./CrabConfig ConfigFile [options]
#
# Take care here to make the request names *nice*
# 
# autocomplete_Datasets(ListOfDatasets) works also for several entries with *
#
import sys, os
sys.path.append('/nfs/dust/cms/user/zoiirene/UpgradeStudiesGtoWW/framework93X/new932/CMSSW_9_3_2/src/UHH2/scripts/crab')
from DasQuery import autocomplete_Datasets

#inputDatasets = ['/QCD_Flat_Pt-15to7000_TuneCUETP8M1_14TeV_pythia8/PhaseIITDRFall17MiniAOD-noPU_93X_upgrade2023_realistic_v2-v1/MINIAODSIM']
inputDatasets = ['/QCD_Flat_Pt-15to7000_TuneCUETP8M1_14TeV_pythia8/PhaseIITDRFall17MiniAOD-PU200_93X_upgrade2023_realistic_v2-v2/MINIAODSIM']
inputDatasets = autocomplete_Datasets(inputDatasets)
requestNames = ['QCD_Flat_Pt-15to7000_TuneCUETP8M1_14TeV_PhaseIITDRFall17_PU200_v2_try6']
for x in inputDatasets:
    name = x.split('/')[1]
    modified_name =name.replace('QCD_Flat_Pt-15to7000_TuneCUETP8M1_14TeV_PU200','')
    if 'ext' in x:
        modified_name += '_ext'
    requestNames.append(modified_name)


# ===============================================================================
# Classical part of crab, after resolving the * it uses in the example below just the first entry
#

from CRABClient.UserUtilities import config, getUsernameFromSiteDB


config = config()
config.General.workArea = 'crab_QCD'
config.General.transferOutputs = True
config.General.transferLogs = True
        
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/nfs/dust/cms/user/zoiirene/UpgradeStudiesGtoWW/framework93X/new932/CMSSW_9_3_2/src/UHH2/core/python/ntuplewriter_93X_irene.py'
config.JobType.outputFiles = ["Ntuple_AK8_fix.root"]
config.JobType.maxMemoryMB = 2500
#config.JobType.inputFiles = ['/nfs/dust/cms/user/gonvaq/CMSSW/CMSSW_7_4_15_patch1/src/UHH2/core/python/Summer15_25nsV2_MC.db']
        
config.Data.inputDBS = 'global'
config.Data.splitting = 'EventAwareLumiBased'
config.Data.unitsPerJob = 1000
config.Data.outLFNDirBase = '/store/user/%s/RunII_93X_v2-v2/QCD_flat_PU200_fix' % (getUsernameFromSiteDB())
config.Data.publication = False
config.JobType.sendExternalFolder = True 
config.Data.allowNonValidInputDataset = True
#config.Data.allowNonValidInputDataset = True
#config.Data.publishDataName = 'CRAB3_tutorial_May2015_MC_analysis'

config.Site.storageSite = 'T2_DE_DESY'
config.Site.blacklist = 'T2_IT_Rome'

config.General.requestName = requestNames[0]
config.Data.inputDataset = inputDatasets[0]


