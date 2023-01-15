// Authors: Antoni Stachowski, Michał Kostyk
// Date: 2023-01-15
// Description: Testy dla WorldCup2022
// License: Do What The Fuck You Want To Public License (WTFPL)

#ifndef TESTS_H
#define TESTS_H

#include <sstream>
#include <memory>
#include <string>
#include <cassert>
#include "worldcup2022.h"
#include <iostream>
#include "scoreboard.h"
#include "test_dice.h"
#include "regex"

std::string const RED = "\033[1;31m";
std::string const GREEN = "\033[1;32m";
std::string const RESET = "\033[0m";

// Testuje wyjątek rzucany przez WorldCup2022::play() gdy liczba kostek jest mniejsza niż 2
void tooFewDiceTest () {
    std::shared_ptr<Die> die1 = std::make_shared<SnakeEyeDie>();

    std::cout << RESET << "Too few dice test running\n" << RESET;

    std::shared_ptr<TextScoreBoard> scoreboard = std::make_shared<TextScoreBoard>();

    std::shared_ptr<WorldCup> worldCup2022 = std::make_shared<WorldCup2022>();
    worldCup2022->addDie(die1);
    worldCup2022->addPlayer("Asterix");
    worldCup2022->addPlayer("Obelix");
    worldCup2022->setScoreBoard(scoreboard);

    bool passed = false;

    try {
        worldCup2022->play(1);
    } catch (std::exception& e) {
        passed = true;
    }

    std::cerr << RED;
    assert(passed);

    std::cout << GREEN << "Too few dice test passed\n\n" << RESET;

}

// Testuje wyjątek rzucany przez WorldCup2022::play() gdy liczba kostek jest większa niż 2
void tooManyDiceTest () {
    std::shared_ptr<Die> die1 = std::make_shared<SnakeEyeDie>();
    std::shared_ptr<Die> die2 = std::make_shared<PopeDie>();
    std::shared_ptr<Die> die3 = std::make_shared<MatthewDie>();

    std::cout << RESET << "Too many dice test running\n" << RESET;

    std::shared_ptr<TextScoreBoard> scoreboard = std::make_shared<TextScoreBoard>();

    std::shared_ptr<WorldCup> worldCup2022 = std::make_shared<WorldCup2022>();
    worldCup2022->addPlayer("Asterix");
    worldCup2022->addPlayer("Obelix");
    worldCup2022->setScoreBoard(scoreboard);

    bool passed = false;

    try {
        worldCup2022->addDie(die1);
        worldCup2022->addDie(die2);
        worldCup2022->addDie(die3);
        worldCup2022->play(1);
    } catch (std::exception& e) {
        passed = true;
    }

    std::cerr << RED;
    assert(passed);

    std::cout << GREEN << "Too many dice test passed\n\n" << RESET;

}

// Testuje wyjątek rzucany przez WorldCup2022::play() gdy liczba graczy jest mniejsza niż 2
void tooFewPlayersTest() {
    std::shared_ptr<Die> die1 = std::make_shared<SnakeEyeDie>();
    std::shared_ptr<Die> die2 = std::make_shared<SnakeEyeDie>();

    std::cout << RESET << "Too few players test running\n" << RESET;

    std::shared_ptr<TextScoreBoard> scoreboard = std::make_shared<TextScoreBoard>();

    std::shared_ptr<WorldCup> worldCup2022 = std::make_shared<WorldCup2022>();
    worldCup2022->addDie(die1);
    worldCup2022->addDie(die2);
    worldCup2022->addPlayer("Gollum");
    worldCup2022->setScoreBoard(scoreboard);

    bool passed = false;

    try {
        worldCup2022->play(1);
    } catch (std::exception& e) {
        passed = true;
    }

    std::cerr << RED;
    assert(passed);

    std::cout << GREEN << "Too few players test passed\n\n" << RESET;

}

