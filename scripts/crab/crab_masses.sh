#!/bin/bash                                                 

array=(800 2000)
versi=(2   3   )
#array=(800 1000 1200 1600 1800 2500 3000 3000 3500 3500 4000 4500)
#versi=(2   3    2    2    1    2    2    3    2    3    2    3)
#array=(600 800 1000 1200 1400 1600 1800 2000 2500 3000 3000 3500 3500 4000 4500)
#versi=(2   2   3    2    2    2    1    3    2    2    3    2    3    2    3)


for i in {0..1}
do 
#    cp  crab_NTupleGraviton_MASSES_WW_PUMoriond17_80X_mcRun2_VERSION.py crab_NTupleGraviton_${array[$i]}_WW_PUMoriond17_80X_mcRun2_${versi[$i]}.py 
#    sed -i "s|MASSES|${array[$i]}|g" crab_NTupleGraviton_${array[$i]}_WW_PUMoriond17_80X_mcRun2_${versi[$i]}.py
#    sed -i "s|VERSION|${versi[$i]}|g" crab_NTupleGraviton_${array[$i]}_WW_PUMoriond17_80X_mcRun2_${versi[$i]}.py
#    echo "copied"
    
#    crab submit -c crab_NTupleGraviton_${array[$i]}_WW_PUMoriond17_80X_mcRun2_${versi[$i]}.py 2>&1 | tee crab_NTupleGraviton_${array[$i]}_WW_PUMoriond17_80X_mcRun2_${versi[$i]}.log
    crab resubmit -d crab_ntupleGravitonToWW/crab_VBF_GravitonToWW_narrow_${array[$i]}_13TeV-madgraph-pythia8_official_2016_PUMoriond2017_ntuple_v${versi[$i]}
    echo "submit ${array[$i]} _${versi[$i]}" 
done
#crab resubmit -d crab_GravitonToWW/crab_VBF_GravitonToWW_narrow_M-3000_13TeV-madgraph_step1_tryAgain4 2>&1