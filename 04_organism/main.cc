#include <cassert>
#include <iostream>
#include <string>
#include <tuple>

#include "organism.h"

using namespace std;
void org_test_0() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_1() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_2() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_3() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_4() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_5() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_6() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_7() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_8() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_9() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_10() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_11() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_12() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_13() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_14() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_15() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_16() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_17() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_18() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_19() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_20() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_21() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_22() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_23() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_24() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_25() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_26() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_27() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_28() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_29() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_30() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_31() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_32() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_33() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_34() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_35() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_36() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_37() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_38() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_39() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_40() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_41() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_42() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_43() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_44() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_45() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_46() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_47() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_48() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_49() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_50() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_51() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_52() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_53() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_54() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_55() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_56() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_57() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_58() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_59() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_60() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_61() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_62() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_63() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_64() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_65() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_66() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_67() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_68() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_69() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_70() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_71() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_72() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_73() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_74() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_75() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_76() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_77() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_78() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_79() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_80() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_81() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_82() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_83() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_84() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_85() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_86() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_87() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_88() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_89() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_90() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_91() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_92() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_93() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_94() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_95() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_96() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_97() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_98() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_99() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_100() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_101() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_102() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_103() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_104() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_105() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_106() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_107() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_108() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_109() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_110() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_111() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_112() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_113() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_114() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_115() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_116() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_117() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_118() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_119() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_120() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_121() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_122() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_123() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_124() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_125() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_126() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_127() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_128() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_129() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_130() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_131() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_132() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_133() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_134() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_135() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_136() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_137() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_138() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_139() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_140() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_141() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_142() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_143() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_144() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_145() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_146() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_147() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_148() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_149() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_150() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_151() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_152() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_153() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_154() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_155() {
    Omnivore<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_156() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_157() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_158() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_159() {
    Omnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_160() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_161() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_162() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_163() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_164() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_165() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_166() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_167() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_168() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_169() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_170() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_171() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_172() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_173() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_174() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_175() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_176() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_177() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_178() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_179() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_180() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_181() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_182() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_183() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_184() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_185() {
    Omnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_186() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_187() {
    Omnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_188() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_189() {
    Omnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_190() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_191() {
    Omnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_192() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_193() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_194() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_195() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_196() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_197() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_198() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_199() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_200() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_201() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_202() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_203() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_204() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_205() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_206() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_207() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_208() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_209() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_210() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_211() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_212() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_213() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_214() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_215() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_216() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_217() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_218() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_219() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_220() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_221() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_222() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_223() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_224() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_225() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_226() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_227() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_228() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_229() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_230() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_231() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_232() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_233() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_234() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_235() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_236() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_237() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_238() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_239() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_240() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_241() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_242() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_243() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_244() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_245() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_246() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_247() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_248() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_249() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_250() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_251() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_252() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_253() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_254() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_255() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_256() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_257() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_258() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_259() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_260() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_261() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_262() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_263() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_264() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_265() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_266() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_267() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_268() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_269() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_270() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_271() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_272() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_273() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_274() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_275() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_276() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_277() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_278() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_279() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_280() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_281() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_282() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_283() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_284() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_285() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_286() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_287() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_288() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_289() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_290() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_291() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_292() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_293() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_294() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_295() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_296() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_297() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_298() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_299() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_300() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_301() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_302() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_303() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_304() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_305() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_306() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_307() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_308() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_309() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_310() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_311() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_312() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_313() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_314() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_315() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_316() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_317() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_318() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_319() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_320() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_321() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_322() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_323() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_324() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_325() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_326() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_327() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_328() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_329() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_330() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_331() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_332() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_333() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_334() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_335() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 100);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_336() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_337() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_338() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_339() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_340() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_341() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_342() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_343() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_344() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_345() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_346() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_347() {
    Herbivore<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_348() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_349() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_350() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_351() {
    Herbivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_352() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_353() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_354() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_355() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_356() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_357() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_358() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_359() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_360() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_361() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_362() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_363() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_364() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_365() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_366() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_367() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_368() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_369() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_370() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_371() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_372() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_373() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_374() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_375() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_376() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_377() {
    Herbivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_378() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_379() {
    Herbivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_380() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_381() {
    Herbivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_382() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_383() {
    Herbivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_384() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_385() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_386() {
    Plant<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_387() {
    Plant<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_388() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_389() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_390() {
    Plant<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_391() {
    Plant<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_392() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_393() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_394() {
    Plant<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_395() {
    Plant<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_396() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_397() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_398() {
    Plant<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_399() {
    Plant<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_400() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_401() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_402() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_403() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_404() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_405() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_406() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_407() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_408() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_409() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_410() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_411() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_412() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_413() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_414() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_415() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_416() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_417() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_418() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_419() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_420() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_421() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_422() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_423() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_424() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_425() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_426() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_427() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_428() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_429() {
    Plant<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_430() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_431() {
    Plant<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_432() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_433() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_434() {
    Plant<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_435() {
    Plant<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_436() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_437() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_438() {
    Plant<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_439() {
    Plant<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_440() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_441() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_442() {
    Plant<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_443() {
    Plant<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_444() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_445() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_446() {
    Plant<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_447() {
    Plant<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_448() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_449() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_450() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_451() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_452() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_453() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_454() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_455() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_456() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_457() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_458() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_459() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_460() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_461() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_462() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_463() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_464() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_465() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_466() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_467() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_468() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_469() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_470() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_471() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_472() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_473() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_474() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_475() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_476() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_477() {
    Plant<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_478() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_479() {
    Plant<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 100);
    assert(!std::get<2>(enc).has_value());
}

void org_test_480() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_481() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_482() {
    Plant<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_483() {
    Plant<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_484() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_485() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_486() {
    Plant<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_487() {
    Plant<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_488() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_489() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_490() {
    Plant<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_491() {
    Plant<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_492() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_493() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_494() {
    Plant<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_495() {
    Plant<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_496() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_497() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_498() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_499() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_500() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_501() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_502() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_503() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_504() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_505() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_506() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_507() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_508() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_509() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_510() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_511() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_512() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_513() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_514() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_515() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_516() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_517() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_518() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_519() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_520() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_521() {
    Plant<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_522() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_523() {
    Plant<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_524() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_525() {
    Plant<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_526() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_527() {
    Plant<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_528() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_529() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_530() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_531() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_532() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_533() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_534() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_535() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_536() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_537() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_538() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_539() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_540() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_541() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_542() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_543() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_544() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_545() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_546() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_547() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_548() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_549() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_550() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_551() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_552() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_553() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_554() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_555() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_556() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_557() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_558() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_559() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_560() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_561() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_562() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_563() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_564() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_565() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_566() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_567() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_568() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_569() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_570() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_571() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Omnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_572() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_573() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_574() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_575() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Omnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_576() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_577() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_578() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_579() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_580() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_581() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_582() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_583() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_584() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_585() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_586() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_587() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_588() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_589() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_590() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_591() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_592() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_593() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_594() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_595() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_596() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_597() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_598() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_599() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_600() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_601() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_602() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_603() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_604() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_605() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_606() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_607() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_608() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_609() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_610() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_611() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_612() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_613() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_614() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_615() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_616() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_617() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_618() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_619() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Herbivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_620() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_621() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_622() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_623() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Herbivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_624() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_625() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_626() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_627() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_628() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_629() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_630() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_631() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_632() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_633() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_634() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_635() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_636() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_637() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_638() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_639() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_640() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_641() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_642() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_643() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_644() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_645() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_646() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_647() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_648() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_649() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_650() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_651() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_652() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_653() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_654() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_655() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_656() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_657() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_658() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_659() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_660() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_661() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_662() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_663() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_664() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_665() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_666() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_667() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Plant<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_668() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_669() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Plant<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_670() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_671() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Plant<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_672() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_673() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_674() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_675() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_676() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_677() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_678() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_679() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_680() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_681() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_682() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_683() {
    Carnivore<string> o1 = {"Tyranozaur", 60};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_684() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_685() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_686() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 60);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_687() {
    Carnivore<string> o1 = {"Dinozaur", 60};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 80);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_688() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_689() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_690() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_691() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_692() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_693() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_694() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_695() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(std::get<2>(enc)->get_vitality() == 40);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_696() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_697() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_698() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_699() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_700() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_701() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 40);
    assert(!std::get<2>(enc).has_value());
}

void org_test_702() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_703() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 40};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_704() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_705() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_706() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_707() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_708() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_709() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_710() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_711() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(std::get<2>(enc)->get_vitality() == 50);
    assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_712() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_713() {
    Carnivore<string> o1 = {"Tyranozaur", 0};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_714() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_715() {
    Carnivore<string> o1 = {"Tyranozaur", 40};
    Carnivore<string> o2 = {"Dinozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 80);
    assert(!std::get<2>(enc).has_value());
}

void org_test_716() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_717() {
    Carnivore<string> o1 = {"Dinozaur", 0};
    Carnivore<string> o2 = {"Tyranozaur", 60};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 0);
    assert(std::get<1>(enc).get_vitality() == 60);
    assert(!std::get<2>(enc).has_value());
}

void org_test_718() {
    Carnivore<string> o1 = {"Dinozaur", 40};
    Carnivore<string> o2 = {"Tyranozaur", 0};

    auto enc = encounter(o1, o2);

    assert(std::get<0>(enc).get_vitality() == 40);
    assert(std::get<1>(enc).get_vitality() == 0);
    assert(!std::get<2>(enc).has_value());
}

void org_test_719() {
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
    org_test_108();
    org_test_109();
    org_test_110();
    org_test_111();
    org_test_112();
    org_test_113();
    org_test_114();
    org_test_115();
    org_test_116();
    org_test_117();
    org_test_118();
    org_test_119();
    org_test_120();
    org_test_121();
    org_test_122();
    org_test_123();
    org_test_124();
    org_test_125();
    org_test_126();
    org_test_127();
    org_test_128();
    org_test_129();
    org_test_130();
    org_test_131();
    org_test_132();
    org_test_133();
    org_test_134();
    org_test_135();
    org_test_136();
    org_test_137();
    org_test_138();
    org_test_139();
    org_test_140();
    org_test_141();
    org_test_142();
    org_test_143();
    org_test_144();
    org_test_145();
    org_test_146();
    org_test_147();
    org_test_148();
    org_test_149();
    org_test_150();
    org_test_151();
    org_test_152();
    org_test_153();
    org_test_154();
    org_test_155();
    org_test_156();
    org_test_157();
    org_test_158();
    org_test_159();
    org_test_160();
    org_test_161();
    org_test_162();
    org_test_163();
    org_test_164();
    org_test_165();
    org_test_166();
    org_test_167();
    org_test_168();
    org_test_169();
    org_test_170();
    org_test_171();
    org_test_172();
    org_test_173();
    org_test_174();
    org_test_175();
    org_test_176();
    org_test_177();
    org_test_178();
    org_test_179();
    org_test_180();
    org_test_181();
    org_test_182();
    org_test_183();
    org_test_184();
    org_test_185();
    org_test_186();
    org_test_187();
    org_test_188();
    org_test_189();
    org_test_190();
    org_test_191();
    org_test_192();
    org_test_193();
    org_test_194();
    org_test_195();
    org_test_196();
    org_test_197();
    org_test_198();
    org_test_199();
    org_test_200();
    org_test_201();
    org_test_202();
    org_test_203();
    org_test_204();
    org_test_205();
    org_test_206();
    org_test_207();
    org_test_208();
    org_test_209();
    org_test_210();
    org_test_211();
    org_test_212();
    org_test_213();
    org_test_214();
    org_test_215();
    org_test_216();
    org_test_217();
    org_test_218();
    org_test_219();
    org_test_220();
    org_test_221();
    org_test_222();
    org_test_223();
    org_test_224();
    org_test_225();
    org_test_226();
    org_test_227();
    org_test_228();
    org_test_229();
    org_test_230();
    org_test_231();
    org_test_232();
    org_test_233();
    org_test_234();
    org_test_235();
    org_test_236();
    org_test_237();
    org_test_238();
    org_test_239();
    org_test_240();
    org_test_241();
    org_test_242();
    org_test_243();
    org_test_244();
    org_test_245();
    org_test_246();
    org_test_247();
    org_test_248();
    org_test_249();
    org_test_250();
    org_test_251();
    org_test_252();
    org_test_253();
    org_test_254();
    org_test_255();
    org_test_256();
    org_test_257();
    org_test_258();
    org_test_259();
    org_test_260();
    org_test_261();
    org_test_262();
    org_test_263();
    org_test_264();
    org_test_265();
    org_test_266();
    org_test_267();
    org_test_268();
    org_test_269();
    org_test_270();
    org_test_271();
    org_test_272();
    org_test_273();
    org_test_274();
    org_test_275();
    org_test_276();
    org_test_277();
    org_test_278();
    org_test_279();
    org_test_280();
    org_test_281();
    org_test_282();
    org_test_283();
    org_test_284();
    org_test_285();
    org_test_286();
    org_test_287();
    org_test_288();
    org_test_289();
    org_test_290();
    org_test_291();
    org_test_292();
    org_test_293();
    org_test_294();
    org_test_295();
    org_test_296();
    org_test_297();
    org_test_298();
    org_test_299();
    org_test_300();
    org_test_301();
    org_test_302();
    org_test_303();
    org_test_304();
    org_test_305();
    org_test_306();
    org_test_307();
    org_test_308();
    org_test_309();
    org_test_310();
    org_test_311();
    org_test_312();
    org_test_313();
    org_test_314();
    org_test_315();
    org_test_316();
    org_test_317();
    org_test_318();
    org_test_319();
    org_test_320();
    org_test_321();
    org_test_322();
    org_test_323();
    org_test_324();
    org_test_325();
    org_test_326();
    org_test_327();
    org_test_328();
    org_test_329();
    org_test_330();
    org_test_331();
    org_test_332();
    org_test_333();
    org_test_334();
    org_test_335();
    org_test_336();
    org_test_337();
    org_test_338();
    org_test_339();
    org_test_340();
    org_test_341();
    org_test_342();
    org_test_343();
    org_test_344();
    org_test_345();
    org_test_346();
    org_test_347();
    org_test_348();
    org_test_349();
    org_test_350();
    org_test_351();
    org_test_352();
    org_test_353();
    org_test_354();
    org_test_355();
    org_test_356();
    org_test_357();
    org_test_358();
    org_test_359();
    org_test_360();
    org_test_361();
    org_test_362();
    org_test_363();
    org_test_364();
    org_test_365();
    org_test_366();
    org_test_367();
    org_test_368();
    org_test_369();
    org_test_370();
    org_test_371();
    org_test_372();
    org_test_373();
    org_test_374();
    org_test_375();
    org_test_376();
    org_test_377();
    org_test_378();
    org_test_379();
    org_test_380();
    org_test_381();
    org_test_382();
    org_test_383();
    org_test_384();
    org_test_385();
    org_test_386();
    org_test_387();
    org_test_388();
    org_test_389();
    org_test_390();
    org_test_391();
    org_test_392();
    org_test_393();
    org_test_394();
    org_test_395();
    org_test_396();
    org_test_397();
    org_test_398();
    org_test_399();
    org_test_400();
    org_test_401();
    org_test_402();
    org_test_403();
    org_test_404();
    org_test_405();
    org_test_406();
    org_test_407();
    org_test_408();
    org_test_409();
    org_test_410();
    org_test_411();
    org_test_412();
    org_test_413();
    org_test_414();
    org_test_415();
    org_test_416();
    org_test_417();
    org_test_418();
    org_test_419();
    org_test_420();
    org_test_421();
    org_test_422();
    org_test_423();
    org_test_424();
    org_test_425();
    org_test_426();
    org_test_427();
    org_test_428();
    org_test_429();
    org_test_430();
    org_test_431();
    org_test_432();
    org_test_433();
    org_test_434();
    org_test_435();
    org_test_436();
    org_test_437();
    org_test_438();
    org_test_439();
    org_test_440();
    org_test_441();
    org_test_442();
    org_test_443();
    org_test_444();
    org_test_445();
    org_test_446();
    org_test_447();
    org_test_448();
    org_test_449();
    org_test_450();
    org_test_451();
    org_test_452();
    org_test_453();
    org_test_454();
    org_test_455();
    org_test_456();
    org_test_457();
    org_test_458();
    org_test_459();
    org_test_460();
    org_test_461();
    org_test_462();
    org_test_463();
    org_test_464();
    org_test_465();
    org_test_466();
    org_test_467();
    org_test_468();
    org_test_469();
    org_test_470();
    org_test_471();
    org_test_472();
    org_test_473();
    org_test_474();
    org_test_475();
    org_test_476();
    org_test_477();
    org_test_478();
    org_test_479();
    org_test_480();
    org_test_481();
    org_test_482();
    org_test_483();
    org_test_484();
    org_test_485();
    org_test_486();
    org_test_487();
    org_test_488();
    org_test_489();
    org_test_490();
    org_test_491();
    org_test_492();
    org_test_493();
    org_test_494();
    org_test_495();
    org_test_496();
    org_test_497();
    org_test_498();
    org_test_499();
    org_test_500();
    org_test_501();
    org_test_502();
    org_test_503();
    org_test_504();
    org_test_505();
    org_test_506();
    org_test_507();
    org_test_508();
    org_test_509();
    org_test_510();
    org_test_511();
    org_test_512();
    org_test_513();
    org_test_514();
    org_test_515();
    org_test_516();
    org_test_517();
    org_test_518();
    org_test_519();
    org_test_520();
    org_test_521();
    org_test_522();
    org_test_523();
    org_test_524();
    org_test_525();
    org_test_526();
    org_test_527();
    org_test_528();
    org_test_529();
    org_test_530();
    org_test_531();
    org_test_532();
    org_test_533();
    org_test_534();
    org_test_535();
    org_test_536();
    org_test_537();
    org_test_538();
    org_test_539();
    org_test_540();
    org_test_541();
    org_test_542();
    org_test_543();
    org_test_544();
    org_test_545();
    org_test_546();
    org_test_547();
    org_test_548();
    org_test_549();
    org_test_550();
    org_test_551();
    org_test_552();
    org_test_553();
    org_test_554();
    org_test_555();
    org_test_556();
    org_test_557();
    org_test_558();
    org_test_559();
    org_test_560();
    org_test_561();
    org_test_562();
    org_test_563();
    org_test_564();
    org_test_565();
    org_test_566();
    org_test_567();
    org_test_568();
    org_test_569();
    org_test_570();
    org_test_571();
    org_test_572();
    org_test_573();
    org_test_574();
    org_test_575();
    org_test_576();
    org_test_577();
    org_test_578();
    org_test_579();
    org_test_580();
    org_test_581();
    org_test_582();
    org_test_583();
    org_test_584();
    org_test_585();
    org_test_586();
    org_test_587();
    org_test_588();
    org_test_589();
    org_test_590();
    org_test_591();
    org_test_592();
    org_test_593();
    org_test_594();
    org_test_595();
    org_test_596();
    org_test_597();
    org_test_598();
    org_test_599();
    org_test_600();
    org_test_601();
    org_test_602();
    org_test_603();
    org_test_604();
    org_test_605();
    org_test_606();
    org_test_607();
    org_test_608();
    org_test_609();
    org_test_610();
    org_test_611();
    org_test_612();
    org_test_613();
    org_test_614();
    org_test_615();
    org_test_616();
    org_test_617();
    org_test_618();
    org_test_619();
    org_test_620();
    org_test_621();
    org_test_622();
    org_test_623();
    org_test_624();
    org_test_625();
    org_test_626();
    org_test_627();
    org_test_628();
    org_test_629();
    org_test_630();
    org_test_631();
    org_test_632();
    org_test_633();
    org_test_634();
    org_test_635();
    org_test_636();
    org_test_637();
    org_test_638();
    org_test_639();
    org_test_640();
    org_test_641();
    org_test_642();
    org_test_643();
    org_test_644();
    org_test_645();
    org_test_646();
    org_test_647();
    org_test_648();
    org_test_649();
    org_test_650();
    org_test_651();
    org_test_652();
    org_test_653();
    org_test_654();
    org_test_655();
    org_test_656();
    org_test_657();
    org_test_658();
    org_test_659();
    org_test_660();
    org_test_661();
    org_test_662();
    org_test_663();
    org_test_664();
    org_test_665();
    org_test_666();
    org_test_667();
    org_test_668();
    org_test_669();
    org_test_670();
    org_test_671();
    org_test_672();
    org_test_673();
    org_test_674();
    org_test_675();
    org_test_676();
    org_test_677();
    org_test_678();
    org_test_679();
    org_test_680();
    org_test_681();
    org_test_682();
    org_test_683();
    org_test_684();
    org_test_685();
    org_test_686();
    org_test_687();
    org_test_688();
    org_test_689();
    org_test_690();
    org_test_691();
    org_test_692();
    org_test_693();
    org_test_694();
    org_test_695();
    org_test_696();
    org_test_697();
    org_test_698();
    org_test_699();
    org_test_700();
    org_test_701();
    org_test_702();
    org_test_703();
    org_test_704();
    org_test_705();
    org_test_706();
    org_test_707();
    org_test_708();
    org_test_709();
    org_test_710();
    org_test_711();
    org_test_712();
    org_test_713();
    org_test_714();
    org_test_715();
    org_test_716();
    org_test_717();
    org_test_718();
    org_test_719();
    return 0;
}

