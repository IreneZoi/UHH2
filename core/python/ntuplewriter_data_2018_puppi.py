import FWCore.ParameterSet.Config as cms
from UHH2.core.ntuple_generator_puppi_new import generate_process  # use CMSSW type path for CRAB
from UHH2.core.optionsParse import setup_opts, parse_apply_opts
#default number of events is set to 500, to have more add maxEvents=2000 to the end of your cmsRun command
#crab will automatically override that 500

"""NTuple config for 2018 DATA datasets.

You should try and put any centralised changes in generate_process(), not here.
"""


process = generate_process(year="2018", useData=True)

# Please do not commit changes to source filenames - used for consistency testing
process.source.fileNames = cms.untracked.vstring([
'/store/data/Run2018D/JetHT/MINIAOD/PromptReco-v2/000/325/170/00000/9494B803-292B-F343-9BCC-6CAD47CB0C8B.root'
])

# Do this after setting process.source.fileNames, since we want the ability to override it on the commandline
options = setup_opts()
parse_apply_opts(process, options)

with open('pydump_data_2018_puppi.py', 'w') as f:
    f.write(process.dumpPython())
