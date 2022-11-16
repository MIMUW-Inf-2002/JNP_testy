#include <functional>
#include <sstream>
#include <vector>

#include "moneybag.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Rentib, binary_operators) {
  Moneybag a(1, 1, 1);
  Moneybag b(2, 2, 2);
  a = a * 3 + a - b;
  b = b * 2 + a;
  ASSERT_TRUE(a < b);
  ASSERT_TRUE(a <= b);
  ASSERT_FALSE(a >= b);

  a = Moneybag(1, 1, 1);
  b = Moneybag(2, 2, 2);

  auto e1 = [&]() { a = a - b; };
  auto e2 = [&]() { a -= b; };
  auto e3 = [&]() { a += Moneybag(~0, ~0, ~0); };
  auto e4 = [&]() { a += Moneybag(~0, 0, 0); };
  auto e5 = [&]() { a += Moneybag(0, ~0, 0); };
  auto e6 = [&]() { a += Moneybag(0, 0, ~0); };
  auto e7 = [&]() { a = ((a * 2) * ~0); };
  auto e8 = [&]() { a = (a * ~0) + b; };

  vector<function<void()>> exc({e1, e2, e3, e4, e5, e6, e7, e8});

  for (auto e : exc) {
    bool exceptionThrown = false;
    try {
      e();
    } catch (...) {
      exceptionThrown = true;
    }
    ASSERT_TRUE(exceptionThrown);
    ASSERT_EQ(a, Moneybag(1, 1, 1));
  }

  b -= a;
  ASSERT_TRUE(a <= b);
  ASSERT_TRUE(a >= b);
  ASSERT_EQ(a, b);
  ASSERT_EQ(a * 213, 213 * a);
  ASSERT_EQ(a * 213, 213 * b);
  ASSERT_EQ(a * ~0, ~0 * b);

  volatile int x = 2;
  ASSERT_EQ(a * (bool)x, a);
  ASSERT_EQ(a * (unsigned char)x, a + a);
  ASSERT_EQ(a * (unsigned short)x, a + a);
  ASSERT_EQ(a * (unsigned int)x, a + b - b + a);
  ASSERT_EQ(a * (unsigned long)x, a + b);
  ASSERT_EQ(a * (unsigned long long)x, a + b - a + b);
  ASSERT_EQ(a * (uint8_t)x, a + a);
  ASSERT_EQ(a * (uint16_t)x, a + b - b + a);
  ASSERT_EQ(a * (uint32_t)x, a + b);
  ASSERT_EQ(a * (uint64_t)x, a + b - a + b);
}

TEST(Rentib, comparision) {
  Moneybag a(1, 2, 3);
  Moneybag b(3, 2, 1);

  ASSERT_TRUE((bool)Moneybag(1, 2, 3));
  ASSERT_TRUE((bool)Moneybag(~0, 0, 0));
  ASSERT_TRUE((bool)Moneybag(~0, 0, 1));
  ASSERT_TRUE((bool)Moneybag(~0, ~0, 1));
  ASSERT_FALSE((bool)Moneybag(0, 0, 0));

  ASSERT_FALSE(a < b);
  ASSERT_FALSE(a > b);
  ASSERT_FALSE(a >= b);
  ASSERT_FALSE(a <= b);
  ASSERT_FALSE(a == b);

  a = Moneybag(1, 1, 1);
  b = a;
  ASSERT_TRUE(a <= b);
  ASSERT_TRUE(a >= b);
  ASSERT_TRUE(a == b);

  a = Moneybag(1, 1, 3);
  b = a * 2;
  ASSERT_TRUE(a < b);
  ASSERT_TRUE(a <= b);
  ASSERT_TRUE(a != b);
  b = a;
  b *= 2;
  assert(a < b);
  assert(a <= b);
  assert(!(a == b));

  Value v = Value(a);
  Value u(b);

  ASSERT_TRUE(v < u);
  ASSERT_TRUE(v <= u);
  ASSERT_FALSE(v == u);
  ASSERT_FALSE(v >= u);
  ASSERT_FALSE(v > u);

  ASSERT_TRUE(v < (1 << 8));
  ASSERT_TRUE(v > (1 << 8) - 2);
  ASSERT_TRUE(v == ~(~0 << 8));

  v = Value(Moneybag(~0, 0, 0));
  u = Value(Moneybag(0, ~0, 0));

  ASSERT_TRUE(v > u);
  ASSERT_TRUE(v >= u);
  ASSERT_TRUE(v != u);
}

TEST(Rentib, constructor) {
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

TEST(Rentib, getters) {
  Moneybag a(1, 1, 1);
  ASSERT_EQ(a.livre_number(), 1);
  ASSERT_EQ(a.solidus_number(), 1);
  ASSERT_EQ(a.denier_number(), 1);
  ASSERT_EQ(a.livre_number(), Moneybag(1, 10, 100).livre_number());
  ASSERT_EQ(a.solidus_number(), Moneybag(2, 5, 1).denier_number());
}

TEST(Rentib, strings) {
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
    ASSERT_EQ(buf.str(), mout[i]);
  }

  ASSERT_EQ(string(Value(0)), "0");
  ASSERT_EQ(string(Value(~0)), "18446744073709551615");
  ASSERT_EQ(string(Value((uint8_t)~0)), "255");
  ASSERT_EQ(string(Value((uint16_t)~0)), "65535");
  ASSERT_EQ(string(Value((uint32_t)~0)), "4294967295");
  ASSERT_EQ(string(Value((uint64_t)~0)), "18446744073709551615");
  ASSERT_EQ(string(Value(Moneybag(~0, ~0, ~0))), "4667026250648516558595");
}
