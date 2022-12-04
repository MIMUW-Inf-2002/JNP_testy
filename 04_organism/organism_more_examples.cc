#include <string>
#include <iostream>
#include "organism.h"

using namespace std;
using species_id_t = uint8_t;
const species_id_t id_1 = 1;
const species_id_t id_2 = 2;

constexpr void plant_eaten_by_herb_1() {
    constexpr Herbivore<species_id_t> stegozaur(id_1, 50);
    constexpr Plant<species_id_t> oak(id_1, 100);


    constexpr auto encounter_result = encounter(stegozaur, oak);
    constexpr Herbivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Plant<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Herbivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 150);
    static_assert(o2.is_dead());
    static_assert(!o3.has_value());
}

constexpr void plant_eaten_by_herb_2() {
    constexpr Herbivore<species_id_t> stegozaur(id_1, 50);
    constexpr Plant<species_id_t> oak(id_1, 100);


    constexpr auto encounter_result = encounter(oak, stegozaur);
    constexpr Plant<species_id_t> o1 = get<0>(encounter_result);
    constexpr Herbivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Plant<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.is_dead());
    static_assert(o2.get_vitality() == 150);
    static_assert(!o3.has_value());
}

constexpr void plant_eaten_by_omn_1() {
    constexpr Omnivore<species_id_t> terizinozaur(id_1, 50);
    constexpr Plant<species_id_t> oak(id_1, 100);

    constexpr auto encounter_result = encounter(terizinozaur, oak);
    constexpr Omnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Plant<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Omnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 150);
    static_assert(o2.is_dead());
    static_assert(!o3.has_value());
}

constexpr void plant_eaten_by_omn_2() {
    constexpr Omnivore<species_id_t> terizinozaur(id_1, 50);
    constexpr Plant<species_id_t> oak(id_1, 100);


    constexpr auto encounter_result = encounter(oak, terizinozaur);
    constexpr Plant<species_id_t> o1 = get<0>(encounter_result);
    constexpr Omnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Plant<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.is_dead());
    static_assert(o2.get_vitality() == 150);
    static_assert(!o3.has_value());
}

constexpr void two_herb_nothing() {
    constexpr Herbivore<species_id_t> stegozaur(id_2, 50);
    constexpr Herbivore<species_id_t> elephant(id_1, 100);

    constexpr auto encounter_result = encounter(stegozaur, elephant);
    constexpr Herbivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Herbivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Herbivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 50);
    static_assert(o2.get_vitality() == 100);
    static_assert(!o3.has_value());
}

constexpr void two_herb_multiply() {
    constexpr Herbivore<species_id_t> stegozaur(id_2, 50);
    constexpr Herbivore<species_id_t> stegozaur2(id_2, 100);

    constexpr auto encounter_result = encounter(stegozaur, stegozaur2);
    constexpr Herbivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Herbivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Herbivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 50);
    static_assert(o2.get_vitality() == 100);
    static_assert(o3.value().get_vitality() == 75);
}

constexpr void herb_eaten_by_omn_1() {
    constexpr Herbivore<species_id_t> stegozaur(id_1, 50);
    constexpr Omnivore<species_id_t> terizinozaur(id_1, 100);

    constexpr auto encounter_result = encounter(stegozaur, terizinozaur);
    constexpr Herbivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Omnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Herbivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.is_dead());
    static_assert(o2.get_vitality() == 125);
    static_assert(!o3.has_value());
}

constexpr void herb_eaten_by_omn_2() {
    constexpr Herbivore<species_id_t> stegozaur(id_1, 50);
    constexpr Omnivore<species_id_t> terizinozaur(id_1, 100);

    constexpr auto encounter_result = encounter(terizinozaur, stegozaur);
    constexpr Omnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Herbivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Omnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 125);
    static_assert(o2.is_dead());
    static_assert(!o3.has_value());
}

constexpr void herb_not_eaten_by_omn_1() {
    constexpr Herbivore<species_id_t> stegozaur(id_1, 100);
    constexpr Omnivore<species_id_t> terizinozaur(id_1, 100);

    constexpr auto encounter_result = encounter(terizinozaur, stegozaur);
    constexpr Omnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Herbivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Omnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 100);
    static_assert(o2.get_vitality() == 100);
    static_assert(!o3.has_value());
}

constexpr void herb_not_eaten_by_omn_2() {
    constexpr Herbivore<species_id_t> stegozaur(id_1, 100);
    constexpr Omnivore<species_id_t> terizinozaur(id_1, 100);

    constexpr auto encounter_result = encounter(stegozaur, terizinozaur);
    constexpr Herbivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Omnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Herbivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 100);
    static_assert(o2.get_vitality() == 100);
    static_assert(!o3.has_value());
}

constexpr void carn_plant_nothing_1() {
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 100);
    constexpr Plant<species_id_t> oak(id_1, 100);

    constexpr auto encounter_result = encounter(tyranozaur, oak);
    constexpr Carnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Plant<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Carnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 100);
    static_assert(o2.get_vitality() == 100);
    static_assert(!o3.has_value());
}

