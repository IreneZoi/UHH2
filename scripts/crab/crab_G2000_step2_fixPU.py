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

#import sys, os
#sys.path.append('/nfs/dust/cms/user/zoiirene/CMSSW_8_0_24_patch1/src/UHH2/scripts/crab')
#from DasQuery import autocomplete_Datasets

#inputDatasets = ['/DYJetsToLL_M-50_HT-*to*_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_*/MINIAODSIM']
#inputDatasets = ['/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/RunIISummer15GS-MCRUN2_71_V1-v1/GEN-SIM']
#inputDatasets = autocomplete_Datasets(inputDatasets)
#requestNames = ['VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2']
#for x in inputDatasets:
#    name = x.split('/')[1]
#    modified_name =name.replace('_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1','')
#    if 'ext' in x:
#        modified_name += '_ext'
#    requestNames.append(modified_name)


# ===============================================================================
# Classical part of crab, after resolving the * it uses in the example below just the first entry
#

from CRABClient.UserUtilities import config, getUsernameFromSiteDB


config = config()
config.General.workArea = 'crab_GravitonToWW'
config.General.transferOutputs = True
config.General.transferLogs = True
        
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/nfs/dust/cms/user/zoiirene/DiBoson/GravitonToWW/FixingPU/EXO-RunIISummer16DR80Premix-08160_2_cfg_2000_crab.py'
config.JobType.outputFiles = ["EXO-RunIISummer16DR80Premix-08160_step2_crab.root"]
config.JobType.maxMemoryMB = 2500
#config.JobType.inputFiles = ['/nfs/dust/cms/user/gonvaq/CMSSW/CMSSW_7_4_15_patch1/src/UHH2/core/python/Summer15_25nsV2_MC.db']
        
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 50
config.Data.outLFNDirBase = '/store/user/%s/Graviton_fixPU/' % (getUsernameFromSiteDB())
config.Data.publication = False
config.JobType.sendExternalFolder = True 
#config.Data.allowNonValidInputDataset = True
#config.Data.publishDataName = 'CRAB3_tutorial_May2015_MC_analysis'

config.Site.storageSite = 'T2_DE_DESY'
config.Site.whitelist  = ['T2_DE_DESY']

config.General.requestName = 'VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step2_tryAgain3'
config.Data.userInputFiles = [
#qui!
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_250.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_249.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_248.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_247.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_246.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_245.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_244.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_243.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_242.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_241.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_240.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_239.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_238.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_237.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_236.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_235.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_234.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_233.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_232.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_231.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_230.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_229.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_228.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_227.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_226.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_225.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_224.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_223.root',
#'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_222.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_221.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_220.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_219.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_218.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_217.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_216.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_215.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_214.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_213.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_212.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_211.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_210.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_209.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_208.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_207.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_206.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_205.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_204.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_203.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_202.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_201.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_200.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_199.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_198.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_197.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_196.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_195.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_194.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_193.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_192.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_191.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_190.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_189.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_188.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_187.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_186.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_185.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_184.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_183.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_182.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_181.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_180.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_179.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_178.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_177.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_176.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_175.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_174.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_173.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_172.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_171.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_170.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_169.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_168.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_167.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_166.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_165.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_164.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_163.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_162.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_161.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_160.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_159.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_158.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_157.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_156.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_155.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_154.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_153.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_152.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_151.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_150.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_149.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_148.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_147.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_146.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_145.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_144.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_143.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_142.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_141.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_140.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_139.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_138.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_137.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_136.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_135.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_134.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_133.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_132.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_131.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_130.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_129.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_128.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_127.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_126.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_125.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_124.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_123.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_122.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_121.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_120.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_119.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_118.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_117.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_116.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_115.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_114.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_113.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_112.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_111.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_110.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_109.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_108.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_107.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_106.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_105.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_104.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_103.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_102.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_101.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_100.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_99.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_98.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_97.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_96.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_95.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_94.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_93.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_92.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_91.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_90.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_89.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_88.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_87.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_86.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_85.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_84.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_83.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_82.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_81.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_80.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_79.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_78.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_77.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_76.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_75.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_74.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_73.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_72.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_71.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_70.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_69.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_68.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_67.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_66.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_65.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_64.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_63.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_62.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_61.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_60.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_59.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_58.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_57.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_56.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_55.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_54.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_53.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_52.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_51.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_50.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_49.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_48.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_47.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_46.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_45.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_44.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_43.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_42.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_41.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_40.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_39.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_38.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_37.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_36.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_35.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_34.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_33.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_32.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_31.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_30.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_29.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_28.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_27.root',
#'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_26.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_25.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_24.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_23.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_22.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_21.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_20.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_19.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_18.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_17.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_16.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_15.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_14.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_13.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_12.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_11.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_10.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_9.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_8.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_7.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_6.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_5.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_4.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_3.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_2.root',
'/store/user/izoi/Graviton_fixPU/VBF_BulkGravToWW_narrow_M-2000_13TeV-madgraph/crab_VBF_GravitonToWW_narrow_M-2000_13TeV-madgraph_step1_tryAgain2/171015_210704/0000/EXO-RunIISummer16DR80Premix-08160_step1_crab_1.root'
]
#config.Data.inputDataset = inputDatasets[0]

config.JobType.numCores = 4
