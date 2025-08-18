## Modular Multiplicative Inverse

> source: [cp-algorithms](https://cp-algorithms.com/algebra/module-inverse.html)

Computes \\( xn \equiv 1 \pmod{m} \\) in \\( log(min(n, m)) \\), using the
[extended GCD](./extended_gcd.md).

```cpp
{{#include mod_inverse.hpp:11:14}}
```

### Modular Inverse of an Array

> source:
> [cp-algorithms](https://cp-algorithms.com/algebra/module-inverse.html#finding-the-modular-inverse-for-array-of-numbers-modulo-m)

Computes the modular inverse of every element of the vector module \\( m \\).

```cpp
{{#include mod_inverse.hpp:16:32}}
```

Dependencies.

```cpp
{{#include mod_inverse.hpp:5:9}}
```
