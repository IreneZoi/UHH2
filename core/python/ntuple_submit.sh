#!bin/bash                                                                                                                                                                                                   

for i in {1..250}
do

cmsRun ntuplewriter_G2000_${i}.py 2>&1 | tee my.log

done

