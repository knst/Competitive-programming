#!/bin/bash

i=$1
cat ../samples/$i.txt | ./points_solver debug 2>&1 | grep score > out/$i.out

