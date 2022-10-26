#include "gtest/gtest.h"
#include "hash.h"

#include <iostream>

namespace {

using ::std::data;

uint64_t hash_function(uint64_t const * v, size_t n) {
    uint64_t hash = 0;
    for (size_t k = 0; k < n; ++k)
      hash ^= v[k];
    return hash;
}

} /* anonymous namespace */

TEST(Official, General) {
    testing::internal::CaptureStderr();

    auto id = ::jnp1::hash_create(hash_function);
    EXPECT_EQ(::jnp1::hash_insert(id, data<uint64_t>({1, 3, 5, 9}), 4), true);

    EXPECT_EQ(::jnp1::hash_test(id, data<uint64_t>({9, 5, 3, 1}), 4), false);
    EXPECT_EQ(::jnp1::hash_insert(id, data<uint64_t>({9, 5, 3, 1}), 4), true);
    EXPECT_EQ(::jnp1::hash_test(id, data<uint64_t>({0, 1, 3, 5, 9}), 5), false);
    EXPECT_EQ(::jnp1::hash_size(id), 2);
    ::jnp1::hash_delete(id);
    EXPECT_EQ(::jnp1::hash_test(id, nullptr, 0), false);
    
    std::string output = testing::internal::GetCapturedStderr();
}
