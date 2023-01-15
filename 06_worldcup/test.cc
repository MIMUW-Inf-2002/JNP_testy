#include <sstream>
#include <memory>
#include <string>
#include <cassert>
#include <iostream>
#include <string>
#include "tests.h"

std::string const CYAN = "\033[1;36m";

int main() {
    tooFewDiceTest();
    tooManyDiceTest();
    tooFewPlayersTest();
    tooManyPlayersTest();
    resultsTestOne();
    resultTestTwo();
    resultTestThree();
    fractionsTest();
    bankruptTest();
    std::cout << CYAN << "All tests passed succesfully\n" << RESET;
}