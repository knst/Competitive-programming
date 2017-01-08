#!/bin/bash

set -e

rm -r build-java/
mkdir build-java/
javac -d ./build-java *.java
pushd build-java
jar cfe tester2.jar LightingVis *
popd
mv build-java/tester2.jar ./
