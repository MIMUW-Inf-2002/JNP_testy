verbose=false
RED="\e[1;31m"
GREEN="\e[1;32m"
YELLOW="\e[1;33m"
MAGENTA="\e[1;35m"

BOLD="\e[1m"
ENDCOLOR="\e[0m"

if [ $# -eq 0 ]; then
    echo "Usage: ./test.sh <path to source directory> [-v]"
    echo "Example: ./test.sh ./src -v"
    exit 1
fi

SRC_DIR=$1

if [ ! -d $SRC_DIR ]; then
    echo "${RED}Fatal Error:${ENDCOLOR} Source directory does not exist. Exiting."
    exit 1
fi

if [ "$2" = "-v" ]; then
    echo "${MAGENTA}Verbose mode enabled.${ENDCOLOR} You can find all logs in ./logs.txt \n"
    verbose=true
fi

if [ ! -d './test_images' ]; then
    mkdir ./test_images
fi

gxx_version=$(g++ -dumpversion)

if [ $gxx_version -lt 10 ]
    then
        echo "${YELLOW}Warning:${ENDCOLOR} You use an old g++ version. You may miss some libraries but otherwise everything should work fine."
        echo "Trying compilation with ${BOLD}'-std=c++2a'${ENDCOLOR}"

        g++ -Wall -Wextra -pedantic -O2 -std=c++2a $SRC_DIR/*.cc -o $SRC_DIR/test
    else
        g++ -Wall -Wextra -pedantic -O2 -std=c++20 $SRC_DIR/*.cc -o $SRC_DIR/test
fi

if [ $? -ne 0 ]; then 
    echo "${RED}Fatal Error:${ENDCOLOR} Could not compile test program. Exiting."
    exit 1
fi

echo "${GREEN}Compilation successful.${ENDCOLOR} Running test program. \n"
./$SRC_DIR/test
python3 test.py verbose