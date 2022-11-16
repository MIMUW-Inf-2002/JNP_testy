#include <cassert>
#include <iostream>
#include <string>

#include "moneybag.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Peczar, official) {
  // You should capture stderr not to trash the test logs
  testing::internal::CaptureStdout();
	
	// Taka konstrukcja nie powinna się kompilować.
  // Moneybag m0;

  Moneybag m1 = Moneybag(1, 10, 19);
  Moneybag m2 = 2 * Solidus + 17 * Denier;
  Moneybag m3(0, 0, 0);
  Moneybag m4(m1);
  m4 = m3;

  cout << m3 << endl;
  cout << m4 + m2 - Solidus << endl;

  Moneybag::coin_number_t s = m2.solidus_number();
  ASSERT_TRUE(s == 2);

  ASSERT_TRUE(m1);
  ASSERT_TRUE(!m3);
  ASSERT_TRUE(m1 >= m2);
  ASSERT_TRUE(m1 > m2);
  ASSERT_TRUE(!(m1 < m2));
  ASSERT_TRUE(m4 == m3);

  ASSERT_TRUE(Moneybag(2, 2, 1) >= Moneybag(2, 1, 1));
  ASSERT_TRUE(Moneybag(2, 2, 1) > Moneybag(2, 1, 1));
  ASSERT_FALSE(Moneybag(1, 2, 2) <= Moneybag(2, 2, 1));
  ASSERT_FALSE(Moneybag(1, 2, 2) < Moneybag(2, 2, 1));

  m2 += 28 * Solidus + 2 * Denier;

  cout << m1 << endl;
  cout << m2 << endl;

  ASSERT_FALSE(m1 == m2);
  ASSERT_FALSE(m1 > m2);
  ASSERT_FALSE(m1 < m2);

  Value v1 = Value(m1);
  Value v2(m2);

  cout << static_cast<string>(v1) << endl;
  cout << string(Value(Livre)) << endl;

  ASSERT_TRUE(v1 == v2);
  ASSERT_TRUE(!is_neq(v1 <=> v2));
  ASSERT_TRUE(v1 == 379);
  ASSERT_TRUE(379 == v2);
  ASSERT_TRUE(v1 > 350);
  ASSERT_TRUE(350 < v2);
  ASSERT_TRUE(0 == Value());

  // Te konstrukcje nie powinny się kompilować.
  // Livre = Denier;
  // Denier = Solidus;
  // Solidus = Livre;
  // int k = Moneybag(1, 2, 3);
	
	// You may also get the captured string from stderr and compare it to something
  std::string output = testing::internal::GetCapturedStdout();
}
