#ifndef ALLOC_FAIL_H_
#define ALLOC_FAIL_H_

#include "kvfifo.h"
#include <cassert>
#include <string>
#include <iostream>
#include <vector>

int mem_fail = 0;
int counter = 0;
bool is_counting = false;
bool did_fail = false;

using std::string;
using std::vector;
using std::cerr;
using std::endl;

void enable_counting() {
    is_counting = true;
}

void disable_counting() {
    is_counting = false;
}

void* operator new(size_t sz)
{   
    if (is_counting) {
        counter++;
        if (counter == mem_fail) {
            did_fail = true;
            throw std::bad_alloc();
        }
    }

    void* m = malloc(sz);

    return m;
}

void operator delete(void* m)
{
    free(m);
}

void operator delete(void* m, size_t sz)
{
    free(m);
}

void* operator new[](size_t sz)
{
    if (is_counting) {
        counter++;
        if (counter == mem_fail) {
            did_fail = true;
            throw std::bad_alloc();
        }
    }

    void* m = malloc(sz);

    return m;
}

void operator delete[](void* m)
{
    free(m);
}

void operator delete[](void* m, size_t sz)
{
    free(m);
}

namespace mkostyk {
    int const SEED = 110912309;
    // int const SEED = time(NULL); - Jeśli chcesz żeby był test losowy.
    int const TEST_SIZE = 100; // Zwiększanie tego powoduje kwadratowy wzrost długości czasu wykonania!

    string const RED = "\033[1;31m";
    string const GREEN = "\033[1;32m";
    string const CYAN = "\033[1;36m";
    string const WHITE = "\033[1;37m";
    string const RESET = "\033[0m";

    // Sprawdza czy nie zepsuliśmy czegoś w zbiorze kluczy.
    bool check_key_set(kvfifo <string, int> &kvf) {
        int unique_key_counter = 0;
        for (int i = 0; i < 10; i++) {
            string key = "key" + std::to_string(i);
            if (kvf.count(key) > 0) {
                unique_key_counter++;
            }
        }

        auto it = kvf.k_begin();
        for (int i = 0; i < unique_key_counter; i++, it++);

        return it == kvf.k_end();
    }

    void test(int mem_fail_id, vector <int> &ops) {
        disable_counting();
        // Deklaracje tutaj są bezpieczne.
        kvfifo <string, int> alloc_kvf = {};
        unsigned int size;
        string top_key, last_key;
        int top_value, last_value;

        counter = 0;
        mem_fail = mem_fail_id;

        for (int i = 0; i < TEST_SIZE; i++) {
            // To musi być safe.
            disable_counting();
            string key = "key" + std::to_string(i % 10);

            try {
                size = alloc_kvf.size();
                top_key = alloc_kvf.front().first;
                top_value = alloc_kvf.front().second;
                last_key = alloc_kvf.back().first;
                last_value = alloc_kvf.back().second;
            } catch (std::invalid_argument &e) {
                assert(alloc_kvf.size() == 0);
            }

            enable_counting();

            switch (ops[i]) {
                case 0:
                    try {
                        alloc_kvf.push(key, i);
                    } catch (std::exception &e) {
                        disable_counting();
                        if (size > 0) assert(alloc_kvf.size() == size && 
                                             alloc_kvf.front().first == top_key &&
                                             alloc_kvf.front().second == top_value &&
                                             alloc_kvf.back().first == last_key &&
                                             alloc_kvf.back().second == last_value &&
                                             check_key_set(alloc_kvf)
                                            );
                        enable_counting();
                    }
                    break;

                case 1:
                    try {
                        alloc_kvf.pop();
                    } catch (std::invalid_argument &e) {
                        disable_counting();
                        assert(alloc_kvf.size() == 0);
                        enable_counting();
                    } catch (std::exception &e) {
                        disable_counting();
                        if (size > 0) assert(alloc_kvf.size() == size && 
                                             alloc_kvf.front().first == top_key &&
                                             alloc_kvf.front().second == top_value &&
                                             alloc_kvf.back().first == last_key &&
                                             alloc_kvf.back().second == last_value &&
                                             check_key_set(alloc_kvf)
                                            );
                        enable_counting();
                    }
                    break;

                case 2:
                    try {
                        alloc_kvf.pop(key);
                    } catch (std::invalid_argument &e) {
                        disable_counting();
                        assert(alloc_kvf.count(key) == 0);
                        enable_counting();
                    } catch (std::exception &e) {
                        disable_counting();
                        if (size > 0) assert(alloc_kvf.size() == size && 
                                             alloc_kvf.front().first == top_key &&
                                             alloc_kvf.front().second == top_value &&
                                             alloc_kvf.back().first == last_key &&
                                             alloc_kvf.back().second == last_value &&
                                             check_key_set(alloc_kvf)
                                            );
                        enable_counting();
                    }
                    break;

                case 3:
                    try {
                        alloc_kvf.move_to_back(key);
                    } catch (std::invalid_argument &e) {
                        disable_counting();
                        assert(alloc_kvf.count(key) == 0);
                        enable_counting();
                    } catch (std::exception &e) {
                        disable_counting();
                        if (size > 0) assert(alloc_kvf.size() == size && 
                                             alloc_kvf.front().first == top_key &&
                                             alloc_kvf.front().second == top_value &&
                                             alloc_kvf.back().first == last_key &&
                                             alloc_kvf.back().second == last_value &&
                                             check_key_set(alloc_kvf)
                                            );
                        enable_counting();
                    }
                    break;
                }
        }
    }

    void mkostyk_alloc_fail_main() {
        srand(SEED);
        vector <int> ops;
        cout << WHITE << "---------- ALLOC FAIL TEST ----------" << RESET << endl;
        for (int i = 0; i < TEST_SIZE; i++) {
            // Test jest domyślnie deterministyczny, ponieważ seed jest ustalony.
            // "Losowanie" w tej funkcji służy tylko do generowania operacji.
            int random = rand() % 5;

            // Podwajamy liczbę pushy żeby nie było zbyt wiele popów.
            if (random == 0 || random == 1) {
                ops.push_back(0);
            }
            else {
                ops.push_back(random - 1);
            }
        }

        int test_number = 1;

        while (true) {
            did_fail = false;
            test(test_number, ops);
            cout << GREEN << "Test of alloc " << test_number << " passed." << RED << endl;
            test_number++;

            if (!did_fail) {
                // Nie ma więcej alloców do zepsucia.
                cout << CYAN << "All tests passed! Congratulations!" << RESET << endl;
                break;
            }
        }

        disable_counting(); // Koniec testu.
    }

} // namespace mkostyk
#endif // ALLOC_FAIL_H_