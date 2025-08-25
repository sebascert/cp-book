#include <vector>

using namespace std;

typedef long long lli;

#define fora(i, a, b) for(lli i = (a); (i) < (b); ++i) // [a -> b)

template <typename T> struct DSU {
  struct Mt {
    T r;   //@ state
    Mt() { //@ initial state
      r = 1;
    }
  };
  vector<T> p;  // parents
  vector<Mt> m; // metadata
  // O(N)
  DSU(T n) : p(n), m(n) { fora(i, 0, n) p[i] = i; }
  // O(1)
  T find(T x) { return p[x] == x ? x : (p[x] = find(p[x])); }
  bool unite(T x, T y) { // O(1)
    T xrt = find(x), yrt = find(y);
    if(xrt == yrt) return false;
    if(m[xrt].r < m[yrt].r) swap(xrt, yrt);
    m[xrt].r += m[yrt].r; //@ update state
    p[yrt] = xrt;
    return true;
  }
  Mt &meta(T x) { return m[find(x)]; } // O(1)
};
