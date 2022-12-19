#ifndef KWASOW_H_
#define KWASOW_H_

#include "kvfifo.h"
#include <cassert>
#include <iostream>

namespace kwasow {

void kwasowTests0();
void kwasowTests1();
void kwasowTests2();
void kwasowTests3();
void kwasowTests4();
void kwasowTests5();

void kwasowMain() {
  std::cout << "Starting kwasow tests" << std::endl;
  kwasowTests0();
  std::cout << "Passed kwasowTests0" << std::endl;
  kwasowTests1();
  std::cout << "Passed kwasowTests1" << std::endl;
  kwasowTests2();
  std::cout << "Passed kwasowTests2" << std::endl;
  kwasowTests3();
  std::cout << "Passed kwasowTests3" << std::endl;
  kwasowTests4();
  std::cout << "Passed kwasowTests4" << std::endl;
	kwasowTests5();
}

// Basic operations
void kwasowTests0() {
  kvfifo<int, int> kvf1;

  try {
  // Test push, empty, front, back, size
  assert(kvf1.empty());
  kvf1.push(1, 2);
  assert(!kvf1.empty());
  assert(kvf1.front().first == 1 && kvf1.front().second == 2);
  kvf1.push(2, 3);
  assert(kvf1.front().first == 1 && kvf1.front().second == 2);
  assert(kvf1.back().first == 2 && kvf1.back().second == 3);
  assert(kvf1.size() == 2);

  // Test first, last, count
  kvf1.push(3, 3);
  kvf1.push(1, 1);
  kvf1.push(3, 2);
  kvf1.push(2, 0);
  // The queue now looks like this:
  // [(1,2), (2,3), (3,3), (1,1), (3,2), (2,0)]
  assert(kvf1.size() == 6);
  assert(kvf1.count(1) == 2);
  assert(kvf1.count(2) == 2);
  assert(kvf1.count(3) == 2);
  assert(kvf1.count(0) == 0);
  assert(kvf1.first(1).first == 1 && kvf1.first(1).second == 2);
  assert(kvf1.first(2).first == 2 && kvf1.first(2).second == 3);
  assert(kvf1.first(3).first == 3 && kvf1.first(3).second == 3);
  assert(kvf1.last(1).first == 1 && kvf1.last(1).second == 1);
  assert(kvf1.last(2).first == 2 && kvf1.last(2).second == 0);
  assert(kvf1.last(3).first == 3 && kvf1.last(3).second == 2);

  // Test move_to_back
  kvf1.move_to_back(2);
  // The queue now looks like this:
  // [(1,2), (3,3), (1,1), (3,2), (2,3), (2,0)]
  assert(kvf1.first(1).first == 1 && kvf1.first(1).second == 2);
  assert(kvf1.first(2).first == 2 && kvf1.first(2).second == 3);
  assert(kvf1.first(3).first == 3 && kvf1.first(3).second == 3);
  assert(kvf1.last(1).first == 1 && kvf1.last(1).second == 1);
  assert(kvf1.last(2).first == 2 && kvf1.last(2).second == 0);
  assert(kvf1.last(3).first == 3 && kvf1.last(3).second == 2);
  assert(kvf1.front().first == 1 && kvf1.front().second == 2);
  assert(kvf1.back().first == 2 && kvf1.back().second == 0);

  kvf1.move_to_back(3);
  // The queue now looks like this:
  // [(1,2), (1,1), (2,3), (2,0), (3,3), (3,2)]
  assert(kvf1.first(1).first == 1 && kvf1.first(1).second == 2);
  assert(kvf1.first(2).first == 2 && kvf1.first(2).second == 3);
  assert(kvf1.first(3).first == 3 && kvf1.first(3).second == 3);
  assert(kvf1.last(1).first == 1 && kvf1.last(1).second == 1);
  assert(kvf1.last(2).first == 2 && kvf1.last(2).second == 0);
  assert(kvf1.last(3).first == 3 && kvf1.last(3).second == 2);
  assert(kvf1.front().first == 1 && kvf1.front().second == 2);
  assert(kvf1.back().first == 3 && kvf1.back().second == 2);

  kvf1.move_to_back(1);
  // The queue now looks like this:
  // [(2,3), (2,0), (3,3), (3,2), (1,2), (1,1)]
  assert(kvf1.first(1).first == 1 && kvf1.first(1).second == 2);
  assert(kvf1.first(2).first == 2 && kvf1.first(2).second == 3);
  assert(kvf1.first(3).first == 3 && kvf1.first(3).second == 3);
  assert(kvf1.last(1).first == 1 && kvf1.last(1).second == 1);
  assert(kvf1.last(2).first == 2 && kvf1.last(2).second == 0);
  assert(kvf1.last(3).first == 3 && kvf1.last(3).second == 2);
  assert(kvf1.front().first == 2 && kvf1.front().second == 3);
  assert(kvf1.back().first == 1 && kvf1.back().second == 1);

  // Test pop
  kvf1.pop(3);
  assert(kvf1.first(3).first == 3 && kvf1.first(3).second == 2);
  assert(kvf1.last(3).first == 3 && kvf1.last(3).second == 2);
  assert(kvf1.size() == 5);
  kvf1.pop(2);
  assert(kvf1.first(2).first == 2 && kvf1.first(2).second == 0);
  assert(kvf1.last(2).first == 2 && kvf1.last(2).second == 0);
  assert(kvf1.front().first == 2 && kvf1.front().second == 0);
  assert(kvf1.size() == 4);
  kvf1.pop();
  assert(kvf1.front().first == 3 && kvf1.front().second == 2);
  assert(kvf1.size() == 3);

  // Test clear
  kvf1.clear();
  assert(kvf1.size() == 0);
  assert(kvf1.empty());
  assert(kvf1.count(1) == 0);
  } catch (...) {
    assert(false && "Should not throw");
  }
}

// Different edge cases
void kwasowTests1() {
  // Elements with the same key and value
  kvfifo<int, int> kvf1;
  kvf1.push(1, 1);
  kvf1.push(1, 1);
  kvf1.push(1, 1);
  assert(kvf1.size() == 3);
  assert(kvf1.count(1) == 3);
  kvf1.pop(1);
  assert(kvf1.size() == 2);
  assert(kvf1.count(1) == 2);
  assert(kvf1.first(1).second == 1);
  kvf1.clear();
  assert(kvf1.size() == 0);
}

// These tests test if modifications on copies of object don't change the
// original object
void kwasowTests2() {
  kvfifo<int, int> originalObject;
  originalObject.push(1, 1);
  originalObject.push(2, 1);
  originalObject.push(3, 1);
  originalObject.push(4, 1);

  // Operator=
  auto copy11 = originalObject;
  auto copy12 = originalObject;
  auto copy13 = originalObject;
  auto copy14 = originalObject;
  auto copy15 = originalObject;
  auto copy16 = originalObject;
  auto copy17 = originalObject;
  auto copy18 = originalObject;
  auto copy19 = originalObject;

  assert(originalObject.size() == copy11.size());
  assert(originalObject.size() == copy12.size());
  assert(originalObject.size() == copy13.size());
  assert(originalObject.size() == copy14.size());
  assert(originalObject.size() == copy15.size());
  assert(originalObject.size() == copy16.size());
  assert(originalObject.size() == copy17.size());
  assert(originalObject.size() == copy18.size());
  assert(originalObject.size() == copy19.size());

  // Assert these objects are all the same (iterators point to the same list)
  assert(originalObject.k_begin() == copy11.k_begin());
  assert(originalObject.k_begin() == copy12.k_begin());
  assert(originalObject.k_begin() == copy13.k_begin());
  assert(originalObject.k_begin() == copy14.k_begin());
  assert(originalObject.k_begin() == copy15.k_begin());
  assert(originalObject.k_begin() == copy16.k_begin());
  assert(originalObject.k_begin() == copy17.k_begin());
  assert(originalObject.k_begin() == copy18.k_begin());
  assert(originalObject.k_begin() == copy19.k_begin());

  // Copy constructor
  auto copy21(originalObject);
  auto copy22(originalObject);
  auto copy23(originalObject);
  auto copy24(originalObject);
  auto copy25(originalObject);
  auto copy26(originalObject);
  auto copy27(originalObject);
  auto copy28(originalObject);
  auto copy29(originalObject);

  assert(originalObject.size() == copy21.size());
  assert(originalObject.size() == copy22.size());
  assert(originalObject.size() == copy23.size());
  assert(originalObject.size() == copy24.size());
  assert(originalObject.size() == copy25.size());
  assert(originalObject.size() == copy26.size());
  assert(originalObject.size() == copy27.size());
  assert(originalObject.size() == copy28.size());
  assert(originalObject.size() == copy29.size());

  // Assert these objects are all the same (iterators point to the same list)
  assert(originalObject.k_begin() == copy21.k_begin());
  assert(originalObject.k_begin() == copy22.k_begin());
  assert(originalObject.k_begin() == copy23.k_begin());
  assert(originalObject.k_begin() == copy24.k_begin());
  assert(originalObject.k_begin() == copy25.k_begin());
  assert(originalObject.k_begin() == copy26.k_begin());
  assert(originalObject.k_begin() == copy27.k_begin());
  assert(originalObject.k_begin() == copy28.k_begin());
  assert(originalObject.k_begin() == copy29.k_begin());

  // All operations for operator=
  copy11.push(6, 6);
  assert(originalObject.k_begin() != copy11.k_begin());
  assert(copy11.size() == 5);
  assert(copy11.back().first == 6 && copy11.back().second == 6);
  // We do this so we can call const version of back()/front()
  kvfifo<int, int> const &constRef11 = originalObject;
  assert(constRef11.size() == 4);
  assert(constRef11.back().first == 4 && constRef11.back().second == 1);

  try {
    copy12.pop();
    assert(originalObject.k_begin() != copy12.k_begin());
  } catch (...) {
    assert(false && "Should not throw");
  }
  assert(copy12.size() == 3);
  assert(copy12.front().first == 2 && copy12.front().second == 1);
  kvfifo<int, int> const &constRef12 = originalObject;
  assert(constRef12.size() == 4);
  assert(constRef12.front().first == 1 && constRef12.front().second == 1);

  try {
    copy13.pop(4);
    assert(originalObject.k_begin() != copy13.k_begin());
  } catch (...) {
    assert(false && "Should not throw");
  }
  assert(copy13.size() == 3);
  assert(copy13.back().first == 3 && copy13.back().second == 1);
  kvfifo<int, int> const &constRef13 = originalObject;
  assert(constRef13.size() == 4);
  assert(constRef13.back().first == 4 && constRef13.back().second == 1);

  try {
    copy14.move_to_back(2);
    assert(originalObject.k_begin() != copy14.k_begin());
  } catch (...) {
    assert(false && "Should not throw");
  }
  assert(copy14.size() == 4);
  assert(copy14.back().first == 2 && copy14.back().second == 1);
  kvfifo<int, int> const &constRef14 = originalObject;
  assert(constRef14.size() == 4);
  assert(constRef14.back().first == 4 && constRef14.back().second == 1);

  auto &front15 = copy15.front().second;
  assert(originalObject.k_begin() != copy15.k_begin());
  front15 = 10;
  assert(copy15.size() == 4);
  assert(copy15.front().first == 1 && copy15.front().second == 10);
  kvfifo<int, int> const &constRef15 = originalObject;
  assert(constRef15.size() == 4);
  assert(constRef15.front().first == 1 && constRef15.front().second == 1);

  auto &back16 = copy16.back().second;
  assert(originalObject.k_begin() != copy16.k_begin());
  back16 = 12;
  assert(copy16.size() == 4);
  assert(copy16.back().first == 4 && copy16.back().second == 12);
  kvfifo<int, int> const &constRef16 = originalObject;
  assert(constRef16.size() == 4);
  assert(constRef16.back().first == 4 && constRef16.back().second == 1);

  auto &first17 = copy17.first(3).second;
  assert(originalObject.k_begin() != copy17.k_begin());
  first17 = 17;
  assert(copy17.size() == 4);
  assert(copy17.first(3).first == 3 && copy17.first(3).second == 17);
  kvfifo<int, int> const &constRef17 = originalObject;
  assert(constRef17.size() == 4);
  assert(constRef17.first(3).first == 3 && constRef17.first(3).second == 1);

  auto &last18 = copy18.last(3).second;
  assert(originalObject.k_begin() != copy18.k_begin());
  last18 = 18;
  assert(copy18.size() == 4);
  assert(copy18.last(3).first == 3 && copy18.last(3).second == 18);
  kvfifo<int, int> const &constRef18 = originalObject;
  assert(constRef18.size() == 4);
  assert(constRef18.last(3).first == 3 && constRef18.last(3).second == 1);

  copy19.clear();
  assert(originalObject.k_begin() != copy19.k_begin());
  assert(copy19.empty());
  assert(copy19.size() == 0);
  assert(!originalObject.empty());
  assert(originalObject.size() == 4);

  // All operations for copy constructor
  copy21.push(6, 6);
  assert(originalObject.k_begin() != copy21.k_begin());
  assert(copy21.size() == 5);
  assert(copy21.back().first == 6 && copy21.back().second == 6);
  // We do this so we can call const version of back()/front()
  kvfifo<int, int> const &constRef21 = originalObject;
  assert(constRef21.size() == 4);
  assert(constRef21.back().first == 4 && constRef21.back().second == 1);

  try {
    copy22.pop();
    assert(originalObject.k_begin() != copy22.k_begin());
  } catch (...) {
    assert(false && "Should not throw");
  }
  assert(copy22.size() == 3);
  assert(copy22.front().first == 2 && copy22.front().second == 1);
  kvfifo<int, int> const &constRef22 = originalObject;
  assert(constRef22.size() == 4);
  assert(constRef22.front().first == 1 && constRef22.front().second == 1);

  try {
    copy23.pop(4);
    assert(originalObject.k_begin() != copy23.k_begin());
  } catch (...) {
    assert(false && "Should not throw");
  }
  assert(copy23.size() == 3);
  assert(copy23.back().first == 3 && copy23.back().second == 1);
  kvfifo<int, int> const &constRef23 = originalObject;
  assert(constRef23.size() == 4);
  assert(constRef23.back().first == 4 && constRef23.back().second == 1);

  try {
    copy24.move_to_back(2);
    assert(originalObject.k_begin() != copy24.k_begin());
  } catch (...) {
    assert(false && "Should not throw");
  }
  assert(copy24.size() == 4);
  assert(copy24.back().first == 2 && copy24.back().second == 1);
  kvfifo<int, int> const &constRef24 = originalObject;
  assert(constRef24.size() == 4);
  assert(constRef24.back().first == 4 && constRef24.back().second == 1);

  auto &front25 = copy25.front().second;
  assert(originalObject.k_begin() != copy25.k_begin());
  front25 = 10;
  assert(copy25.size() == 4);
  assert(copy25.front().first == 1 && copy25.front().second == 10);
  kvfifo<int, int> const &constRef25 = originalObject;
  assert(constRef25.size() == 4);
  assert(constRef25.front().first == 1 && constRef25.front().second == 1);

  auto &back26 = copy26.back().second;
  assert(originalObject.k_begin() != copy26.k_begin());
  back26 = 12;
  assert(copy26.size() == 4);
  assert(copy26.back().first == 4 && copy26.back().second == 12);
  kvfifo<int, int> const &constRef26 = originalObject;
  assert(constRef26.size() == 4);
  assert(constRef26.back().first == 4 && constRef26.back().second == 1);

  auto &first27 = copy27.first(3).second;
  assert(originalObject.k_begin() != copy27.k_begin());
  first27 = 17;
  assert(copy27.size() == 4);
  assert(copy27.first(3).first == 3 && copy27.first(3).second == 17);
  kvfifo<int, int> const &constRef27 = originalObject;
  assert(constRef27.size() == 4);
  assert(constRef27.first(3).first == 3 && constRef27.first(3).second == 1);

  auto &last28 = copy28.last(3).second;
  assert(originalObject.k_begin() != copy28.k_begin());
  last28 = 18;
  assert(copy28.size() == 4);
  assert(copy28.last(3).first == 3 && copy28.last(3).second == 18);
  kvfifo<int, int> const &constRef28 = originalObject;
  assert(constRef28.size() == 4);
  assert(constRef28.last(3).first == 3 && constRef28.last(3).second == 1);

  copy29.clear();
  assert(originalObject.k_begin() != copy29.k_begin());
  assert(copy29.empty());
  assert(copy29.size() == 0);
  assert(!originalObject.empty());
  assert(originalObject.size() == 4);

  // Other tests that check if object are not copied if not necessary
  kvfifo<int, int> kvf;
  kvf.push(1, 1);
  kvf.push(2, 2);
  kvf.push(3, 3);
  kvf.push(4, 4);
  kvfifo<int, int> const &kvf1 = kvf;
  auto kvf2(kvf1);
  assert(kvf.k_begin() == kvf2.k_begin() && kvf.k_end() == kvf2.k_end());

  kvf1.front().second;
  assert(kvf.k_begin() == kvf2.k_begin() && kvf.k_end() == kvf2.k_end());

  kvf1.back().second;
  assert(kvf.k_begin() == kvf2.k_begin() && kvf.k_end() == kvf2.k_end());

  kvf1.first(2).second;
  assert(kvf.k_begin() == kvf2.k_begin() && kvf.k_end() == kvf2.k_end());

  kvf1.last(2).second;
  assert(kvf.k_begin() == kvf2.k_begin() && kvf.k_end() == kvf2.k_end());

  kvf1.size();
  assert(kvf.k_begin() == kvf2.k_begin() && kvf.k_end() == kvf2.k_end());

  kvf1.empty();
  assert(kvf.k_begin() == kvf2.k_begin() && kvf.k_end() == kvf2.k_end());

  kvf1.count(1);
  assert(kvf.k_begin() == kvf2.k_begin() && kvf.k_end() == kvf2.k_end());
}

// Exceptions
void kwasowTests3() {
  kvfifo<int, int> kvf1;

  bool exception1 = false;
  try {
    kvf1.pop();
  } catch (std::invalid_argument&) {
    exception1 = true;
  }
  assert(exception1);

  bool exception2 = false;
  try {
    kvf1.pop(1);
  } catch (std::invalid_argument&) {
    exception2 = true;
  }
  assert(exception2);

  bool exception3 = false;
  try {
    kvf1.move_to_back(1);
  } catch (std::invalid_argument&) {
    exception3 = true;
  }
  assert(exception3);

  bool exception4 = false;
  try {
    kvf1.front();
  } catch (std::invalid_argument&) {
    exception4 = true;
  }
  assert(exception4);

  bool exception5 = false;
  try {
    kvf1.back();
  } catch (std::invalid_argument&) {
    exception5 = true;
  }
  assert(exception5);

  bool exception6 = false;
  try {
    kvf1.first(1);
  } catch (std::invalid_argument&) {
    exception6 = true;
  }
  assert(exception6);

  bool exception7 = false;
  try {
    kvf1.last(1);
  } catch (std::invalid_argument&) {
    exception7 = true;
  }
  assert(exception7);

  kvfifo<int, int> const &kvfConst = kvf1;

  bool exception8 = false;
  try {
    kvfConst.front();
  } catch (std::invalid_argument&) {
    exception8 = true;
  }
  assert(exception8);

  bool exception9 = false;
  try {
    kvfConst.back();
  } catch (std::invalid_argument&) {
    exception9 = true;
  }
  assert(exception9);

  bool exception10 = false;
  try {
    kvfConst.first(1);
  } catch (std::invalid_argument&) {
    exception10 = true;
  }
  assert(exception10);

  bool exception11 = false;
  try {
    kvfConst.last(1);
  } catch (std::invalid_argument&) {
    exception11 = true;
  }
  assert(exception11);

  try {
    kvf1.k_begin();
  } catch (...) {
    assert(false);
  }

  try {
    kvf1.k_end();
  } catch (...) {
    assert(false);
  }
}

// Iterator tests
void kwasowTests4() {
  kvfifo<int, int> kvf1;
  kvf1.push(1, 1);
  kvf1.push(2, 1);
  kvf1.push(3, 1);
  kvf1.push(4, 1);
  kvf1.push(1, 2);
  kvf1.push(2, 2);
  kvf1.push(3, 2);
  kvf1.push(4, 2);

  int i = 1;;
  for (auto walk = kvf1.k_begin(); walk != kvf1.k_end(); ++walk) {
    assert(*walk == i);
    i++;
  }
  assert(i == 5);

  i = 1;
  for (auto walk = kvf1.k_begin(); walk != kvf1.k_end(); walk++) {
    assert(*walk == i);
    i++;
  }
  assert(i == 5);

  i = 4;
  auto walk = kvf1.k_end();
  do {
    --walk;
    assert(*walk == i);
    i--;
  } while (walk != kvf1.k_begin());
  assert(i == 0);

  i = 4;
  walk = kvf1.k_end();
  do {
    walk--;
    assert(*walk == i);
    i--;
  } while (walk != kvf1.k_begin());
  assert(i == 0);
}

// Test move constructor
void kwasowTests5() {
  kvfifo<int, int> kvf1;
  kvf1.push(1, 1);
  kvf1.push(2, 1);
  kvf1.push(3, 1);
  kvf1.push(4, 1);

  kvfifo<int, int> kvf2(std::move(kvf1));
  assert(!kvf2.empty());
  assert(kvf2.size() == 4);
  assert(kvf2.front().first == 1 && kvf2.front().second == 1);
  assert(kvf2.first(2).first == 2 && kvf2.first(2).second == 1);
  assert(kvf2.last(3).first == 3 && kvf2.last(3).second == 1);
  assert(kvf2.back().first == 4 && kvf2.back().second == 1);

  // We called std::move on kvf1 so the object is no longer valid, thus
  // any of these function calls should fail
  std::cout << "Finishing kwasowTests5..." << std::endl;
  std::cout << "The program should segfault now..." << std::endl;
  kvf1.empty();
  kvf1.size();
  kvf1.clear();
  kvf1.pop();
  kvf1.pop(2);
  kvf1.front();
  kvf1.back();
  kvf1.first(3);
  kvf1.last(3);
  kvf1.k_begin();
  kvf1.k_end();
}

} // namespace kwasow

#endif // KWASOW_H_
