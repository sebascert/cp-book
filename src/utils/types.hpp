#include <cstddef>
#include <ostream>

using namespace std;

typedef size_t size;
typedef long long lli;
typedef unsigned long long ull;
typedef long double ld;

struct Type {
  int x, y;

  Type operator*(const Type &o) const;
  bool operator==(const Type &o) const;

  friend ostream &operator<<(ostream &os, const Type &o);
  friend istream &operator>>(istream &is, Type &o);
};

namespace std {
template <> struct hash<Type> {
  size_t operator()(const Type &o) const {
    size_t h1 = hash<int>()(o.x), h2 = hash<int>()(o.y);
    return h1 ^ (h2 << 1); // Combine hashes of members
  }
};
} // namespace std
