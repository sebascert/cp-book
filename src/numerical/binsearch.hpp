#include <cstdint>

#define mid(l, r) ((l) + ((r) - (l)) / 2)

#define rcast(T, V) reinterpret_cast<T &>(V)

typedef float f;
typedef double lf;

typedef uint32_t ui32;
typedef uint64_t ui64;

template <typename T, typename P> // P is a predicate
T binsearch(T l, T r, P p) {      // O(log(r-l)) [l r]
  T m;
  while(r > l + 1) {
    m = mid(l, r);
    (p(m) ? r : l) = m; //@ r:l (T:F) or l:r (T:F)
  }
  return m; //@ l (last T or F) or r (first T or F)
}

template <typename R, typename I, typename P>
R binsearch(R l, R r, P p) { // O(32 or 64), 0 < l <= r
  I _l = rcast(I, l), _r = rcast(I, r), m;
  while(l < r) {
    m = mid(_l, _r);
    if(p(rcast(R, m))) r = m;
    else
      l = m + 1;
  }
  return rcast(R, m);
} //@ either binsearch<f, ui32> or binsearch<lf, ui64>
