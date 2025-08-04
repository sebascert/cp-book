## Binary Exponentiation

> source:
> [cp-algorithms](https://cp-algorithms.com/algebra/binary-exp.html#implementation)

Generic binary exponentiation to compute \\( b^N \\) in \\( O(logN) \\). Any
type with the `T * T` operator defined can be used. In case the type does not
have an identity value simply exponentiate until \\( N-1 \\) and set the initial
value of `res` to the base.

```cpp
{{#include binexp.hpp:7:15}}
```

Dependencies.

```cpp
{{#include binexp.hpp:1}}
{{#include binexp.hpp:4}}
```

### Computation of Exponents Modulo a Number

> source:
> [cp-algorithms](https://cp-algorithms.com/algebra/binary-exp.html#effective-computation-of-large-exponents-modulo-a-number)

Compute \\( x^N mod m \\) efficiently. Any type which can be used in the
previous `binexp` can also be used in the modular version, with the additional
constraint of needing to define the `T % T` operator defined.

```cpp
{{#include binexp.hpp:17:26}}
```