// Testuje wyjątek rzucany przez WorldCup2022::play() gdy liczba graczy jest większa niż 11
void tooManyPlayersTest() {
    std::shared_ptr<Die> die1 = std::make_shared<SnakeEyeDie>();
    std::shared_ptr<Die> die2 = std::make_shared<SnakeEyeDie>();

    std::cout << RESET << "Too many players test running\n" << RESET;

    std::shared_ptr<TextScoreBoard> scoreboard = std::make_shared<TextScoreBoard>();

    std::shared_ptr<WorldCup> worldCup2022 = std::make_shared<WorldCup2022>();
    worldCup2022->addDie(die1);
    worldCup2022->addDie(die2);
    worldCup2022->setScoreBoard(scoreboard);

    bool passed = false;

    try {
        worldCup2022->play(1);
        worldCup2022->addPlayer("Thorin");
        worldCup2022->addPlayer("Balin");
        worldCup2022->addPlayer("Dwalin");
        worldCup2022->addPlayer("Bifur");
        worldCup2022->addPlayer("Bofur");
        worldCup2022->addPlayer("Bombur");
        worldCup2022->addPlayer("Oin");
        worldCup2022->addPlayer("Gloin");
        worldCup2022->addPlayer("Dori");
        worldCup2022->addPlayer("Nori");
        worldCup2022->addPlayer("Ori");
        worldCup2022->addPlayer("Filli");
        worldCup2022->addPlayer("Killi");
    } catch (std::exception& e) {
        passed = true;
    }

    std::cerr << RED;
    assert(passed);

    std::cout << GREEN << "Too many players test passed\n\n" << RESET;

}

// Prosty test poprawnościowy.
void resultsTestOne() {
    std::cout << RESET << "Results test 1 running\n" << RESET;

    std::shared_ptr<Die> die1 = std::make_shared<MatthewDie>();
    std::shared_ptr<Die> die2 = std::make_shared<PopeDie>();

    std::shared_ptr<TextScoreBoard> scoreboard = std::make_shared<TextScoreBoard>();

    std::shared_ptr<WorldCup> worldCup2022 = std::make_shared<WorldCup2022>();
    worldCup2022->addDie(die1);
    worldCup2022->addDie(die2);
    worldCup2022->addPlayer("Bitek");
    worldCup2022->addPlayer("Bajtek");
    worldCup2022->setScoreBoard(scoreboard);

    worldCup2022->play(6);

    std::cerr << RED;
    assert(scoreboard->str() ==
           "=== Runda: 0\n"
           "Bitek [w grze] [40] - Mecz z Argentyną\n"
           "Bajtek [w grze] [140] - Bukmacher\n"
           "=== Runda: 1\n"
           "Bitek [*** bankrut ***] [0] - Żółta kartka\n"
           "=== Zwycięzca: Bajtek\n");

    std::cout << GREEN << "Results test 1 passed\n\n" << RESET;
}

// Prosty test poprawnościowy.
void resultTestTwo() {
    std::cout << RESET << "Results test 2 running\n" << RESET;

    std::shared_ptr<Die> die1 = std::make_shared<SnakeEyeDie>();
    std::shared_ptr<Die> die2 = std::make_shared<PopeDie>();

    std::shared_ptr<TextScoreBoard> scoreboard = std::make_shared<TextScoreBoard>();

    std::shared_ptr<WorldCup> worldCup2022 = std::make_shared<WorldCup2022>();
    worldCup2022->addDie(die1);
    worldCup2022->addDie(die2);
    worldCup2022->addPlayer("Andrew Tate");
    worldCup2022->addPlayer("Greta Thunberg");
    worldCup2022->setScoreBoard(scoreboard);

    worldCup2022->play(6);

    const std::regex RoundOne("^=== Runda: 0\nAndrew Tate \\[w grze] \\[840] - Mecz z Lie?chtensteinem\nGreta Thunberg \\[w grze] \\[840] - Dzień wolny od treningu\n(.*\n)*$");
    const std::regex RoundTwo("^(.*\n)*=== Runda: 1\nAndrew Tate \\[w grze] \\[360] - Bukmacher\nGreta Thunberg \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Mecz z Francją\n(.*\n)*$");

    std::cerr << RED;
    assert (std::regex_match(scoreboard->str(), RoundOne));
    assert (std::regex_match(scoreboard->str(), RoundTwo));

    std::cout << GREEN << "Results test 2 passed\n\n" << RESET;

}

