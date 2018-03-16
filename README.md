# Cplusplus-Study
`jskyzero` `2017/11/01`

![cpp_logo.png](https://isocpp.org/files/img/cpp_logo.png)

## Overview

C++ is a general-purpose programming language. It has imperative, object-oriented and generic programming features, while also providing facilities for low-level memory manipulation.

C++ is standardized by the International Organization for Standardization (ISO), with the latest standard version ratified and published by ISO in December 2014 as ISO/IEC 14882:2014 (informally known as C++14). The C++ programming language was initially standardized in 1998 as ISO/IEC 14882:1998, which was then amended by the C++03, ISO/IEC 14882:2003, standard.

## Structure
```
├── docs                        // documents
├── hardwork
│   ├── C++11                   // C++11 new feature
│   ├── C++17                   // C++17 new feature
│   ├── hardway                 // practice code
│   ├── helloworld              // first program
│   ├── leetcode                // leetcode Online Judge codes
│   ├── sicily                  // sicily Online Judge codes
│   ├── sicily_datastructure    // sicily Online Judge codes about DSA
│   ├── STL                     // quick example of stl
│   └── tips                    // some syntax tips
├── LICENSE
├── projects
│   ├── Agenda                  // A mvc structured meeting manage system 
│   ├── CMake                   // Learn to use CMake
│   └── OpenCV                  // Open Source Computer Vision Library Study
└── README.md
```

## Naming Style
+ File Names: Filenames should be all lowercase and can include underscores (\_) or dashes (-). Follow the convention that your project uses. If there is no consistent local pattern to follow, prefer "_".
+ Type Names: Type names start with a capital letter and have a capital letter for each new word, with no underscores: `MyExcitingClass`, `MyExcitingEnum`.
+ Variable Names: The names of variables (including function parameters) and data members are all lowercase, with underscores between words. Data members of classes (but not structs) additionally have trailing underscores. For instance: `a_local_variable`, `a_struct_data_member`, `a_class_data_member_`.
+ Constant Names: Variables declared constexpr or const, and whose value is fixed for the duration of the program, are named with a leading "k" followed by mixed case. `const int kDaysInAWeek = 7;`
+ Function Names:
  + Regular functions have mixed case; accessors and mutators may be named like variables.
  + Ordinarily, functions should start with a capital letter and have a capital letter for each new word.
+ Namespace Names: Namespace names are all lower-case. Top-level namespace names are based on the project name . Avoid collisions between nested namespaces and well-known top-level namespaces.
+ Enumerator Names: 
  + Enumerators (for both scoped and unscoped enums) should be named either like constants or like macros: either kEnumName or ENUM_NAME.
  + Preferably, the individual enumerators should be named like constants. However, it is also acceptable to name them like macros. The enumeration name, UrlTableErrors (and AlternateUrlTableErrors), is a type, and therefore mixed case.
    ```Cplusplus
    enum UrlTableErrors {
      kOK = 0,
      kErrorOutOfMemory,
      kErrorMalformedInput,
    };
    enum AlternateUrlTableErrors {
      OK = 0,
      OUT_OF_MEMORY = 1,
      MALFORMED_INPUT = 2,
    };
    ```


## Reference

+ [Get Start](https://isocpp.org/get-started)
+ [cplusplus.com](http://www.cplusplus.com/)
+ [isocpp](https://isocpp.org).
+ [Google Style Naming](https://google.github.io/styleguide/cppguide.html#Naming)
