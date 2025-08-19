## Binary Search

> source: NA

Generic binary search over interval \\( [L, R] \\), in \\( O(log(R-L)) \\).

```cpp
{{#include binsearch.hpp:13:21}}
```

Dependencies.

```cpp
{{#include binsearch.hpp:3}}
```

### Binary Search Over the Reals

> source: [codeforces blog](https://codeforces.com/blog/entry/63085)

Generic binary search on reals over interval \\( [L, R] \\), using a
representation of \\( N \\) bits, in \\( O(log(2^N)) = O(N) \\). This only works
for positive numbers.

```cpp
{{#include binsearch.hpp:23:33}}
```

Dependencies.

```cpp
{{#include binsearch.hpp:3:11}}
```
