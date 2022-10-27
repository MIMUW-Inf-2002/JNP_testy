#include "gtest/gtest.h"
#include "hash.h"

namespace {

uint64_t hash_function(uint64_t const * v, size_t n) {
    uint64_t hash = 0;
    for (size_t k = 0; k < n; ++k)
      hash ^= v[k];
    return hash;
}

}

TEST(Example, Create) {
    // You should capture stderr not to trash the test logs
    testing::internal::CaptureStderr();

    auto id = jnp1::hash_create(hash_function);
    
    EXPECT_EQ(jnp1::hash_size(id), 0);

    jnp1::hash_delete(id);
    
    // You may also get the captured string from stderr and compare it to something
    std::string output = testing::internal::GetCapturedStderr();
}
