#!/bin/bash

FILEDIR=${1}

[ -z ${FILEDIR} ] && printf "Nie podałeś folderu z plikami!\n" && exit 1

rm -f hash.cc hash.h
ln -s $FILEDIR/hash.cc hash.cc
ln -s $FILEDIR/hash.h hash.h

rm -rf build
mkdir build
cd build
cmake ..
cmake --build .