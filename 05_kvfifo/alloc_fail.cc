#include "kvfifo.h"
#include <cassert>
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cerr;
using std::endl;

int const SEED = 110912309;
// int const SEED = srand(time(NULL)); - Jeśli chcesz żeby był test losowy.
int const TEST_SIZE = 500; // Zwiększanie tego powoduje kwadratowy wzrost długości czasu wykonania!

string const RED = "\033[1;31m";
string const GREEN = "\033[1;32m";
string const CYAN = "\033[1;36m";

int mem_fail = 0;
int counter = 0;
bool is_counting = false;
bool did_fail = false;

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

void enable_counting() {
    is_counting = true;
}

void disable_counting() {
    is_counting = false;
}

int test(int mem_fail_id, vector <int> &ops) {
    disable_counting();
    // Deklaracje tutaj są bezpieczne.
    kvfifo <string, int> kvf2 = {};
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
            size = kvf2.size();
            top_key = kvf2.front().first;
            top_value = kvf2.front().second;
            last_key = kvf2.back().first;
            last_value = kvf2.back().second;
        } catch (std::invalid_argument &e) {
            assert(kvf2.size() == 0);
        }

        enable_counting();

        switch (ops[i]) {
            case 0:
                try {
                    kvf2.push(key, i);
                } catch (std::exception &e) {
                    disable_counting();
                    if (size > 0) assert(kvf2.size() == size && 
                                         kvf2.front().first == top_key &&
                                         kvf2.front().second == top_value &&
                                         kvf2.back().first == last_key &&
                                         kvf2.back().second == last_value
                                        );
                    enable_counting();
                }
                break;

            case 1:
                try {
                    kvf2.pop();
                } catch (std::invalid_argument &e) {
                    disable_counting();
                    assert(kvf2.size() == 0);
                    enable_counting();
                } catch (std::exception &e) {
                    disable_counting();
                    if (size > 0) assert(kvf2.size() == size && 
                                         kvf2.front().first == top_key &&
                                         kvf2.front().second == top_value &&
                                         kvf2.back().first == last_key &&
                                         kvf2.back().second == last_value
                                        );
                    enable_counting();
                }
                break;

            case 2:
                try {
                    kvf2.pop(key);
                } catch (std::invalid_argument &e) {
                    disable_counting();
                    assert(kvf2.count(key) == 0);
                    enable_counting();
                } catch (std::exception &e) {
                    disable_counting();
                    if (size > 0) assert(kvf2.size() == size && 
                                         kvf2.front().first == top_key &&
                                         kvf2.front().second == top_value &&
                                         kvf2.back().first == last_key &&
                                         kvf2.back().second == last_value
                                        );
                    enable_counting();
                }
                break;

            case 3:
                try {
                    kvf2.move_to_back(key);
                } catch (std::invalid_argument &e) {
                    disable_counting();
                    assert(kvf2.count(key) == 0);
                    enable_counting();
                } catch (std::exception &e) {
                    disable_counting();
                    if (size > 0) assert(kvf2.size() == size && 
                                         kvf2.front().first == top_key &&
                                         kvf2.front().second == top_value &&
                                         kvf2.back().first == last_key &&
                                         kvf2.back().second == last_value
                                        );
                    enable_counting();
                }
                break;
            }
    }

    return -1;

}

int main() {
    srand(SEED);
    vector <int> ops;
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
            cout << CYAN << "All tests passed! Congratulations!" << endl;
            break;
        }
    }
}