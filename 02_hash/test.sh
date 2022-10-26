#!/bin/bash

CC="gcc"
CPP="g++"
CFLAGS="-std=c17 -Wall -Wextra -Wno-implicit-fallthrough -g"
CFALGS_WRAP="-Wl,--wrap=malloc -Wl,--wrap=calloc -Wl,--wrap=realloc
	-Wl,--wrap=reallocarray -Wl,--wrap=free -Wl,--wrap=strdup -Wl,--wrap=strndup"
VALGRIND_FLAGS="--leak-check=full --show-leak-kinds=all
	--errors-for-leak-kinds=all --quiet"
TEST_DIR="testy_forward"

BOLD=$(tput bold)
NORMAL=$(tput sgr0)

C_RED="\033[0;31m"
C_DEFAULT="\033[0m"

SKIP_CMAKE_FLAG=""
RUN_VALGRIND_FLAG=0

# Function definitions
print_usage() {
  header="Usage: $0 [options] <path/to/src>"
  options="Options:
    -h   show this help message
    -c   remove test files
    -m   skip cmake tests
    -v   run tests with valgrind"
  printf "%s\n%s\n" "$header" "$options"
}

clean() {
	printf "Removing test files...\n"
	FILES=$(find $TEST_DIR -type f -name "*.o")
	rm -f $FILES
}

test_cmake() {
  # Test CMake Release
  mkdir tmp_cmake_$1_forward_test
  cd tmp_cmake_$1_forward_test || exit
  cmake -D CMAKE_BUILD_TYPE=$1 ../$SRC_DIR/..  > /dev/null
  make > /dev/null

  printf "[OK] TEST CMAKE $1\n"

  ./phone_forward >temp_message

  make clean > temp_message
  rm temp_message
  cd ..
  rm -r -f  tmp_cmake_$1_forward_test

}

# Check flags
while getopts 'chsvm' FLAG; do
	case "${FLAG}" in
		c) clean; exit 0;;
		h) print_usage; exit 0;;
		m) SKIP_CMAKE_FLAG="m";;
		v) RUN_VALGRIND_FLAG=1;;
		*) print_usage; exit 1;;
	esac
done

# Check number of arguments
[[ $# < 1  ]] && print_usage && exit 1

SRC_DIR=${@:$#}

# Notify user if skipping tests
[ "$SKIP_CMAKE_FLAG" == "m" ] && printf "Skipping tests for cmake\n"
[ $RUN_VALGRIND_FLAG == 1 ] && printf "Running tests with valgrind\n"

# Check if SRC_DIR exists
[ ! -d "$SRC_DIR" ] && printf "Directory %s does not exist!\n" "$SRC_DIR" && exit 1

##############################################################################
#                              cmake/doc tests                               #
##############################################################################

[ "$SKIP_CMAKE_FLAG" == "m" ] || test_cmake ''
[ "$SKIP_CMAKE_FLAG" == "m" ] || test_cmake 'Release'
[ "$SKIP_CMAKE_FLAG" == "m" ] || test_cmake 'Test'

# Compile and run tests
SRC_FILES=()

for SRC_FILE in $SRC_DIR/*; do
  if [ -d $SRC_FILE ]
  then
    for SUB_SRC_FILE in $SRC_FILE/*.c; do
      SRC_FILES+="${SUB_SRC_FILE} "
    done
  elif [[ $SRC_FILE == *.c ]]
  then
    SRC_FILE_NAME=$(basename -- "$SRC_FILE")

    if [[ "$SRC_FILE_NAME" != "phone_forward_example.c" && "$SRC_FILE_NAME" != "phone_forward_tests.c" ]]
    then

      SRC_FILES+="${SRC_FILE} "
    fi
  fi
done


TEST_FILES=$(find $TEST_DIR -type f -name "*.c")

for TEST in $TEST_FILES
do
	echo -e "\n${BOLD}========= Running test ${TEST} =========${NORMAL}\n"
	echo -n "Compiling... "

	$CC $CFLAGS -o ${TEST%.c}.o $TEST $SRC_FILES >/dev/null
  [ "$?" -ne 0 ] && printf "${C_RED}Compilation error${C_DEFAULT}\n" && exit 1
	
	echo -e "done"
	
	if [[ $RUN_VALGRIND_FLAG == 1 ]]
	then
		valgrind $VALGRIND_FLAGS ./${TEST%.c}.o
	else
		time ./${TEST%.c}.o
	fi
done


##############################################################################
#                           Instrumented tests                               #
##############################################################################
INSTR_OUT="$TEST_DIR/instrumented.o"
INSTR_IN="$TEST_DIR/official_tests.c"


if [ -f $INSTR_IN ]
then	
	echo -e "\n${BOLD}========= Running instrumented =========${NORMAL}\n"
	echo -n "Compiling... "

	$CC $CFLAGS $CFALGS_WRAP -o $INSTR_OUT $INSTR_IN $SRC_FILES >/dev/null
  [ "$?" -ne 0 ] && printf "${C_RED}Compilation error${C_DEFAULT}\n" && exit 1
	
	echo -e "done"
	
	if [[ $RUN_VALGRIND_FLAG == 1 ]]
	then
		valgrind $VALGRIND_FLAGS ./$INSTR_OUT
	else
		time ./$INSTR_OUT
	fi
fi

