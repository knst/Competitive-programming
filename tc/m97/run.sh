#!/bin/bash

index=$1

rm out/*.out

set -e

seq $index $(($index+$index)) | xargs -n 1 -P 4 ../run_one.sh $i

cat out/*.out | awk '{s += $2} END {print s}'
../best-extractor.sh out/ ../picked/
