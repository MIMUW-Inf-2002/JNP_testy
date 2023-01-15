// Authors: Antoni Stachowski, Michał Kostyk
// Date: 2023-01-15
// Description: Testy dla WorldCup2022
// License: Do What The Fuck You Want To Public License (WTFPL)

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class TextScoreBoard : public ScoreBoard {
    std::stringstream info;
public:
    void onRound(unsigned int roundNo) override {
        info << "=== Runda: " << roundNo << "\n";
    }

    void onTurn(std::string const &playerName, std::string const &status,
                std::string const &currentSquareName, unsigned int money) override {
        info << playerName << " [" << status << "] [" << money << "] - " << currentSquareName << "\n";
    }

    void onWin(const std::string &playerName) override {
        info << "=== Zwycięzca: " << playerName << "\n";
    }

    std::string str() {
        return info.str();
    }
};

#endif
