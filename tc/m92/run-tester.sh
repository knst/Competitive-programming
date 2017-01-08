#!/bin/bash

set -e

echo > output.txt

for i in 2 3 6 9 10
    do java -jar tester2.jar -exec './Lighting2' -seed $i >> output.txt &
    sleep 3s;
done

sleep 1s

for i in 1 4 5 7 8
    do java -jar tester2.jar -exec './Lighting2' -seed $i >> output.txt &
    sleep 1s;
done

#for i in 11 12 13 14 15 16 17 18 19 20
#    do java -jar tester2.jar -exec './Lighting2' -seed $i >> output.txt &
#    sleep 5s;
#done

#for i in $(seq 21 100)
#    do java -jar tester2.jar -exec './Lighting2' -seed $i >> output.txt &
#    sleep 2s;
#done

for job in `jobs -p`
do wait $job || let "FAIL+=1"
done

echo $FAIL
cat output.txt
cat output.txt  | grep "Score = " | awk '{print $3}' | tr '\n' '+' | sed 's/+$/\n/' | bc
