typedef unsigned long long ull;

/*
type operator*(const type& a, const type& b);
*/

template <typename T> T binexp(T a, ull b) { // O(log(b))
  T res = 1;                                 //@ identity
  while(b > 0) {
    if(b & 1) res = res * a;
    a = a * a;
    b /= 2;
  }
  return res;
}

template <typename T> T binexp(T a, ull b, T m) { // O(log(b))
  a = a % m;
  T res = 1;
  while(b > 0) {
    if(b & 1) res = res * a % m;
    a = a * a % m;
    b /= 2;
  }
  return res;
}
