#!bin/bash

for i in {1..250}
do

crab submit -c crab_ntupleGraviton2000ToWW_${i}.py 2>&1 | tee my.log

done