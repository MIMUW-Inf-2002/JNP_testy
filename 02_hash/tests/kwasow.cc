#include "gtest/gtest.h"
#include "hash.h"
#include <string>
#include <sstream>

namespace {

uint64_t hash_function_very_bad(uint64_t const * v, size_t n) {
    return 0;
}

uint64_t hash_function_pretty_bad(uint64_t const * v, size_t n) {
    uint64_t hash = 0;
    for (size_t k = 0; k < n; ++k)
      hash ^= v[k];
    return hash;
}

uint64_t hash_function_good(uint64_t const * v, size_t n) {
    uint64_t hash = 0;
    for (size_t k = 0; k < n; ++k)
      hash = (hash * 79 + v[k]) % 694202137;
    return hash;
}

}

// Different hash tables use different hash functions
TEST(Kwasow, Multiple1) {
    // You should capture stderr not to trash the test logs
    testing::internal::CaptureStderr();
    
    long unsigned int size1 = 3;
    long unsigned int size2 = 3;
    long unsigned int size3 = 3;
    auto array1 = new uint64_t[size1]{1, 2, 3};
    auto array2 = new uint64_t[size2]{1, 3, 2};
    auto array3 = new uint64_t[size3]{3, 2, 1};

    auto id1 = jnp1::hash_create(hash_function_very_bad);
    auto id2 = jnp1::hash_create(hash_function_pretty_bad);
    auto id3 = jnp1::hash_create(hash_function_good);
    
    // Test insertion
    ASSERT_TRUE(jnp1::hash_insert(id1, array1, size1));
    ASSERT_EQ(jnp1::hash_size(id1), 1);
    ASSERT_EQ(jnp1::hash_size(id2), 0);
    ASSERT_EQ(jnp1::hash_size(id3), 0);
    ASSERT_TRUE(jnp1::hash_insert(id2, array2, size2));
    ASSERT_EQ(jnp1::hash_size(id1), 1);
    ASSERT_EQ(jnp1::hash_size(id2), 1);
    ASSERT_EQ(jnp1::hash_size(id3), 0);
    ASSERT_TRUE(jnp1::hash_insert(id3, array3, size3));
    ASSERT_EQ(jnp1::hash_size(id1), 1);
    ASSERT_EQ(jnp1::hash_size(id2), 1);
    ASSERT_EQ(jnp1::hash_size(id3), 1);
    if (id1 != 100 && id2 != 100 && id3 != 100) {
      ASSERT_FALSE(jnp1::hash_insert(100, array1, size1));
    }
    
    ASSERT_TRUE(jnp1::hash_test(id1, array1, size1));
    ASSERT_FALSE(jnp1::hash_test(id1, array2, size2));
    ASSERT_FALSE(jnp1::hash_test(id1, array3, size3));
    
    ASSERT_FALSE(jnp1::hash_test(id2, array1, size1));
    ASSERT_TRUE(jnp1::hash_test(id2, array2, size2));
    ASSERT_FALSE(jnp1::hash_test(id2, array3, size3));
    
    ASSERT_FALSE(jnp1::hash_test(id3, array1, size1));
    ASSERT_FALSE(jnp1::hash_test(id3, array2, size2));
    ASSERT_TRUE(jnp1::hash_test(id3, array3, size3));
    
    if (id1 != 100 && id2 != 100 && id3 != 100) {
      ASSERT_FALSE(jnp1::hash_insert(100, array1, size1));
    }
    
    // Test removal
    ASSERT_FALSE(jnp1::hash_remove(id1, array2, size2));
    ASSERT_TRUE(jnp1::hash_remove(id1, array1, size1));
    ASSERT_EQ(jnp1::hash_size(id1), 0);
    ASSERT_EQ(jnp1::hash_size(id2), 1);
    ASSERT_EQ(jnp1::hash_size(id3), 1);
    
    // Test clear
    jnp1::hash_clear(id2);
    ASSERT_EQ(jnp1::hash_size(id1), 0);
    ASSERT_EQ(jnp1::hash_size(id2), 0);
    ASSERT_EQ(jnp1::hash_size(id3), 1);
    
    // Test deleting
    jnp1::hash_delete(id1);
    jnp1::hash_delete(id2);
    jnp1::hash_delete(id3);
    
    ASSERT_FALSE(jnp1::hash_test(id1, array1, size1));
    ASSERT_FALSE(jnp1::hash_test(id1, array2, size2));
    ASSERT_FALSE(jnp1::hash_test(id1, array3, size3));
    ASSERT_FALSE(jnp1::hash_test(100, array3, size3));

    ASSERT_EQ(jnp1::hash_size(id1), 0);
    ASSERT_EQ(jnp1::hash_size(id2), 0);
    ASSERT_EQ(jnp1::hash_size(id3), 0);

    ASSERT_FALSE(jnp1::hash_insert(id1, array1, size1));
    ASSERT_FALSE(jnp1::hash_insert(id2, array2, size2));
    ASSERT_FALSE(jnp1::hash_insert(id3, array3, size3));
    
    delete array1;
    delete array2;
    delete array3;
    
    // You may also get the captured string from stderr and compare it to something
    std::string output = testing::internal::GetCapturedStderr();
}

