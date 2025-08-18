#include <tuple>

using namespace std;

template <typename T>
T gcd(T x, T y, T &a, T &b) { // O(log(min(x, y)))
  a = 1, b = 0;
  T aa = 0, bb = 1, xx = x, yy = y;
  while(yy) {
    T q = xx / yy;
    tie(a, aa) = make_tuple(aa, a - q * aa);
    tie(b, bb) = make_tuple(bb, b - q * bb);
    tie(xx, yy) = make_tuple(yy, xx - q * yy);
  }
  return xx;
}
