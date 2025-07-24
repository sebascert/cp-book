# Contributing

## Dependencies

- [dprint](https://github.com/dprint/dprint).
- [clang-format](https://clang.llvm.org/docs/ClangFormat.html)
- [gtest](https://github.com/google/googletest)

## Formatting

Always format the sources (markdown and hpp's) before commiting, do so by running:

```bash
make format
```

## Adding a DSA

Each DSA implementation must have 3 things:

- Implementation in `src/category/**/<dsa>.hpp`.
- Markdown paged in `src/category/**/<dsa>.md`.
- Test in `test/category/**/<dsa>.cpp`.

The markdown page must contain the code snippet of only the code relevant at
the time of transcribing it, include it following this
[guide](https://rust-lang.github.io/mdBook/format/mdbook.html#including-files).

Make sure the test for the DSA passes before commiting.