// Dłuższy test poprawnościowy - 5 rund.
void resultTestThree() {
    std::cout << RESET << "Results test 3 running\n" << RESET;

    std::shared_ptr<Die> die1 = std::make_shared<SnakeEyeDie>();
    std::shared_ptr<Die> die2 = std::make_shared<WeirdlySpecificDie>();

    std::shared_ptr<TextScoreBoard> scoreboard = std::make_shared<TextScoreBoard>();

    std::shared_ptr<WorldCup> worldCup2022 = std::make_shared<WorldCup2022>();
    worldCup2022->addDie(die1);
    worldCup2022->addDie(die2);
    worldCup2022->addPlayer("Kleofas");
    worldCup2022->addPlayer("Ildefons");
    worldCup2022->addPlayer("Godehard");
    worldCup2022->setScoreBoard(scoreboard);

    worldCup2022->play(5);

    const std::regex RoundOne("^=== Runda: 0\nKleofas \\[\\*\\*\\* czekanie: 3 \\*\\*\\*] \\[620] - Żółta kartka\nIldefons \\[w grze] \\[620] - Mecz z Meksykiem\nGodehard \\[w grze] \\[1280] - Mecz z Lie?chtensteinem\n(.*\n)*$");
    const std::regex RoundTwo("^(.*\n)*=== Runda: 1\nKleofas \\[\\*\\*\\* czekanie: 2 \\*\\*\\*] \\[620] - Żółta kartka\nIldefons \\[w grze] \\[440] - Bukmacher\nGodehard \\[w grze] \\[1680] - Mecz z Arabią Saudyjską\n(.*\n)*$");
    const std::regex RoundThree("^(.*\n)*=== Runda: 2\nKleofas \\[\\*\\*\\* czekanie: 1 \\*\\*\\*] \\[620] - Żółta kartka\nIldefons \\[w grze] \\[310] - Gol\nGodehard \\[w grze] \\[850] - Rzut karny\n(.*\n)*$");
    const std::regex RoundFour("^(.*\n)*=== Runda: 3\nKleofas \\[w grze] \\[1290] - Mecz z Argentyną\nIldefons \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Mecz z San Marino\nGodehard \\[w grze] \\[1380] - Mecz z San Marino\n(.*\n)*$");
    const std::regex RoundFive("^(.*\n)*=== Runda: 4\nKleofas \\[w grze] \\[4130] - Mecz z Francją\nGodehard \\[w grze] \\[480] - Bukmacher\n=== Zwycięzca: Kleofas\\s*$");
    
    const std::regex RoundFiveWithBankrupt("^(.*\n)*=== Runda: 4\nKleofas \\[w grze] \\[4130] - Mecz z Francją\nIldefons \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Mecz z San Marino\nGodehard \\[w grze] \\[480] - Bukmacher\n=== Zwycięzca: Kleofas\\s*$");
    
    std::cerr << RED;
    assert (std::regex_match(scoreboard->str(), RoundOne));
    assert (std::regex_match(scoreboard->str(), RoundTwo));
    assert (std::regex_match(scoreboard->str(), RoundThree));
    assert (std::regex_match(scoreboard->str(), RoundFour));
    assert (std::regex_match(scoreboard->str(), RoundFive) ||
            std::regex_match(scoreboard->str(), RoundFiveWithBankrupt));

    std::cout << GREEN << "Results test 3 passed\n\n" << RESET;

}

