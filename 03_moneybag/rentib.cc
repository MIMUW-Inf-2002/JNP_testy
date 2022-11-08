#include <cassert>
#include <iostream>
#include <map>
#include <sstream>

#include "moneybag.h"

namespace test {

using namespace std;

void binary_operators() {
  Moneybag a(1, 1, 1);
  Moneybag b(2, 2, 2);
  a = a * 3 + a - b;
  b = b * 2 + a;
  assert(a < b);
  assert(a <= b);
  assert(!(a >= b));

  a = Moneybag(1, 1, 1);
  b = Moneybag(2, 2, 2);

  {
  bool exceptionThrown = false;
  try {
    a = a - b;
  } catch (...) {
    exceptionThrown = true;
  }
  assert(exceptionThrown);
  assert(a == Moneybag(1, 1, 1));
  }

  {
  bool exceptionThrown = false;
  try {
    a -= b;
  } catch (...) {
    exceptionThrown = true;
  }
  assert(exceptionThrown);
  assert(a == Moneybag(1, 1, 1));
  }

  b -= a;
  assert(a <= b);
  assert(a >= b);
  assert(a == b);
  assert(a * 213 == 213 * b);

  volatile int x = 2;
  assert(a * (bool)x == a);
  assert(a * (unsigned char)x == a + a);
  assert(a * (unsigned short)x == a + a);
  assert(a * (unsigned int)x == a + b - b + a);
  assert(a * (unsigned long)x == a + b);
  assert(a * (unsigned long long)x == a + b - a + b);
  assert(a * (uint8_t)x == a + a);
  assert(a * (uint16_t)x == a + b - b + a);
  assert(a * (uint32_t)x == a + b);
  assert(a * (uint64_t)x == a + b - a + b);
}

void comparision() {
  Moneybag a(1, 2, 3);
  Moneybag b(3, 2, 1);

  assert(!(a < b));
  assert(!(a > b));
  assert(!(a >= b));
  assert(!(a <= b));
  assert(!(a == b));

  a = Moneybag(1, 1, 1);
  b = a;
  assert(a <= b);
  assert(a >= b);
  assert(a == b);

  a = Moneybag(1, 1, 3);
  b = a * 2;
  assert(a < b);
  assert(a <= b);
  assert(!(a == b));

  Value v = Value(a);
  Value u(b);

  assert(v < u);
  assert(v <= u);
  assert(!(v == u));
  assert(!(v >= u));
  assert(!(v > u));

  assert(v < (1 << 8));
  assert(v > (1 << 8) - 2);
  assert(v == ~(~0 << 8));
}

void constructor() {
  Moneybag m1(1, 2, 3);
  Moneybag m2 = Moneybag(3, 2, 1);
  Moneybag m3(m1);
  Moneybag m4 = Solidus;
  m1 = m2;
  m3 = m4;
  Value v1(10);
  Value v2(m1);
  Value v3 = v1;
  v2 = v3;
}

void getters() {
  Moneybag a(1, 1, 1);
  assert(a.livre_number() == 1);
  assert(a.solidus_number() == 1);
  assert(a.denier_number() == 1);
  assert(a.livre_number() == Moneybag(1, 10, 100).livre_number());
  assert(a.solidus_number() == Moneybag(2, 5, 1).denier_number());
}

void strings() {
  Moneybag m(0, 0, 0);

  const string mout[4] = {
    "(1 livr, 2 soliduses, 2 deniers)",
    "(2 livres, 1 solidus, 2 deniers)",
    "(2 livres, 2 soliduses, 1 denier)",
    "(2 livres, 2 soliduses, 2 deniers)",
  };

  for (int i = 0; i < 4; i++) {
    stringstream buf;
    m = Moneybag(2 - (i == 0), 2 - (i == 1), 2 - (i == 2));
    buf << m;
    assert(buf.str() == mout[i]);
  }

  assert(string(Value(0)) == "0");
  assert(string(Value(~0)) == "18446744073709551615");
  assert(string(Value((uint8_t)~0)) == "255");
  assert(string(Value((uint16_t)~0)) == "65535");
  assert(string(Value((uint32_t)~0)) == "4294967295");
  assert(string(Value((uint64_t)~0)) == "18446744073709551615");
}

map<string, void (*)(void)> mp({
    {"binary_operators", binary_operators},
    {"comparision", comparision},
    {"constructor", constructor},
    {"getters", getters},
    {"strings", strings},
});

} // namespace test

int main() {
  for (auto [name, func] : test::mp) {
    std::cout << name << std::endl;
    func();
  }
  std::cout << "Przeszło wszystko\n";
}