// Different hash tables use the same hash function
TEST(Kwasow, Multiple2) {
    // You should capture stderr not to trash the test logs
    testing::internal::CaptureStderr();

    long unsigned int size = 3;
    auto array = new uint64_t[size]{1, 2, 3};

    auto id1 = jnp1::hash_create(hash_function_very_bad);
    auto id2 = jnp1::hash_create(hash_function_very_bad);

    ASSERT_TRUE(jnp1::hash_insert(id1, array, size));
    ASSERT_EQ(jnp1::hash_size(id1), 1);
    ASSERT_EQ(jnp1::hash_size(id2), 0);

    ASSERT_TRUE(jnp1::hash_insert(id2, array, size));
    ASSERT_EQ(jnp1::hash_size(id1), 1);
    ASSERT_EQ(jnp1::hash_size(id2), 1);

    jnp1::hash_delete(id1);
    ASSERT_EQ(jnp1::hash_size(id1), 0);
    ASSERT_EQ(jnp1::hash_size(id2), 1);

    jnp1::hash_delete(id2);
    ASSERT_EQ(jnp1::hash_size(id1), 0);
    ASSERT_EQ(jnp1::hash_size(id2), 0);

    delete array;
    
    // You may also get the captured string from stderr and compare it to something
    std::string output = testing::internal::GetCapturedStderr();
}

TEST(Kwasow, Persistence) {
    // You should capture stderr not to trash the test logs
    testing::internal::CaptureStderr();

    long unsigned int size = 3;
    auto array1 = new uint64_t[size]{1, 2, 3};
    auto array2 = new uint64_t[size]{1, 2, 3};

    auto id = jnp1::hash_create(hash_function_good);

    ASSERT_TRUE(jnp1::hash_insert(id, array1, size));
    ASSERT_TRUE(jnp1::hash_test(id, array2, size));
    ASSERT_EQ(jnp1::hash_size(id), 1);

    // Oh no, we delete the array, how sad :((
    delete array1;

    ASSERT_TRUE(jnp1::hash_test(id, array2, size));
    ASSERT_FALSE(jnp1::hash_insert(id, array2, size));
    ASSERT_EQ(jnp1::hash_size(id), 1);
    ASSERT_TRUE(jnp1::hash_remove(id, array2, size));
    ASSERT_EQ(jnp1::hash_size(id), 0);
    jnp1::hash_delete(id);

    delete array2;
    
    // You may also get the captured string from stderr and compare it to something
    std::string output = testing::internal::GetCapturedStderr();
}

// Logging
TEST(Kwasow, Logging) {
    std::string correct, output;

    long unsigned int size = 3;
    auto array1 = new uint64_t[size]{1, 2, 3};
    auto array2 = new uint64_t[size]{1, 1, 1};

    testing::internal::CaptureStderr();
    auto id = jnp1::hash_create(hash_function_good);
    output = testing::internal::GetCapturedStderr();
    
    // Add something
    testing::internal::CaptureStderr();
    jnp1::hash_insert(id, array1, size);
    correct = "hash_insert(" + std::to_string(id) + ", \"1 2 3\", 3)\nhash_insert: hash table #" + std::to_string(id) + ", sequence \"1 2 3\" inserted\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // Add something that is already in there
    testing::internal::CaptureStderr();
    jnp1::hash_insert(id, array1, size);
    correct = "hash_insert(" + std::to_string(id) + ", \"1 2 3\", 3)\nhash_insert: hash table #" + std::to_string(id) + ", sequence \"1 2 3\" was present\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // Test size
    testing::internal::CaptureStderr();
    jnp1::hash_size(id);
    correct = "hash_size(" + std::to_string(id) + ")\nhash_size: hash table #" + std::to_string(id) + " contains 1 element(s)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // Test if present (yes)
    testing::internal::CaptureStderr();
    jnp1::hash_test(id, array1, size);
    correct = "hash_test(" + std::to_string(id) + ", \"1 2 3\", 3)\nhash_test: hash table #" + std::to_string(id) + ", sequence \"1 2 3\" is present\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // Test if present (no)
    testing::internal::CaptureStderr();
    jnp1::hash_test(id, array2, size);
    correct = "hash_test(" + std::to_string(id) + ", \"1 1 1\", 3)\nhash_test: hash table #" + std::to_string(id) + ", sequence \"1 1 1\" is not present\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // Remove existing
    testing::internal::CaptureStderr();
    jnp1::hash_remove(id, array1, size);
    correct = "hash_remove(" + std::to_string(id) + ", \"1 2 3\", 3)\nhash_remove: hash table #" + std::to_string(id) + ", sequence \"1 2 3\" removed\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // Remove not existing
    testing::internal::CaptureStderr();
    jnp1::hash_remove(id, array1, size);
    correct = "hash_remove(" + std::to_string(id) + ", \"1 2 3\", 3)\nhash_remove: hash table #" + std::to_string(id) + ", sequence \"1 2 3\" was not present\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_insert(id, array1, size);
    output = testing::internal::GetCapturedStderr();

    testing::internal::CaptureStderr();
    jnp1::hash_clear(id);
    correct = "hash_clear(" + std::to_string(id) + ")\nhash_clear: hash table #" + std::to_string(id) + " cleared\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_clear(id);
    correct = "hash_clear(" + std::to_string(id) + ")\nhash_clear: hash table #" + std::to_string(id) + " was empty\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_delete(id);
    correct = "hash_delete(" + std::to_string(id) + ")\nhash_delete: hash table #" + std::to_string(id) + " deleted\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());
}

