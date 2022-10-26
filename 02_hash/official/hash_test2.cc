#ifdef NDEBUG
#undef NDEBUG
#endif

#include <cassert>
#include <vector>
#include "hash.h"

namespace {

  using ::std::data;

  uint64_t hash_function(uint64_t const * v, size_t n) {
    uint64_t hash = 0;
    for (size_t k = 0; k < n; ++k)
      hash ^= v[k];
    return hash;
  }

  unsigned long test() {
    unsigned long id = ::jnp1::hash_create(hash_function);
    assert(::jnp1::hash_insert(id, data<uint64_t>({1, 3, 5, 9}), 4));
    return id;
  }

  unsigned long id = test();

} /* anonymous namespace */

int main() {
  assert(!::jnp1::hash_test(id, data<uint64_t>({9, 5, 3, 1}), 4));
  assert(::jnp1::hash_insert(id, data<uint64_t>({9, 5, 3, 1}), 4));
  assert(!::jnp1::hash_test(id, data<uint64_t>({0, 1, 3, 5, 9}), 5));
  assert(::jnp1::hash_size(id) == 2);
  ::jnp1::hash_delete(id);
  assert(!::jnp1::hash_test(id, nullptr, 0));
}
