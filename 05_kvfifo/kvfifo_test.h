#ifndef KVFIFO_TEST_H_
#define KVFIFO_TEST_H_

#include "kvfifo.h"
#include <cassert>
#include <memory>
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

namespace mkostyk {
    auto f(kvfifo<int, int> q) {
        return q;
    }

    void peczar_test() {
        cout << "Peczar test" << endl;
        int keys[] = {3, 1, 2};

        kvfifo<int, int> kvf1 = f({});

        for (int i = 0; i < 3; ++i)
        kvf1.push(keys[i], i);

        auto &ref = kvf1.front().second;

        kvfifo<int, int> kvf2(kvf1); // Wykonuje się pełna kopia, dlaczego?
        kvfifo<int, int> kvf3;
        kvf3 = kvf2;

        ref = 10;
        assert(kvf1.front().second == 10);
        assert(kvf2.front().second != 10);

        kvf2.pop(); // Obiekt kvf2 dokonuje kopii i przestaje współdzielić dane z kvf3.
        assert(kvf2.size() == 2);
        assert(kvf2.count(3) == 0);
        assert(kvf2.count(2) == 1);

        assert(kvf3.size() == 3);
        assert(kvf3.count(3) == 1);

        kvf2.push(1, 3);
        kvf2.move_to_back(1);
        assert(kvf2.size() == 3);
        assert(kvf2.front().second == 2 &&
                kvf2.first(1).second == 1 &&
                kvf2.last(1).second == 3 &&
                kvf2.back().second == 3);

        kvfifo<int, int> const kvf4 = kvf2;
        assert(kvf4.front().second == 2 &&
                kvf4.first(1).second == 1 &&
                kvf4.last(1).second == 3 &&
                kvf4.back().second == 3);

        int i = 1;
        for (auto k_it = kvf1.k_begin(), k_end = kvf1.k_end(); k_it != k_end; ++k_it, ++i)
            assert(i <= 3 && *k_it == i);


        auto kvf5 = std::make_unique<kvfifo<int, int>>();
        kvf5->push(4, 0);
        assert(kvf5->front().first == 4 && kvf5->front().second == 0);
        auto kvf6(*kvf5);
        kvf5.reset();
        assert(kvf6.front().first == 4 && kvf6.front().second == 0);

        std::swap(kvf1, kvf2);
        std::vector<kvfifo<int, int>> vec;
        for (int i = 0; i < 100000; i++)
        kvf1.push(i, i);
        for (int i = 0; i < 1000000; i++)
        vec.push_back(kvf1);  // Wszystkie obiekty w vec współdzielą dane.
    }

    void correctness_test() {
        cout << "Correctness test" << endl;
        string keys[] = {"Peczar", "Diks", "Engel"};
        kvfifo<string, int> kvf1;

        for (int i = 0; i < 3; ++i) {
            kvf1.push(keys[i], i);
        }
        
        assert(kvf1.size() == 3);
        assert(kvf1.count("Peczar") == 1);

        kvfifo<string, int> kvf2;

        for (int i = 0; i < 100; ++i) {
            kvf2.push(keys[i % 3], i);
        }

        assert(kvf2.size() == 100);

        for (int i = 0; i < 20; i++) {
            kvf2.pop();
        }

        assert(kvf2.size() == 80 && kvf2.count("Peczar") == 27 && kvf2.front().first == "Engel");

        kvf2.move_to_back("Peczar");
        assert(kvf2.size() == 80 && kvf2.count("Peczar") == 27 && kvf2.back().first == "Peczar");

        kvfifo<string, int> kvf3 = kvf2;
        kvf3.pop("Engel");
        assert(kvf3.size() == 79 && kvf3.count("Peczar") == 27 && kvf3.front().first == "Diks");
        assert(kvf2.size() == 80); // Nie usunęliśmy z kvf2

        kvfifo<string, int> kvf4 = kvf2;
        kvfifo<string, int> kvf5 = kvf4;
        assert(kvf4.first("Peczar").second == 21 && kvf4.last("Peczar").second == 99);

        // Reference testing
        auto &val1 = kvf4.first("Peczar").second;
        val1 = 2137;

        assert(kvf4.first("Peczar").second == 2137);
        assert(kvf5.first("Peczar").second != 2137);


        kvf4 = kvf2;
        kvf5 = kvf4;

        auto &val2 = kvf4.last("Peczar").second;
        val2 = 2137;

        assert(kvf4.last("Peczar").second == 2137);
        assert(kvf5.last("Peczar").second != 2137);

        
        kvf4 = kvf2;
        kvf5 = kvf4;

        auto &val3 = kvf4.front().second;
        val3 = 2137;

        assert(kvf4.front().second == 2137);
        assert(kvf5.front().second != 2137);


        kvf4 = kvf2;
        kvf5 = kvf4;

        auto &val4 = kvf4.back().second;
        val4 = 2137;

        assert(kvf4.back().second == 2137);
        assert(kvf5.back().second != 2137);
    }

