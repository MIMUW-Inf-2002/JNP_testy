// Authors: Antoni Stachowski, Michał Kostyk
// Date: 2023-01-15
// Description: Testy dla WorldCup2022
// License: Do What The Fuck You Want To Public License (WTFPL)

#ifndef TEST_DICE_H
#define TEST_DICE_H

#include "worldcup.h"

class SnakeEyeDie : public Die {
    [[nodiscard]] unsigned short roll() const override {
        return 1;
    }
};

class PopeDie : public Die {
    private:
        static constexpr unsigned short papiesh[4] = {2, 1, 3, 7};
        std::shared_ptr<unsigned long> rollNum;
    public :
        PopeDie () : Die() {
            rollNum = std::make_shared<unsigned long>(0);
        }


    [[nodiscard]] unsigned short roll() const override {
        unsigned short out = papiesh[*rollNum];
        (*rollNum)++;
        (*rollNum) %= 4;
        return out;
    }
};

class MatthewDie : public Die {
    private:
        static constexpr unsigned short rolls[9] = {6, 6, 5, 6, 5, 6, 5, 5, 6};
        std::shared_ptr<unsigned long> rollNum;
    public :
        MatthewDie () : Die() {
            rollNum = std::make_shared<unsigned long>(0);
        }



    [[nodiscard]] unsigned short roll() const override {
        unsigned short out = rolls[*rollNum];
        (*rollNum)++;
        (*rollNum) %= 9;
        return out;
    }
};

class WeirdlySpecificDie : public Die {
    private:
        static constexpr unsigned short rolls[12] = {3, 4, 2, 1, 2, 1, 4, 3, 3, 1, 1, 5};
        std::shared_ptr<unsigned long> rollNum;
    public :
        WeirdlySpecificDie () : Die() {
            rollNum = std::make_shared<unsigned long>(0);
        }



    [[nodiscard]] unsigned short roll() const override {
        unsigned short out = rolls[*rollNum];
        (*rollNum)++;
        (*rollNum) %= 12;
        return out;
    }
};

class EvenMoreSpecificDie : public Die {
    private:
        static constexpr unsigned short rolls[19] = {4, 1, 2, 4, 4, 2, 15, 6, 1, 5, 6, 1, 8, 1, 1, 11, 3, 1, 1};
        std::shared_ptr<unsigned long> rollNum;
    public :
        EvenMoreSpecificDie () : Die() {
            rollNum = std::make_shared<unsigned long>(0);
        }

        [[nodiscard]] unsigned short roll() const override {
            unsigned short out = rolls[*rollNum];
            (*rollNum)++;
            (*rollNum) %= 19;
            return out;
        }
};

class ZeroDie : public Die {
    [[nodiscard]] unsigned short roll() const override {
        return 0;
    }
};

class YouProbablyShouldBeginToWorryAboutHowSpecificTheseDiceAreDie : public Die {
    private:
        static constexpr unsigned short rolls[10] = {1, 0, 5, 0, 1, 0, 1, 0, 3, 30};
        std::shared_ptr<unsigned long> rollNum;
    public :
        YouProbablyShouldBeginToWorryAboutHowSpecificTheseDiceAreDie () : Die() {
            rollNum = std::make_shared<unsigned long>(0);
        }

        [[nodiscard]] unsigned short roll() const override {
            unsigned short out = rolls[*rollNum];
            (*rollNum)++;
            (*rollNum) %= 10;
            return out;
        }
};

#endif
