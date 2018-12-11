#!/bin/bash                                                 
array=(1200 1400 1600 1800 2500 3000 3500 4000 4500)
for i in {0..8}
do 

#echo ${array[$i]}
#cp /nfs/dust/cms/user/zoiirene/DiBoson/GravitonToWW/FixingPU/EXO-RunIISummer16DR80Premix-08160_1_cfg_MASS_crab.py /nfs/dust/cms/user/zoiirene/DiBoson/GravitonToWW/FixingPU/EXO-RunIISummer16DR80Premix-08160_1_cfg_${array[$i]}_crab.py

#cp crab_G_MASS_step1_fixPU.py crab_G_${array[$i]}_step1_fixPU.py
#sed -i "s|MASS|${array[$i]}|g" crab_G_${array[$i]}_step1_fixPU.py
#sed -i "s|MASS|${array[$i]}|g" /nfs/dust/cms/user/zoiirene/DiBoson/GravitonToWW/FixingPU/EXO-RunIISummer16DR80Premix-08160_1_cfg_${array[$i]}_crab.py

crab kill -d crab_GravitonToWW/crab_VBF_GravitonToWW_narrow_M-${array[$i]}_13TeV-madgraph_step1_try 2>&1 | tee my.log
done