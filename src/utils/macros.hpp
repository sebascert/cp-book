#include <limits>
#include <utility>
#include <vector>

using namespace std;

#define mid(l, r) ((l) + ((r) - (l)) / 2)
#define btl(p) ((p) * 2)     // binary tree buf left child
#define btr(p) ((p) * 2 + 1) // binary tree buf right child

#define INF(T, s) numeric_limits<T>::s() // s: min | max

#define alias_t(T, A)                                              \
  typedef T A;                                                     \
  const T POSINF = INF(T, max);                                    \
  const T NEGINF = INF(T, min);                                    \
  typedef vector<T> vec;                                           \
  typedef pair<T, T> pr;

#define all(v) v.begin(), v.end()
