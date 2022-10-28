#!/bin/bash

FILEDIR=${1}

[ -z ${FILEDIR} ] && printf "Nie podałeś folderu z plikami!\n" && exit 1

rm -f hash.cc hash.h
# Jeżeli tworzenie linków nie działa to należy podmienić poniższe linijki
ln $FILEDIR/hash.cc hash.cc || exit 1
ln $FILEDIR/hash.h hash.h || exit 1

[ ! -d "build" ] && mkdir build

cd build
cmake ..

cmake --build .