// Test poprawnej obsługi ułamków w wynikach. Przy okazji też kolejny
// test poprawnościowy z 5 rundami.
void fractionsTest() {
    std::cout << RESET << "Fractions test running\n" << RESET;

    std::shared_ptr<Die> die1 = std::make_shared<EvenMoreSpecificDie>();
    std::shared_ptr<Die> die2 = std::make_shared<ZeroDie>();

    std::shared_ptr<TextScoreBoard> scoreboard = std::make_shared<TextScoreBoard>();

    std::shared_ptr<WorldCup> worldCup2022 = std::make_shared<WorldCup2022>();
    worldCup2022->addDie(die1);
    worldCup2022->addDie(die2);
    worldCup2022->addPlayer("Hamilton");
    worldCup2022->addPlayer("Jefferson");
    worldCup2022->addPlayer("Burr");
    worldCup2022->addPlayer("Lafaeyette");
    worldCup2022->addPlayer("King George III");
    worldCup2022->addPlayer("Eliza");

    worldCup2022->setScoreBoard(scoreboard);

    worldCup2022->play(5);

    const std::regex RoundOne("^=== Runda: 0\nHamilton \\[\\*\\*\\* czekanie: 3 \\*\\*\\*] \\[620] - Żółta kartka\nJefferson \\[w grze] \\[1160] - Mecz z San Marino\nBurr \\[w grze] \\[840] - Dzień wolny od treningu\nLafaeyette \\[\\*\\*\\* czekanie: 3 \\*\\*\\*] \\[620] - Żółta kartka\nKing George III \\[\\*\\*\\* czekanie: 3 \\*\\*\\*] \\[620] - Żółta kartka\nEliza \\[w grze] \\[840] - Dzień wolny od treningu\n(.*\n)*$");
    const std::regex RoundTwo("^(.*\n)*=== Runda: 1\nHamilton \\[\\*\\*\\* czekanie: 2 \\*\\*\\*] \\[620] - Żółta kartka\nJefferson \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Żółta kartka\nBurr \\[w grze] \\[665] - Mecz z Argentyną\nLafaeyette \\[\\*\\*\\* czekanie: 2 \\*\\*\\*] \\[620] - Żółta kartka\nKing George III \\[\\*\\*\\* czekanie: 2 \\*\\*\\*] \\[620] - Żółta kartka\nEliza \\[w grze] \\[1940] - Mecz z Lie?chtensteinem\n(.*\n)*$");
    const std::regex RoundThree("^(.*\n)*=== Runda: 2\nHamilton \\[\\*\\*\\* czekanie: 1 \\*\\*\\*] \\[620] - Żółta kartka\nBurr \\[w grze] \\[955] - Mecz z San Marino\nLafaeyette \\[\\*\\*\\* czekanie: 1 \\*\\*\\*] \\[620] - Żółta kartka\nKing George III \\[\\*\\*\\* czekanie: 1 \\*\\*\\*] \\[620] - Żółta kartka\nEliza \\[w grze] \\[1230] - Gol\n(.*\n)*$");
    const std::regex RoundFour("^(.*\n)*=== Runda: 3\nHamilton \\[w grze] \\[2870] - Mecz z Meksykiem\nBurr \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Gol\nLafaeyette \\[w grze] \\[1370] - Mecz z Meksykiem\nKing George III \\[w grze] \\[620] - Mecz z Meksykiem\nEliza \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Mecz z Argentyną\n(.*\n)*$");
    const std::regex RoundFive("^(.*\n)*=== Runda: 4\nHamilton \\[w grze] \\[3602] - Mecz z Argentyną\nLafaeyette \\[w grze] \\[5370] - Mecz z Arabią Saudyjską\nKing George III \\[w grze] \\[620] - Mecz z Arabią Saudyjską\n(.*\n)*$");

    const std::regex RoundThreeWithBankrupt("^(.*\n)*=== Runda: 2\nHamilton \\[\\*\\*\\* czekanie: 1 \\*\\*\\*] \\[620] - Żółta kartka\nJefferson \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Żółta kartka\nBurr \\[w grze] \\[955] - Mecz z San Marino\nLafaeyette \\[\\*\\*\\* czekanie: 1 \\*\\*\\*] \\[620] - Żółta kartka\nKing George III \\[\\*\\*\\* czekanie: 1 \\*\\*\\*] \\[620] - Żółta kartka\nEliza \\[w grze] \\[1230] - Gol\n(.*\n)*$");
    const std::regex RoundFourWithBankrupt("^(.*\n)*=== Runda: 3\nHamilton \\[w grze] \\[2870] - Mecz z Meksykiem\nJefferson \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Żółta kartka\nBurr \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Gol\nLafaeyette \\[w grze] \\[1370] - Mecz z Meksykiem\nKing George III \\[w grze] \\[620] - Mecz z Meksykiem\nEliza \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Mecz z Argentyną\n(.*\n)*$");
    const std::regex RoundFiveWithBankrupt("^(.*\n)*=== Runda: 4\nHamilton \\[w grze] \\[3602] - Mecz z Argentyną\nJefferson \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Żółta kartka\nBurr \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Gol\nLafaeyette \\[w grze] \\[5370] - Mecz z Arabią Saudyjską\nKing George III \\[w grze] \\[620] - Mecz z Arabią Saudyjską\nEliza \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Mecz z Argentyną\n(.*\n)*$");
    
    std::cerr << RED;
    assert (std::regex_match(scoreboard->str(), RoundOne));
    assert (std::regex_match(scoreboard->str(), RoundTwo));

    assert (std::regex_match(scoreboard->str(), RoundThree) ||
            std::regex_match(scoreboard->str(), RoundThreeWithBankrupt));

    assert (std::regex_match(scoreboard->str(), RoundFour) ||
            std::regex_match(scoreboard->str(), RoundFourWithBankrupt));

    assert (std::regex_match(scoreboard->str(), RoundFive) || 
            std::regex_match(scoreboard->str(), RoundFiveWithBankrupt));

    std::cout << GREEN << "Fractions test passed\n\n" << RESET;
}

