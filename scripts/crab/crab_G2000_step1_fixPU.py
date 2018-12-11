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
sys.path.append('/nfs/dust/cms/user/zoiirene/CMSSW_8_0_24_patch1/src/UHH2/scripts/crab')
from DasQuery import autocomplete_Datasets

#inputDatasets = ['/DYJetsToLL_M-50_HT-*to*_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_*/MINIAODSIM']
inputDatasets = ['/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/RunIISummer15GS-MCRUN2_71_V1-v1/GEN-SIM']
inputDatasets = autocomplete_Datasets(inputDatasets)
requestNames = ['VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain3']
for x in inputDatasets:
    name = x.split('/')[1]
    modified_name =name.replace('_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1','')
    if 'ext' in x:
        modified_name += '_ext'
    requestNames.append(modified_name)


# ===============================================================================
# Classical part of crab, after resolving the * it uses in the example below just the first entry
#

from CRABClient.UserUtilities import config, getUsernameFromSiteDB


config = config()
config.General.workArea = 'crab_GravitonToWW'
config.General.transferOutputs = True
config.General.transferLogs = True
        
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/nfs/dust/cms/user/zoiirene/DiBoson/GravitonToWW/FixingPU/EXO-RunIISummer16DR80Premix-08160_1_cfg_2000_crab.py'
config.JobType.outputFiles = ["EXO-RunIISummer16DR80Premix-08160_step1_crab.root"]
config.JobType.maxMemoryMB = 2500
#config.JobType.inputFiles = ['/nfs/dust/cms/user/gonvaq/CMSSW/CMSSW_7_4_15_patch1/src/UHH2/core/python/Summer15_25nsV2_MC.db']
        
config.Data.inputDBS = 'global'
config.Data.splitting = 'EventAwareLumiBased'
config.Data.unitsPerJob = 50
config.Data.outLFNDirBase = '/store/user/%s/Graviton_fixPU/' % (getUsernameFromSiteDB())
config.Data.publication = False
config.JobType.sendExternalFolder = True 
#config.Data.allowNonValidInputDataset = True
#config.Data.publishDataName = 'CRAB3_tutorial_May2015_MC_analysis'

config.Site.storageSite = 'T2_DE_DESY'

config.General.requestName = requestNames[0]
config.Data.inputDataset = inputDatasets[0]

config.JobType.numCores = 4
