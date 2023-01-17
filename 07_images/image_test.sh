#! /bin/bash

if [ ! -e "functional.cc" ]
then
    touch functional.cc
fi

if [ ! -e "images.cc" ]
then
    touch images.cc
fi

if [ ! -d "./build-tests/" ]
then
    mkdir build-tests
fi

cd build-tests

rm *.bmp

cmake ../src
make

echo "Running official tests"

./example
rcode=$?

if [ ! $rcode ]
then
    echo "Official tests returned with exit code $rcode"
    exit 1
fi

echo "Running student tests"

./image_test
rcode=$?

if [ ! $rcode ]
then
    echo "Error: ./image_test returned with exit code $rcode"
    exit 1
fi

if [ ! -d "../diffs" ]
then
    mkdir ../diffs
fi

passed=0
failed=0

for f in *.bmp
do
    echo "Checking $f..."
    ./diff_bmp $f ../original-images/$f ../diffs/$f
    rcode=$?
    if [[ $rcode = 0 ]]
    then
        ((passed=$passed+1))
    elif [[ $rcode = 1 ]]
    then
        ((failed=$failed+1))
    else
        echo "Fatal error!"
        exit 1
    fi
done

echo ""
echo "$passed test passed, $failed tests failed"
