#!/bin/bash

FILEDIR=${1}

[ -z ${FILEDIR} ] && printf "Nie podałeś folderu z plikami!\n" && exit 1

# Nie wiemy ile jest plików, więc skopiuj wszysztkie
cp $FILEDIR/*.{cc,h} .
# Jeśli ktoś miał własny plik main to wywal
rm -f main.cc

[ ! -d "build" ] && mkdir build

cd build
cmake ..

cmake --build .
