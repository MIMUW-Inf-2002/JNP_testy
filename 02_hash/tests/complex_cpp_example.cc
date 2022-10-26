#include "gtest/gtest.h"
// hash.h will be copied into this directory by the testing script
#include "hash.h"

namespace example {

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  FooTest() {
     // You can do set-up work for each test here.
  }

  ~FooTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  // for Foo.
};

uint64_t hash_function(uint64_t const * v, size_t n) {
    uint64_t hash = 0;
    for (size_t k = 0; k < n; ++k)
      hash ^= v[k];
    return hash;
}

// Tests that the Foo::Bar() method does Abc.
TEST_F(FooTest, MethodBarDoesAbc) {
    testing::internal::CaptureStderr();

    auto id = jnp1::hash_create(hash_function);
    
    EXPECT_EQ(jnp1::hash_size(id), 0);

    jnp1::hash_delete(id);
    
    std::string output = testing::internal::GetCapturedStderr();
}

}  // namespace example

