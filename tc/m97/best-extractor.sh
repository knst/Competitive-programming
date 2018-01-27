#!/bin/bash

set -e

in=$1
picked=$2

for i in $(ls "$in/") 
do
    if [ -f "$picked/$i" ] 
        then 
            s_picked=$(cat "$picked/$i" | grep score | awk '{print $2}')
            s_in=$(cat "$in/$i" | grep score | awk '{print $2}')
            if (( $(echo "$s_in < $s_picked" | bc -l) )); then
                cp "$in/$i" "$picked/"
            fi
        else
            cp "$in/$i" "$picked/"
    fi
done