// Incorrect input with loggging
TEST(Kwasow, Incorrect) {
    std::string correct, output;

    long unsigned int size = 3;
    auto array = new uint64_t[size]{1, 2, 3};
    auto emptyArray = new uint64_t[0];

    // Test all functions before creating a hash table
    testing::internal::CaptureStderr();
    jnp1::hash_delete(0);
    correct = "hash_delete(0)\nhash_delete: hash table #0 does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_size(0);
    correct = "hash_size(0)\nhash_size: hash table #0 does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_insert(0, array, size);
    correct = "hash_insert(0, \"1 2 3\", 3)\nhash_insert: hash table #0 does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_remove(0, array, size);
    correct = "hash_remove(0, \"1 2 3\", 3)\nhash_remove: hash table #0 does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_clear(0);
    correct = "hash_clear(0)\nhash_clear: hash table #0 does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_test(0, array, size);
    correct = "hash_test(0, \"1 2 3\", 3)\nhash_test: hash table #0 does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // Create hash table
    testing::internal::CaptureStderr();
    auto id = jnp1::hash_create(hash_function_good);
    output = testing::internal::GetCapturedStderr();
    auto wrongId = id + 1;

    // NULL arrays
    testing::internal::CaptureStderr();
    jnp1::hash_insert(id, nullptr, size);
    correct = "hash_insert(" + std::to_string(id) + ", NULL, 3)\nhash_insert: invalid pointer (NULL)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_remove(id, nullptr, size);
    correct = "hash_remove(" + std::to_string(id) + ", NULL, 3)\nhash_remove: invalid pointer (NULL)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_test(id, nullptr, size);
    correct = "hash_test(" + std::to_string(id) + ", NULL, 3)\nhash_test: invalid pointer (NULL)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // Incorrect ids
    testing::internal::CaptureStderr();
    jnp1::hash_delete(wrongId);
    correct = "hash_delete(" + std::to_string(wrongId) + ")\nhash_delete: hash table #" + std::to_string(wrongId) + " does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_size(wrongId);
    correct = "hash_size(" + std::to_string(wrongId) + ")\nhash_size: hash table #" + std::to_string(wrongId) + " does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_insert(wrongId, array, size);
    correct = "hash_insert(" + std::to_string(wrongId) + ", \"1 2 3\", 3)\nhash_insert: hash table #" + std::to_string(wrongId) + " does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_remove(wrongId, array, size);
    correct = "hash_remove(" + std::to_string(wrongId) + ", \"1 2 3\", 3)\nhash_remove: hash table #" + std::to_string(wrongId) + " does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_clear(wrongId);
    correct = "hash_clear(" + std::to_string(wrongId) + ")\nhash_clear: hash table #" + std::to_string(wrongId) + " does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_test(wrongId, array, size);
    correct = "hash_test(" + std::to_string(wrongId) + ", \"1 2 3\", 3)\nhash_test: hash table #" + std::to_string(wrongId) + " does not exist\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // NULL arrays and incorrect ids
    testing::internal::CaptureStderr();
    jnp1::hash_insert(wrongId, nullptr, size);
    correct = "hash_insert(" + std::to_string(wrongId) + ", NULL, 3)\nhash_insert: hash table #" + std::to_string(wrongId) + " does not exist\nhash_insert: invalid pointer (NULL)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_remove(wrongId, nullptr, size);
    correct = "hash_remove(" + std::to_string(wrongId) + ", NULL, 3)\nhash_remove: hash table #" + std::to_string(wrongId) + " does not exist\nhash_remove: invalid pointer (NULL)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_test(wrongId, nullptr, size);
    correct = "hash_test(" + std::to_string(wrongId) + ", NULL, 3)\nhash_test: hash table #" + std::to_string(wrongId) + " does not exist\nhash_test: invalid pointer (NULL)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // Incorrect size (0)
    testing::internal::CaptureStderr();
    jnp1::hash_insert(id, emptyArray, 0);
    correct = "hash_insert(" + std::to_string(id) + ", \"\", 0)\nhash_insert: invalid size (0)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_remove(id, emptyArray, 0);
    correct = "hash_remove(" + std::to_string(id) + ", \"\", 0)\nhash_remove: invalid size (0)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_test(id, emptyArray, 0);
    correct = "hash_test(" + std::to_string(id) + ", \"\", 0)\nhash_test: invalid size (0)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // NULL arrays and incorrect sizes (0)
    testing::internal::CaptureStderr();
    jnp1::hash_insert(id, nullptr, 0);
    correct = "hash_insert(" + std::to_string(id) + ", NULL, 0)\nhash_insert: invalid pointer (NULL)\nhash_insert: invalid size (0)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_remove(id, nullptr, 0);
    correct = "hash_remove(" + std::to_string(id) + ", NULL, 0)\nhash_remove: invalid pointer (NULL)\nhash_remove: invalid size (0)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_test(id, nullptr, 0);
    correct = "hash_test(" + std::to_string(id) + ", NULL, 0)\nhash_test: invalid pointer (NULL)\nhash_test: invalid size (0)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    // Incorrect id, NULL array, incorrect size (0)
    testing::internal::CaptureStderr();
    jnp1::hash_insert(wrongId, nullptr, 0);
    correct = "hash_insert(" + std::to_string(wrongId) + ", NULL, 0)\nhash_insert: hash table #" + std::to_string(wrongId) + " does not exist\nhash_insert: invalid pointer (NULL)\nhash_insert: invalid size (0)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_remove(wrongId, nullptr, 0);
    correct = "hash_remove(" + std::to_string(wrongId) + ", NULL, 0)\nhash_remove: hash table #" + std::to_string(wrongId) + " does not exist\nhash_remove: invalid pointer (NULL)\nhash_remove: invalid size (0)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());

    testing::internal::CaptureStderr();
    jnp1::hash_test(wrongId, nullptr, 0);
    correct = "hash_test(" + std::to_string(wrongId) + ", NULL, 0)\nhash_test: hash table #" + std::to_string(wrongId) + " does not exist\nhash_test: invalid pointer (NULL)\nhash_test: invalid size (0)\n";
    output = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(output.c_str(), correct.c_str());
}

