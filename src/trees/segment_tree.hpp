#include <limits>
#include <vector>

using namespace std;

typedef long long lli;

#define sz(c) ((lli)(c).size())
#define fora(i, a, b) for(lli i = (a); (i) < (b); ++i) // [a -> b)
#define ford(i, a, b) for(lli i = (a); (i)-- > (b);)   // [b <- a)

#define mid(l, r) ((l) + ((r) - (l)) / 2)
#define btl(p) ((p) * 2)     // binary tree buf left child
#define btr(p) ((p) * 2 + 1) // binary tree buf right child
#define INF(T, s) numeric_limits<T>::s() // s: min | max

template <typename T> struct STree {
  struct N {                       // Node
    T s, mn;                       //@ state
    N(T x) : s(x), mn(x) {}        //@ elem to node
    N() : s(0), mn(INF(T, max)) {} //@ identities
    N op(N o) {                    // this operates over other
      o.s = s + o.s;               //@ operations
      o.mn = min(mn, o.mn);
      return o;
    }
  };
  lli n;
  vector<N> t;
  STree(vector<T> a) : n(sz(a)), t(n * 2) { // O(T)
    fora(i, 0, n) t[i + n] = N(a[i]);
    ford(i, n, 1) t[i] = t[btl(i)].op(t[btr(i)]);
  }
  void set(lli i, T x) { // O(logN)
    for(t[i += n] = N(x); i /= 2;)
      t[i] = t[btl(i)].op(t[btr(i) | 1]);
  }
  N query(lli i) { return t[i + n]; } // O(1)
  N query(lli l, lli r) {             // O(logN) [left, right)
    N lres, rres;
    for(l += n, r += n; l < r; l /= 2, r /= 2) {
      if(l & 1) lres = lres.op(t[l++]);
      if(r & 1) rres = t[--r].op(rres);
    }
    return lres.op(rres);
  }
};
