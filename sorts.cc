#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <inttypes.h>

#if defined(NONE)

inline bool swap_if(bool c, int&, int&) { return c; }

#elif defined(STD)
# define SORT std::sort
# define TYPE int

#elif defined(RADIX256)
# define SORT sort_radix256
# define TYPE unsigned

void sort_radix256(unsigned* begin, unsigned* end) {
  std::vector<int> buckets[256];
  for (auto& v : buckets) v.reserve((end - begin)/128);
  for (int byte = 0; byte != sizeof(unsigned); ++byte) {
    for (unsigned* p = begin; p != end; ++p) {
      buckets[*p & 0xff].push_back((*p >> 8) | (*p << 24));
    }
    unsigned* p = begin;
    for (auto& v : buckets) {
      std::memcpy(p, v.data(), v.size() * sizeof(unsigned));
      p += v.size();
      v.clear();
} } }

#elif defined(RADIX2)
# define SORT sort_radix2
# define TYPE unsigned

void sort_radix2(unsigned* begin, unsigned* end) {
  std::vector<unsigned> a_buckets[2];
  for (auto& v : a_buckets) v.reserve((end - begin)/3);
  int i = 0;
  for (; i < (end - begin) / 2; ++i) a_buckets[0].push_back(begin[i]);
  for (; i < (end - begin); ++i) a_buckets[1].push_back(begin[i]);

  std::vector<unsigned> b_buckets[2];
  for (auto& v : b_buckets) v.reserve((end - begin)/3);

  for (int bit = 0; bit != 8 * sizeof(unsigned); ++bit) {
    for (int j = 0; j != 2; ++j) {
      for (unsigned v : a_buckets[j]) {
        b_buckets[v & 0x1].push_back((v >> 1) | (v << 31));
      }
    }
    std::swap(a_buckets[0], b_buckets[0]), b_buckets[0].clear();
    std::swap(a_buckets[1], b_buckets[1]), b_buckets[1].clear();
  }

  for (unsigned v : a_buckets[0]) *begin++ = v;
  for (unsigned v : a_buckets[1]) *begin++ = v;
}

#elif defined(BOG)

inline bool swap_if(bool c, int& a, int& b) {
  if (c) {
    int ta = a; a = b; b = ta;
  }
  return c;
}

#elif defined(ANDANDOR)

inline bool swap_if(bool c, int& a, int& b) {
  int ta = a, mask = -c;  // false -> 0, true -> 111..111
  a = (b & mask) | (ta & ~mask);
  b = (ta & mask) | (b & ~mask);
  return c;
}

#elif defined(INDEXED)

inline bool swap_if(bool c, int& a, int& b) {
  int v[2] = { a, b };
  b = v[1-c], a = v[c];
  return c;
}

#elif defined(ROT)

inline bool swap_if(bool c, int& a, int& b) {
  uint64_t both = (uint64_t(uint32_t(a)) << 32) | uint32_t(b);
  int shift = int(c) << 5;
  both = (both >> shift) | (both << (64 - shift));
  b = int(uint32_t(both & 0xffffffff)), a = int(both >> 32);
  return c;
}

#elif defined(CMOV)

inline bool swap_if(bool c, int& a, int& b) {
  int ta = a, tb = b;
  a = c ? tb : ta;
  b = c ? ta : tb;
  return c;
}

#elif defined(INDEXED_PESSIMAL_ON_HASWELL)

inline bool swap_if(bool c, int& a, int& b) {
  int v[2] = { a, b };
  b = v[!c], a = v[c];
  return c;
}

#elif defined(INDEXED_ALT1)

inline bool swap_if(bool c, int** sides) {
  int a = *sides[c], b = *sides[1-c];
  *sides[0] = a, *sides[1] = b;
  return c;
}

#elif defined(INDEXED_ALT2)

inline bool swap_if(bool c, int** sides) {
  int a = *sides[0], b = *sides[1];
  *sides[c] = a, *sides[1-c] = b;
  return c;
}

#endif

#ifndef SORT
# define SORT quicksort
# define TYPE int

int* partition(int* begin, int* end) {
  int pivot = end[-1];
  int* sides[2] = { begin, begin };
  for (; sides[1] < end - 1; ++sides[1]) {
#if defined(INDEXED_ALT1) || defined(INDEXED_ALT2)
    sides[0] += swap_if(*sides[1] <= pivot, sides);
#else
    sides[0] += swap_if(*sides[1] <= pivot, *sides[0], *sides[1]);
#endif
  }
  int tmp = *sides[0]; *sides[0] = end[-1], end[-1] = tmp;
  return sides[0];
}

void quicksort(int* begin, int* end) {
  while (end - begin > 1) {
    int* mid = partition(begin, end);
    quicksort(begin, mid);
    begin = mid + 1;
} }

#endif  // SORT

static const int size = 100'000'000;

int main(int, char**) {
  int fd = ::open("1e8ints", O_RDONLY);
  int perms = PROT_READ|PROT_WRITE;
  int flags = MAP_PRIVATE|MAP_POPULATE|MAP_NORESERVE;
  auto* a = (TYPE*) ::mmap(nullptr, size * sizeof(TYPE), perms, flags, fd, 0);

  SORT(a, a + size);

#ifndef CHECK
  return a[0] == a[size - 1];
#else
  auto* ar = (TYPE*) ::mmap(nullptr, size * sizeof(TYPE), perms, flags, fd, 0);
  std::sort(ar, ar + size);
  return std::memcmp(a, ar, size * sizeof(TYPE));
#endif
}