// Are colisions handled?
TEST(Kwasow, Colisions) {
    // You should capture stderr not to trash the test logs
    testing::internal::CaptureStderr();

    long unsigned int size = 4;
    auto array1 = new uint64_t[size]{1, 2, 3, 4};
    auto array2 = new uint64_t[size]{2, 2, 3, 3};
    auto array3 = new uint64_t[size]{4, 1, 7, 10};
    auto array4 = new uint64_t[size]{1, 1, 1, 1};

    auto id = jnp1::hash_create(hash_function_very_bad);

    ASSERT_TRUE(jnp1::hash_insert(id, array1, size));
    ASSERT_TRUE(jnp1::hash_insert(id, array2, size));
    ASSERT_TRUE(jnp1::hash_insert(id, array3, size));

    ASSERT_TRUE(jnp1::hash_test(id, array1, size));
    ASSERT_TRUE(jnp1::hash_test(id, array2, size));
    ASSERT_TRUE(jnp1::hash_test(id, array3, size));
    ASSERT_FALSE(jnp1::hash_test(id, array4, size));

    ASSERT_FALSE(jnp1::hash_remove(id, array4, size));
    ASSERT_TRUE(jnp1::hash_remove(id, array1, size));

    ASSERT_FALSE(jnp1::hash_test(id, array1, size));
    ASSERT_TRUE(jnp1::hash_test(id, array2, size));
    ASSERT_TRUE(jnp1::hash_test(id, array3, size));
    ASSERT_FALSE(jnp1::hash_test(id, array4, size));

    ASSERT_EQ(jnp1::hash_size(id), 2);
    jnp1::hash_clear(id);
    ASSERT_EQ(jnp1::hash_size(id), 0);
    jnp1::hash_delete(id);

    delete array1;
    delete array2;
    delete array3;
    delete array4;
    
    // You may also get the captured string from stderr and compare it to something
    std::string output = testing::internal::GetCapturedStderr();
}

// TODO
// A general more complex test, but only using one hash table
// TEST(Kwasow, Complex) {
//     // You should capture stderr not to trash the test logs
//     testing::internal::CaptureStderr();
    
//     // You may also get the captured string from stderr and compare it to something
//     std::string output = testing::internal::GetCapturedStderr();
// }