constexpr void carn_plant_nothing_2() {
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 100);
    constexpr Plant<species_id_t> oak(id_1, 100);

    constexpr auto encounter_result = encounter(oak, tyranozaur);
    constexpr Plant<species_id_t> o1 = get<0>(encounter_result);
    constexpr Carnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Plant<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 100);
    static_assert(o2.get_vitality() == 100);
    static_assert(!o3.has_value());
}

constexpr void herb_eaten_by_carn_1() {
    constexpr Herbivore<species_id_t> stegozaur(id_1, 50);
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 100);

    constexpr auto encounter_result = encounter(stegozaur, tyranozaur);
    constexpr Herbivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Carnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Herbivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.is_dead());
    static_assert(o2.get_vitality() == 125);
    static_assert(!o3.has_value());
}

constexpr void herb_eaten_by_carn_2() {
    constexpr Herbivore<species_id_t> stegozaur(id_1, 50);
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 100);

    constexpr auto encounter_result = encounter(tyranozaur, stegozaur);
    constexpr Carnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Herbivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Carnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 125);
    static_assert(o2.is_dead());
    static_assert(!o3.has_value());
}

constexpr void herb_not_eaten_by_carn_1() {
    constexpr Herbivore<species_id_t> stegozaur(id_1, 100);
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 100);

    constexpr auto encounter_result = encounter(tyranozaur, stegozaur);
    constexpr Carnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Herbivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Carnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 100);
    static_assert(o2.get_vitality() == 100);
    static_assert(!o3.has_value());
}

constexpr void herb_not_eaten_by_carn_2() {
    constexpr Herbivore<species_id_t> stegozaur(id_1, 100);
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 100);

    constexpr auto encounter_result = encounter(stegozaur, tyranozaur);
    constexpr Herbivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Carnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Herbivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 100);
    static_assert(o2.get_vitality() == 100);
    static_assert(!o3.has_value());
}

constexpr void omn_carn_fight_1() {
    constexpr Omnivore<species_id_t> human(id_1, 200);
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 100);

    constexpr auto encounter_result = encounter(human, tyranozaur);
    constexpr Omnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Carnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Omnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 250);
    static_assert(o2.get_vitality() == 0);
    static_assert(!o3.has_value());
}

constexpr void omn_carn_fight_2() {
    constexpr Omnivore<species_id_t> human(id_1, 200);
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 100);

    constexpr auto encounter_result = encounter(tyranozaur, human);
    constexpr Carnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Omnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Carnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 0);
    static_assert(o2.get_vitality() == 250);
    static_assert(!o3.has_value());
}

constexpr void omn_carn_fight_3() {
    constexpr Omnivore<species_id_t> human(id_1, 100);
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 100);

    constexpr auto encounter_result = encounter(human, tyranozaur);
    constexpr Omnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Carnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Omnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 0);
    static_assert(o2.get_vitality() == 0);
    static_assert(!o3.has_value());
}

constexpr void omn_carn_fight_4() {
    constexpr Omnivore<species_id_t> human(id_1, 100);
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 100);

    constexpr auto encounter_result = encounter(tyranozaur, human);
    constexpr Carnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Omnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Carnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 0);
    static_assert(o2.get_vitality() == 0);
    static_assert(!o3.has_value());
}

constexpr void omn_carn_fight_5() {
    constexpr Omnivore<species_id_t> human(id_1, 100);
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 200);

    constexpr auto encounter_result = encounter(human, tyranozaur);
    constexpr Omnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Carnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Omnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 0);
    static_assert(o2.get_vitality() == 250);
    static_assert(!o3.has_value());
}

constexpr void omn_carn_fight_6() {
    constexpr Omnivore<species_id_t> human(id_1, 100);
    constexpr Carnivore<species_id_t> tyranozaur(id_1, 200);

    constexpr auto encounter_result = encounter(tyranozaur, human);
    constexpr Carnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Omnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Carnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 250);
    static_assert(o2.get_vitality() == 0);
    static_assert(!o3.has_value());
}

constexpr void omn_omn_fight_1() {
    constexpr Omnivore<species_id_t> human(id_1, 100);
    constexpr Omnivore<species_id_t> bear(id_2, 200);

    constexpr auto encounter_result = encounter(human, bear);
    constexpr Omnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Omnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Omnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 0);
    static_assert(o2.get_vitality() == 250);
    static_assert(!o3.has_value());
}

constexpr void omn_omn_fight_2() {
    constexpr Omnivore<species_id_t> human(id_1, 200);
    constexpr Omnivore<species_id_t> bear(id_2, 100);

    constexpr auto encounter_result = encounter(human, bear);
    constexpr Omnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Omnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Omnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 250);
    static_assert(o2.get_vitality() == 0);
    static_assert(!o3.has_value());
}

