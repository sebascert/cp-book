#include <cstdint>

#define mid(l, r) ((l) + ((r) - (l)) / 2)

#define rcast(T, V) reinterpret_cast<T &>(V)

typedef float f;
typedef double lf;

typedef uint32_t ui32;
typedef uint64_t ui64;

template <typename T>
T binsearch(T l, T r, bool (*p)(T)) { // O(log(r-l))
  T m;
  while(r > l + 1) {
    m = mid(l, r);
    (p(m) ? r : l) = m;
  }
  return m; //@ l (lastF) or r (firstT)
}

template <typename R, typename I>     //@ <f, ui32> or <lf, ui64>
R binsearch(R l, R r, bool (*p)(R)) { // O(32 or 64), 0 < l <= r
  I _l = rcast(I, l), _r = rcast(I, r), m;
  while(l < r) {
    m = mid(_l, _r);
    if(p(rcast(R, m))) r = m;
    else
      l = m + 1;
  }
  return rcast(R, m);
}
