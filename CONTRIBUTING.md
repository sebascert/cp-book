# Contributing

## Dependencies

- [dprint-latest](https://github.com/dprint/dprint).
- [clang-format-18](https://clang.llvm.org/docs/ClangFormat.html)
- [gtest-latest](https://github.com/google/googletest)

## Formatting

Always format the sources (markdown and hpp's) before committing, do so by
running:

```bash
make format
```

## Adding a DSA

Each DSA implementation must have 3 things:

- Implementation in `src/category/**/<dsa>.hpp`.
- Markdown paged in `src/category/**/<dsa>.md`.
- Test in `test/category/**/<dsa>.cpp`.

> The only exception is the template, which is a `.cpp` and has no tests.

Make sure the test for the DSA passes before commitittng.

### DSA Implementations

Follow this template for every DSA implementation:

- Have a clear track of dependencies.
- Avoid classes, no need for encapsulation.
- Always use templates when needed, they help to avoid type errors, for example
  integer overflows.
- Add `//@` comments to lines which may get changed during DSA usage.

```cpp
#include ...

// template macros and typedefs
typedef long long lli;
#define fora(i, a, b) for(sz i = (a); (i) < (b); ++i) // [a -> b)

// non template macros and typedefs
#define mid(l, r) ((l) + ((r) - (l)) / 2)

template <typename T> struct DataStructure {
    ...
}
template <typename T> int algorithm(T params...) {
    ...
}
```

### DSA Markdown Page

Make sure to include the following in the markdown page of each DSA:

- Source of the implementation.
- Code snippet with the implementation of the DSA, only with content for
  transcribing on competition time.
- Code snippet with dependencies on macros and typedefs.

Use this
[guide](https://rust-lang.github.io/mdBook/format/mdbook.html#including-files)
for including snippets.

```md
## DSA

> source: [src](link-to-source)

Quick explanation.

<!--dsa code snippet-->

Dependencies.

<!--dsa dependencies code snippet-->
```
