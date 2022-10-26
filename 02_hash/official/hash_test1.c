#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include "hash.h"

#define SIZE_SEQ(seq) (sizeof seq / sizeof seq[0])

static uint64_t hash_function_1(uint64_t const * v, size_t n) {
  uint64_t hash = 0;
  for (size_t k = 0; k < n; ++k)
    hash ^= v[k];
  return hash;
}

static uint64_t hash_function_2(uint64_t const * v, size_t n) {
  uint64_t hash = 0;
  for (size_t k = 0; k < n; ++k)
    hash += v[k];
  return hash;
}

int main() {
  unsigned long id_1, id_2;
  uint64_t const seq_1[] = {0, 1, 3000, 150, 25};
  uint64_t const seq_2[] = {25, 3000, 150, 1, 0};
  uint64_t const seq_3[] = {-1, 0, 250};

  id_1 = hash_create(hash_function_1);
  assert(hash_size(id_1) == 0);

  assert(hash_insert(id_1, seq_1, SIZE_SEQ(seq_1)));
  assert(hash_size(id_1) == 1);
  assert(hash_insert(id_1, seq_2, SIZE_SEQ(seq_2)));
  assert(hash_size(id_1) == 2);
  assert(!hash_insert(id_1, seq_1, SIZE_SEQ(seq_1)));
  assert(hash_size(id_1) == 2);
  assert(!hash_insert(id_1, NULL, 0));
  assert(!hash_insert(id_1, NULL, 1));
  assert(!hash_insert(id_1, seq_3, 0));

  assert(hash_test(id_1, seq_2, SIZE_SEQ(seq_2)));
  assert(!hash_test(id_1, seq_3, SIZE_SEQ(seq_3)));
  assert(!hash_test(id_1, NULL, 0));
  assert(!hash_test(id_1, NULL, 1));
  assert(!hash_test(id_1, seq_1, 0));
  assert(!hash_test(id_1, seq_1, SIZE_SEQ(seq_1) - 1));

  assert(hash_remove(id_1, seq_1, SIZE_SEQ(seq_1)));
  assert(hash_size(id_1) == 1);
  assert(hash_insert(id_1, seq_3, SIZE_SEQ(seq_3)));
  assert(hash_size(id_1) == 2);
  assert(!hash_remove(id_1, seq_1, SIZE_SEQ(seq_1)));
  assert(!hash_remove(id_1, NULL, 0));
  assert(!hash_remove(id_1, NULL, 1));
  assert(!hash_remove(id_1, seq_2, 0));

  id_2 = hash_create(hash_function_2);
  assert(hash_insert(id_2, seq_2, SIZE_SEQ(seq_2)));
  assert(hash_insert(id_2, seq_3, SIZE_SEQ(seq_3)));

  hash_clear(id_1);
  assert(hash_size(id_1) == 0);

  assert(hash_remove(id_2, seq_2, SIZE_SEQ(seq_2)));
  assert(hash_size(id_2) == 1);
  assert(hash_remove(id_2, seq_3, SIZE_SEQ(seq_3)));
  assert(hash_size(id_2) == 0);

  hash_clear(id_2);
  assert(hash_size(id_2) == 0);

  hash_delete(id_1);
  assert(!hash_insert(id_1, seq_1, SIZE_SEQ(seq_1)));
  assert(!hash_remove(id_1, seq_1, SIZE_SEQ(seq_1)));
  assert(!hash_test(id_1, seq_1, SIZE_SEQ(seq_1)));
  hash_clear(id_1);
  assert(hash_size(id_1) == 0);
  hash_delete(id_1);

  hash_delete(id_2);
}
