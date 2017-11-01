## History
> From Wikipedia

+ In 1979, Bjarne Stroustrup, a Danish computer scientist, began work on "C with Classes", the predecessor to C++.
+ Initially, Stroustrup's "C with Classes" added features to the C compiler, Cpre, including classes, derived classes, strong typing, inlining and default arguments
+ In 1983, "C with Classes" was renamed to "C++" (++ being the increment operator in C), adding new features that included virtual functions, function name and operator overloading, references, constants, type-safe free-store memory allocation (new/delete), improved type checking, and BCPL style single-line comments with two forward slashes (//). Furthermore, it included the development of a standalone compiler for C++, Cfront.
+ In 1985, the first edition of The C++ Programming Language was released, which became the definitive reference for the language, as there was not yet an official standard.
+ In 1989, C++ 2.0 was released, followed by the updated second edition of The C++ Programming Language in 1991. New features in 2.0 included multiple inheritance, abstract classes, static member functions, const member functions, and protected members. In 1990, The Annotated C++ Reference Manual was published. This work became the basis for the future standard. Later feature additions included templates, exceptions, namespaces, new casts, and a boolean type.
+ After the 2.0 update, C++ evolved relatively slowly until, in 2011, the C++11 standard was released, adding numerous new features, enlarging the standard library further, and providing more facilities to C++ programmers. After a minor C++14 update released in December 2014, various new additions are planned for July 2017 and 2020
+ As of 2017, C++ remains the third most popular programming language, behind Java and C

## Versions

+ find out your version
  ```
  g++ -dM -E -x c++ /dev/null | grep -F __cplusplus
  ```
+ use `-std=c++98` to use c++98

