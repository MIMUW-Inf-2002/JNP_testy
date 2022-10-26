#include "gtest/gtest.h"

// Include your tests here (include the source file, not header file)
#include "example.cc"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

