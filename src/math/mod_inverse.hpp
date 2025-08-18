#include <vector>

using namespace std;

typedef long long lli;

#define ford(i, a, b) for(lli i = (a); (i)-- > (b);) // [b <- a)

template <typename T> T gcd(T x, T y, T &a, T &b);

template <typename T> T invs(T n, T m) { // O(log(min(n, m)))
  T a, b;
  return gcd(n, m, a, b) == 1 ? (a % m + m) % m : 0;
}

template <typename T>
vector<T> invs(const vector<T> &v, T m) { // O(v)
  T n = v.size(), c = 1, a, b;
  if(n == 0) return {};

  vector<T> r(n);
  for(lli i = 0; i != n; ++i)
    r[i] = c, c = static_cast<T>(c) * v[i] % m;

  gcd(c, m, a, b);
  a = (a % m + m) % m;
  ford(i, n, 0) {
    r[i] = static_cast<T>(a) * r[i] % m;
    a = static_cast<T>(a) * v[i] % m;
  }
  return r;
}
