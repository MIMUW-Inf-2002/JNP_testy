#include "organism.h"
#include <cassert>
#include <iostream>
#include <string>
#include <tuple>

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
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_25() {
  Omnivore<string> o1 = {"Dinozaur", 60};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_26() {
  Omnivore<string> o1 = {"Tyranozaur", 60};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_27() {
  Omnivore<string> o1 = {"Dinozaur", 60};
  Plant<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_28() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_29() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_30() {
  Omnivore<string> o1 = {"Tyranozaur", 40};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_31() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_32() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_33() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_34() {
  Omnivore<string> o1 = {"Tyranozaur", 40};
  Plant<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_35() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_36() {
  Omnivore<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_37() {
  Omnivore<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_38() {
  Omnivore<string> o1 = {"Tyranozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_39() {
  Omnivore<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_40() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_41() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_42() {
  Omnivore<string> o1 = {"Tyranozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_43() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_44() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_45() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_46() {
  Omnivore<string> o1 = {"Tyranozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_47() {
  Omnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_48() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_49() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_50() {
  Herbivore<string> o1 = {"Tyranozaur", 60};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_51() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Omnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_52() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_53() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_54() {
  Herbivore<string> o1 = {"Tyranozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_55() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_56() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_57() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_58() {
  Herbivore<string> o1 = {"Tyranozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_59() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_60() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(std::get<2>(enc)->get_vitality() == 50);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_61() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(std::get<2>(enc)->get_vitality() == 50);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_62() {
  Herbivore<string> o1 = {"Tyranozaur", 60};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_63() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Herbivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_64() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(std::get<2>(enc)->get_vitality() == 40);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_65() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(std::get<2>(enc)->get_vitality() == 40);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_66() {
  Herbivore<string> o1 = {"Tyranozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_67() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_68() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(std::get<2>(enc)->get_vitality() == 50);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_69() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(std::get<2>(enc)->get_vitality() == 50);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_70() {
  Herbivore<string> o1 = {"Tyranozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_71() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_72() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_73() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_74() {
  Herbivore<string> o1 = {"Tyranozaur", 60};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_75() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Plant<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_76() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_77() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_78() {
  Herbivore<string> o1 = {"Tyranozaur", 40};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_79() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_80() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_81() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_82() {
  Herbivore<string> o1 = {"Tyranozaur", 40};
  Plant<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_83() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 100);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_84() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_85() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_86() {
  Herbivore<string> o1 = {"Tyranozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_87() {
  Herbivore<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_88() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_89() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_90() {
  Herbivore<string> o1 = {"Tyranozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_91() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_92() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_93() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_94() {
  Herbivore<string> o1 = {"Tyranozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_95() {
  Herbivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_96() {
  Plant<string> o1 = {"Dinozaur", 60};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_97() {
  Plant<string> o1 = {"Dinozaur", 60};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_98() {
  Plant<string> o1 = {"Tyranozaur", 60};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_99() {
  Plant<string> o1 = {"Dinozaur", 60};
  Omnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_100() {
  Plant<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_101() {
  Plant<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_102() {
  Plant<string> o1 = {"Tyranozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_103() {
  Plant<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_104() {
  Plant<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_105() {
  Plant<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_106() {
  Plant<string> o1 = {"Tyranozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_107() {
  Plant<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_108() {
  Plant<string> o1 = {"Dinozaur", 60};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_109() {
  Plant<string> o1 = {"Dinozaur", 60};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_110() {
  Plant<string> o1 = {"Tyranozaur", 60};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_111() {
  Plant<string> o1 = {"Dinozaur", 60};
  Herbivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_112() {
  Plant<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_113() {
  Plant<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_114() {
  Plant<string> o1 = {"Tyranozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_115() {
  Plant<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_116() {
  Plant<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_117() {
  Plant<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_118() {
  Plant<string> o1 = {"Tyranozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_119() {
  Plant<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 100);
  assert(!std::get<2>(enc).has_value());
}

void org_test_120() {
  Plant<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_121() {
  Plant<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_122() {
  Plant<string> o1 = {"Tyranozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_123() {
  Plant<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_124() {
  Plant<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_125() {
  Plant<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_126() {
  Plant<string> o1 = {"Tyranozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_127() {
  Plant<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_128() {
  Plant<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_129() {
  Plant<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_130() {
  Plant<string> o1 = {"Tyranozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_131() {
  Plant<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_132() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_133() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_134() {
  Carnivore<string> o1 = {"Tyranozaur", 60};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_135() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Omnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_136() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_137() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_138() {
  Carnivore<string> o1 = {"Tyranozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_139() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_140() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_141() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_142() {
  Carnivore<string> o1 = {"Tyranozaur", 40};
  Omnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_143() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Omnivore<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_144() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_145() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_146() {
  Carnivore<string> o1 = {"Tyranozaur", 60};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_147() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Herbivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_148() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_149() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_150() {
  Carnivore<string> o1 = {"Tyranozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_151() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_152() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_153() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_154() {
  Carnivore<string> o1 = {"Tyranozaur", 40};
  Herbivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_155() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Herbivore<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_156() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_157() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_158() {
  Carnivore<string> o1 = {"Tyranozaur", 60};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_159() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Plant<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_160() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_161() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_162() {
  Carnivore<string> o1 = {"Tyranozaur", 40};
  Plant<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_163() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(!std::get<2>(enc).has_value());
}

void org_test_164() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_165() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_166() {
  Carnivore<string> o1 = {"Tyranozaur", 40};
  Plant<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_167() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Plant<string> o2 = {"Tyranozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(!std::get<2>(enc).has_value());
}

void org_test_168() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(std::get<2>(enc)->get_vitality() == 50);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_169() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 60);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(std::get<2>(enc)->get_vitality() == 50);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_170() {
  Carnivore<string> o1 = {"Tyranozaur", 60};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_171() {
  Carnivore<string> o1 = {"Dinozaur", 60};
  Carnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 80);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_172() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(std::get<2>(enc)->get_vitality() == 40);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_173() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 40);
  assert(std::get<2>(enc)->get_vitality() == 40);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_174() {
  Carnivore<string> o1 = {"Tyranozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_175() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Tyranozaur", 40};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 0);
  assert(!std::get<2>(enc).has_value());
}

void org_test_176() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(std::get<2>(enc)->get_vitality() == 50);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_177() {
  Carnivore<string> o1 = {"Dinozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 40);
  assert(std::get<1>(enc).get_vitality() == 60);
  assert(std::get<2>(enc)->get_vitality() == 50);
  assert(std::get<2>(enc)->get_species() == "Dinozaur");
}

void org_test_178() {
  Carnivore<string> o1 = {"Tyranozaur", 40};
  Carnivore<string> o2 = {"Dinozaur", 60};

  auto enc = encounter(o1, o2);

  assert(std::get<0>(enc).get_vitality() == 0);
  assert(std::get<1>(enc).get_vitality() == 80);
  assert(!std::get<2>(enc).has_value());
}

void org_test_179() {
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
  return 0;
}
