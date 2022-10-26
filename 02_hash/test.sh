#!/bin/bash

FILEDIR=${1}

[ -z ${FILEDIR} ] && printf "Nie podałeś folderu z plikami!\n" && exit 1

cp $FILEDIR/hash.cc .
cp $FILEDIR/hash.h .

rm -rf build
mkdir build
cd build
cmake ..
cmake --build .