constexpr void omn_omn_fight_3() {
    constexpr Omnivore<species_id_t> human(id_1, 100);
    constexpr Omnivore<species_id_t> bear(id_2, 100);

    constexpr auto encounter_result = encounter(human, bear);
    constexpr Omnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Omnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Omnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 0);
    static_assert(o2.get_vitality() == 0);
    static_assert(!o3.has_value());
}

constexpr void omn_omn_multiply_1() {
    constexpr Omnivore<species_id_t> human1(id_1, 100);
    constexpr Omnivore<species_id_t> human2(id_1, 200);

    constexpr auto encounter_result = encounter(human1, human2);
    constexpr Omnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Omnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Omnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 100);
    static_assert(o2.get_vitality() == 200);
    static_assert(o3.value().get_vitality() == 150);
}

constexpr void carn_carn_fight_1() {
    constexpr Carnivore<species_id_t> lion(id_1, 200);
    constexpr Carnivore<species_id_t> tyranozaur(id_2, 100);

    constexpr auto encounter_result = encounter(lion, tyranozaur);
    constexpr Carnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Carnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Carnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 250);
    static_assert(o2.get_vitality() == 0);
    static_assert(!o3.has_value());
}

constexpr void carn_carn_fight_2() {
    constexpr Carnivore<species_id_t> lion(id_1, 100);
    constexpr Carnivore<species_id_t> tyranozaur(id_2, 100);

    constexpr auto encounter_result = encounter(lion, tyranozaur);
    constexpr Carnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Carnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Carnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 0);
    static_assert(o2.get_vitality() == 0);
    static_assert(!o3.has_value());
}

constexpr void carn_carn_fight_3() {
    constexpr Carnivore<species_id_t> lion(id_1, 100);
    constexpr Carnivore<species_id_t> tyranozaur(id_2, 200);

    constexpr auto encounter_result = encounter(lion, tyranozaur);
    constexpr Carnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Carnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Carnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 0);
    static_assert(o2.get_vitality() == 250);
    static_assert(!o3.has_value());
}

constexpr void carn_carn_multiply_1() {
    constexpr Carnivore<species_id_t> lion1(id_1, 100);
    constexpr Carnivore<species_id_t> lion2(id_1, 200);

    constexpr auto encounter_result = encounter(lion1, lion2);
    constexpr Carnivore<species_id_t> o1 = get<0>(encounter_result);
    constexpr Carnivore<species_id_t> o2 = get<1>(encounter_result);
    constexpr std::optional<Carnivore<species_id_t>> o3 = get<2>(encounter_result);

    static_assert(o1.get_vitality() == 100);
    static_assert(o2.get_vitality() == 200);
    static_assert(o3.value().get_vitality() == 150);
}

constexpr void should_fail(){
    constexpr Omnivore<uint64_t> dog1(id_1, 10);
    constexpr Omnivore<double> dog2(id_1, 15);

//    encounter(dog1, dog2);
    constexpr Plant<uint64_t> plant1(id_1, 10);
    constexpr Plant<uint64_t> plant2(id_1, 15);
//    encounter(plant1, plant2);
}

constexpr void series(){
    constexpr Omnivore<species_id_t> caveman(id_1, 200);
    constexpr Carnivore<species_id_t> lion1(id_1, 100);
    constexpr Carnivore<species_id_t> lion2(id_1, 100);
    constexpr Carnivore<species_id_t> lion3(id_1, 100);
    constexpr Omnivore<species_id_t> caveman2(id_2, 300);
    constexpr Herbivore<species_id_t> mammoth(id_1, 1000);

    constexpr auto caveman_result = encounter_series(caveman, lion1, lion2, lion3, caveman2, mammoth);

    static_assert(!caveman_result.is_dead());
    static_assert(caveman_result.get_vitality() == 500);

}

int main() {
    plant_eaten_by_herb_1();
    plant_eaten_by_herb_2();
    plant_eaten_by_omn_1();
    plant_eaten_by_omn_2();
    two_herb_nothing();
    two_herb_multiply();
    herb_eaten_by_omn_1();
    herb_eaten_by_omn_2();
    herb_not_eaten_by_omn_1();
    herb_not_eaten_by_omn_2();
    carn_plant_nothing_1();
    carn_plant_nothing_2();
    herb_eaten_by_carn_1();
    herb_eaten_by_carn_2();
    herb_not_eaten_by_carn_1();
    herb_not_eaten_by_carn_2();
    omn_carn_fight_1();
    omn_carn_fight_2();
    omn_carn_fight_3();
    omn_carn_fight_4();
    omn_carn_fight_5();
    omn_carn_fight_6();
    omn_omn_fight_1();
    omn_omn_fight_2();
    omn_omn_fight_3();
    omn_omn_multiply_1();
    carn_carn_fight_1();
    carn_carn_fight_2();
    carn_carn_fight_3();
    carn_carn_multiply_1();
    should_fail(); // tutaj trzeba odkomentować linijki w środku, aby sprawdzić, czy się nie skompiluje
    series();
    cout << "Tests passed." << endl;
}
