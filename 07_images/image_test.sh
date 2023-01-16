# ! bin/bash

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
cmake ..
make

echo "Running official tests"

code = ./example

if ! code
then
    echo "Official tests returned with exit code $code"
    exit 1
fi

echo "Running student tests"

code= ./image_test

if ! $code
then
    echo "Error: ./image_test returned with exit code $code"
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
    code= ./diff_bmp $f ../original-images/$f ../diffs/$f
    if $code == 0
    then
        ((passed=$passed+1))
    elif $code == 1
    then
        ((failed=$failed+1))
    else
        echo "Fatal error!"
        exit 1
    fi
done

echo ""
echo "$passed test passed, $failed tests failed"
