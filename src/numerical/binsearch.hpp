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
  while(l < r) {
    m = mid(l, r);
    p(m) ? r = m : l = m + 1;
  }
  return l; //@ l (last T or F) or r (first T or F)
}
template <typename R, typename I, typename P>
R binsearch(R rl, R rr, P p) { // O(32 or 64), 0 < l <= r
  I l = rcast(I, rl), r = rcast(I, rr), m;
  while(l < r) {
    m = mid(l, r);
    p(rcast(R, m)) ? r = m : l = m + 1;
  }
  return rcast(R, l); //@ l (last T or F) or r (first T or F)
} //@ either binsearch<f, ui32> or binsearch<lf, ui64>