#!/bin/sh

PROG=${1}
TEST=${2}

DIR=`pwd`

[ -z ${PROG} ] && printf "Ty j***** idioto, nie podałeś binarki!\n" && exit 1
[ -z ${TEST} ] && printf "Ty j***** idioto, nie podałeś folderu z testami!\n" && exit 1

ansok=0
errok=0
tests=0

printf "Sprawdzam \e[92;1m%s\e[0m.\n" "${PROG}"
for test in ${TEST}/*.in; do
  tests=$((tests + 1))
  test=${test%.in}
  printf "%s\n" ${test}

  ./$PROG < ${test}.in 1> prog.out 2> prog.err

  printf "ANS: "
  diff prog.out ${test}.out >/dev/null 2>&1 \
    && printf "\e[92mOK\e[0m\n" && ansok=$((ansok + 1)) \
    || printf "\e[31mWA\e[0m\n"
  
  printf "ERR: "
  diff prog.err ${test}.err >/dev/null \
    && printf "\e[92mOK\e[0m\n" && errok=$((errok + 1)) \
    || printf "\e[31mWA\e[0m\n"
done

rm -f prog.out prog.err

printf "\nTotal results:\n"
printf "\e[37;1m%d/%d\e[0m tests with correct answer.\n"   "$ansok" "$tests"
printf "\e[37;1m%d/%d\e[0m tests with correct error.\n"    "$errok" "$tests"
