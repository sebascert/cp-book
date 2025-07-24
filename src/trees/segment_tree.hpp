#include <limits>
#include <vector>

using namespace std;

typedef size_t sz;

#define fora(i, a, b) for(sz i = (a); (i) < (b); ++i) // [a -> b)
#define ford(i, a, b) for(sz i = (a); --(i) > (b);)   // [b <- a]

#define mid(l, r) ((l) + ((r) - (l)) / 2)
#define btl(p) ((p) * 2)     // binary tree buf left child
#define btr(p) ((p) * 2 + 1) // binary tree buf right child
#define INF(T, s) numeric_limits<T>::s() // s: min | max

template <typename T> struct STree {
  struct Nd {
    T s, mn;                                          //@ state
    Nd(T s = 0, T mn = INF(T, max)) : s(s), mn(mn) {} //@ identities
    Nd op(Nd o) { //@ operations, this operates over other
      o.s = s + o.s;
      o.mn = min(mn, o.mn);
      return o;
    }
  };
  sz n;
  vector<Nd> t;
  STree(vector<T> a) : n(sz(a)), t(n * 2) {  // O(T)
    fora(i, 0, n) t[i + n] = Nd(a[i], a[i]); //@ elem to node
    ford(i, n - 1, 0) t[i] = t[btl(i)].op(t[btr(i)]);
  }
  void set(sz i, T x) { // O(logN)
    for(t[i += n] = x; i /= 2;) t[i] = t[btl(i)].op(t[btr(i) | 1]);
  }
  Nd query(sz i) { return t[i + n]; } // O(1)
  Nd query(sz l, sz r) {              // O(logN) [left, right)
    Nd lres, rres;
    for(l += n, r += n; l < r; l /= 2, r /= 2) {
      if(l & 1) lres = lres.op(t[l++]);
      if(r & 1) rres = t[--r].op(rres);
    }
    return lres.op(rres);
  }
};
