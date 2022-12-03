#include <cassert>
#include <iostream>
#include <string>
#include <tuple>

#include "organism.h"

using namespace std;
void org_test_0() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_1() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_2() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_3() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_4() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_5() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_6() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_7() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_8() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_9() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_10() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_11() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_12() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_13() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_14() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_15() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_16() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_17() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_18() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_19() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_20() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_21() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_22() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_23() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_24() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_25() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_26() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_27() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_28() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_29() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_30() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_31() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_32() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_33() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_34() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_35() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_36() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_37() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_38() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_39() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_40() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_41() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_42() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_43() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_44() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_45() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_46() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_47() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_48() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_49() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_50() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_51() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_52() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_53() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_54() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_55() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_56() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_57() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_58() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_59() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_60() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_61() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_62() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_63() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_64() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_65() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_66() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_67() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_68() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_69() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_70() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_71() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_72() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_73() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_74() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_75() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_76() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_77() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_78() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_79() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_80() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_81() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_82() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_83() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_84() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_85() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_86() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_87() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_88() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_89() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_90() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_91() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_92() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_93() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_94() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_95() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_96() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_97() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_98() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_99() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_100() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_101() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_102() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_103() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_104() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_105() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_106() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_107() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

int main() {
    org_test_0();
    org_test_1();
    org_test_2();
    org_test_3();
    org_test_4();
    org_test_5();
    org_test_6();
    org_test_7();
    org_test_8();
    org_test_9();
    org_test_10();
    org_test_11();
    org_test_12();
    org_test_13();
    org_test_14();
    org_test_15();
    org_test_16();
    org_test_17();
    org_test_18();
    org_test_19();
    org_test_20();
    org_test_21();
    org_test_22();
    org_test_23();
    org_test_24();
    org_test_25();
    org_test_26();
    org_test_27();
    org_test_28();
    org_test_29();
    org_test_30();
    org_test_31();
    org_test_32();
    org_test_33();
    org_test_34();
    org_test_35();
    org_test_36();
    org_test_37();
    org_test_38();
    org_test_39();
    org_test_40();
    org_test_41();
    org_test_42();
    org_test_43();
    org_test_44();
    org_test_45();
    org_test_46();
    org_test_47();
    org_test_48();
    org_test_49();
    org_test_50();
    org_test_51();
    org_test_52();
    org_test_53();
    org_test_54();
    org_test_55();
    org_test_56();
    org_test_57();
    org_test_58();
    org_test_59();
    org_test_60();
    org_test_61();
    org_test_62();
    org_test_63();
    org_test_64();
    org_test_65();
    org_test_66();
    org_test_67();
    org_test_68();
    org_test_69();
    org_test_70();
    org_test_71();
    org_test_72();
    org_test_73();
    org_test_74();
    org_test_75();
    org_test_76();
    org_test_77();
    org_test_78();
    org_test_79();
    org_test_80();
    org_test_81();
    org_test_82();
    org_test_83();
    org_test_84();
    org_test_85();
    org_test_86();
    org_test_87();
    org_test_88();
    org_test_89();
    org_test_90();
    org_test_91();
    org_test_92();
    org_test_93();
    org_test_94();
    org_test_95();
    org_test_96();
    org_test_97();
    org_test_98();
    org_test_99();
    org_test_100();
    org_test_101();
    org_test_102();
    org_test_103();
    org_test_104();
    org_test_105();
    org_test_106();
    org_test_107();
    return 0;
}
