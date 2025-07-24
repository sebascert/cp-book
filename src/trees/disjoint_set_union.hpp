#include <vector>

using namespace std;

typedef size_t sz;

#define fora(i, a, b) for(sz i = (a); (i) < (b); ++i) // [a -> b)

struct DSU {
  struct Mt {
    sz r;  //@ state
    Mt() { //@ initial state
      r = 1;
    }
  };
  vector<sz> p; // parents
  vector<Mt> m; // metadata
  // O(N)
  DSU(sz n) : p(n), m(n) { fora(i, 0, n) p[i] = i; }
  // O(1)
  sz find(sz x) { return p[x] == x ? x : (p[x] = find(p[x])); }
  bool unite(sz x, sz y) { // O(1)
    sz xrt = find(x), yrt = find(y);
    if(xrt == yrt) return false;
    if(m[xrt].r < m[yrt].r) swap(xrt, yrt);
    m[xrt].r += m[yrt].r; //@ update state
    p[yrt] = xrt;
    return true;
  }
  Mt &meta(sz x) { return m[find(x)]; } // O(1)
};