// Jeśli mamy dokładnie 0 pieniędzy, to wciąż *technically*
// nie zbankrutowaliśmy i możemy grać dalej.
void bankruptTest() {
    std::cout << RESET << "Bankrupt test running\n" << RESET;

    std::shared_ptr<Die> die1 = std::make_shared<ZeroDie>();
    std::shared_ptr<Die> die2 = std::make_shared<YouProbablyShouldBeginToWorryAboutHowSpecificTheseDiceAreDie>();

    std::shared_ptr<TextScoreBoard> scoreboard = std::make_shared<TextScoreBoard>();

    std::shared_ptr<WorldCup> worldCup2022 = std::make_shared<WorldCup2022>();
    worldCup2022->addDie(die1);
    worldCup2022->addDie(die2);
    worldCup2022->addPlayer("Młoda Leokadia");
    worldCup2022->addPlayer("Oliwka Brazil");
    worldCup2022->setScoreBoard(scoreboard);

    worldCup2022->play(5);

    std::regex RoundOne("^(.*\n)*=== Runda: 0\nMłoda Leokadia \\[w grze\\] \\[1000\\] - Mecz z San Marino\nOliwka Brazil \\[w grze\\] \\[1050\\] - Początek sezonu\n(.*\n)*$");
    std::regex RoundTwo("^(.*\n)*=== Runda: 1\nMłoda Leokadia \\[w grze\\] \\[480\\] - Mecz z Arabią Saudyjską\nOliwka Brazil \\[w grze\\] \\[1100\\] - Początek sezonu\n(.*\n)*$");
    std::regex RoundThree("^(.*\n)*=== Runda: 2\nMłoda Leokadia \\[w grze\\] \\[580\\] - Bukmacher\nOliwka Brazil \\[w grze\\] \\[1150\\] - Początek sezonu\n(.*\n)*$");
    std::regex RoundFour("^(.*\n)*=== Runda: 3\nMłoda Leokadia \\[w grze\\] \\[580\\] - Mecz z Argentyną\nOliwka Brazil \\[w grze\\] \\[1200\\] - Początek sezonu\n(.*\n)*$");
    std::regex RoundFive("^(.*\n)*=== Runda: 4\nMłoda Leokadia \\[w grze\\] \\[0\\] - Rzut karny\nOliwka Brazil \\[\\*\\*\\* bankrut \\*\\*\\*\\] \\[0\\] - Mecz z Arabią Saudyjską\n(.*\n)*$");

    std::cerr << RED;
    assert (std::regex_match(scoreboard->str(), RoundOne));
    assert (std::regex_match(scoreboard->str(), RoundTwo));
    assert (std::regex_match(scoreboard->str(), RoundThree));
    assert (std::regex_match(scoreboard->str(), RoundFour));
    assert (std::regex_match(scoreboard->str(), RoundFive));

    std::cout << GREEN << "Bankrupt test ended\n" << RESET;
}


#endif