    void iterator_test() {
        cout << "Iterator test" << endl;
        kvfifo<string, int> kvf1;

        kvf1.push("Asterix", 1);
        kvf1.push("Obelix", 2);
        kvf1.push("Idefix", 3);

        // Tworzymy const kolejkę i sprawdzamy, czy iterator działa poprawnie.
        kvfifo<string, int> const const_kvf = static_cast<const kvfifo<string, int>&>(kvf1);

        auto it = const_kvf.k_begin();
        assert(*it == "Asterix");

        // Żadna z poniższych operacji nie powinna unieważnić iteratora.

        std::pair<string const&, int const&> ref1 = const_kvf.front();
        it++;
        assert(*it == "Idefix");

        std::pair<string const&, int const&> ref2 = const_kvf.back();
        it++;
        assert(*it == "Obelix");

        std::pair<string const&, int const&> ref3 = const_kvf.first("Obelix");
        it--;
        assert(*it == "Idefix");

        std::pair<string const&, int const&> ref4 = const_kvf.last("Obelix");
        it--;
        assert(*it == "Asterix");

        for (int i = 0; i < 3; i++)
            it++;

        assert(it == const_kvf.k_end());

        assert(ref1.first == "Asterix" && ref1.second == 1);
        assert(ref2.first == "Idefix" && ref2.second == 3);
        assert(ref3.first == "Obelix" && ref3.second == 2);
        assert(ref4.first == "Obelix" && ref4.second == 2);
    }

    void shared_data_test() {
        cout << "Shared data test" << endl;
        string napis = "To nie ma tak że dobrze albo że nie dobrze.";
        kvfifo<string, int> shared_test;
        std::vector<kvfifo<string, int>> vec;

        // Analogicznie do testu Peczara
        for (int i = 0; i < 100000; i++) {
            shared_test.push(napis, i);
        }

        for (int i = 0; i < 100000; i++) {
            vec.push_back(shared_test);
        }

        // Sprawdzamy czy usuwanie w jednym nie powoduje stworzenia kopii wszystkiego.
        for (int i = 0; i < 100000; i++) {
            vec[0].pop();
        }

        assert(vec[0].size() == 0);

        // Referencje będą do stałych obiektów, więc dane nie powinny być kopiowane.
        using const_ref = typename std::pair<string const&, int const&>;
        std::vector<const_ref> vec_ref;

        for (int i = 1; i < 100000; i++) {
            vec_ref.push_back(static_cast<const kvfifo<string, int>&>(vec[i]).front());
        }
    }

    void very_long_key_test() {
        cout << "Very long key test" << endl;

        int STRING_SIZE = 1000000;
        int QUEUE_SIZE = 10000;
        string very_long_string = "";
        for (int i = 0; i < STRING_SIZE; ++i)
            very_long_string += "a";

        kvfifo<string, int> string_test;

        for (int i = 0; i < QUEUE_SIZE; i++) {
            string_test.push(very_long_string, i);
        }
    }

    void invalidating_references_test() {
        cout << "Invalidating references test" << endl;
        string napis = "Gdybym miał powiedzieć co cenię w życiu najbardziej, powiedziałbym że ludzi.";

        kvfifo<string, int> ref_test;
        for (int i = 0; i < 100000; i++) {
            ref_test.push(napis, i);
        }

        auto &val = ref_test.front().second;
        val = 42;
        ref_test.pop();

        // To powinno działać, gdyż dokonując pop unieważniamy referencję i nie trzeba
        // robić kolejnych kopii danych.
        std::vector<kvfifo<string, int>> vec;
        for (int i = 0; i < 100000; i++) {
            vec.push_back(ref_test);
        }
    }

    void mkostyk_kvfifo_test_main() {
        cout << "\033[1;37m" << "---------- MKOSTYK TEST ----------" << "\033[0m" << endl;
        peczar_test();
        correctness_test();
        iterator_test();
        shared_data_test();
        very_long_key_test();
        invalidating_references_test();
    }
} // namespace mkostyk
#endif // KVFIFO_TEST_H_