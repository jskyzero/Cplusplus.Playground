出处大概是cppreference

# Fast leaning C++

## Compilers

machine language, compiler and it's linker, use -std=c++0x



## Structure of a program

comments is important



## Variables and types

1. valid identifier: a sequence of one or more letters, digits, or underscore characters, identifier shall always begin with a letter (include underscore characters)

```C++
alignas, alignof, and, and_eq, asm, auto, bitand, bitor, bool, break, case, catch, char, char16_t, char32_t, class, compl, const, constexpr, const_cast, continue, decltype, default, delete, do, double, dynamic_cast, else, enum, explicit, export, extern, false, float, for, friend, goto, if, inline, int, long, mutable, namespace, new, noexcept, not, not_eq, nullptr, operator, or, or_eq, private, protected, public, register, reinterpret_cast, return, short, signed, sizeof, static, static_assert, static_cast, struct, switch, template, this, thread_local, throw, true, try, typedef, typeid, typename, union, unsigned, using, virtual, void, volatile, wchar_t, while, xor, xor_eq
```

2.

| Size   | Unique representable values  | Notes                       |
| ------ | ---------------------------- | --------------------------- |
| 8-bit  | `256`                        | = 28                        |
| 16-bit | `65 536`                     | = 216                       |
| 32-bit | `4 294 967 296`              | = 232 (~4 billion)          |
| 64-bit | `18 446 744 073 709 551 616` | = 264 (~18 billion billion) |

3. Type deduction: `auto` and `decltype`

```C++
int foo = 0;
auto bar = foo;  // the same as: int bar = foo; 
```

```C++
int foo = 0;
decltype(foo) bar;  // the same as: int bar; 
```



## Constants

1. Literals: 
   1. Integer Numerals(0 / 0x / U / L / LL) 
   2. Floating Point Numerals(F / L) 
   3. Character and string literals(backslash / u  `char16_t` /  U `char32_t`  / L `wchar_t` / u8 / R)
   4. Other literals(true / false / nullptr)
2. Typed constant expressions(const)
3. Preprocessor definitions (#define)

## Operator

1. Comma operator ( , )

For example, the following code:
` a = (b=3, b+2);`

would first assign the value 3 to `b`, and then assign `b+2` to variable `a`. So, at the end, variable `a` would contain the value 5 while variable `b` would contain value 3

2. Bitwise operator( &, |, ^, ~, <<, >>)

| `&`  | `AND` | Bitwise AND                      |
| ---- | ----- | -------------------------------- |
| `\|` | `OR`  | Bitwise inclusive OR             |
| `^`  | `XOR` | Bitwise exclusive OR             |
| `~`  | `NOT` | Unary complement (bit inversion) |
| `<<` | `SHL` | Shift bits left                  |
| `>>` | `SHR` | Shift bits right                 |

3. Explicit type casting operator

```C++
int i;
float f = 3.14;
i = (int) f;
```

4. sizeof

## Basic Input/Output

1. stringstream

```C++
// stringstreams
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
  string mystr;
  float price=0;
  int quantity=0;

  cout << "Enter price: ";
  getline (cin,mystr);
  stringstream(mystr) >> price;
  cout << "Enter quantity: ";
  getline (cin,mystr);
  stringstream(mystr) >> quantity;
  cout << "Total price: " << price*quantity << endl;
  return 0;
}
```

## Statements and flow control

1. for 
2. while
3. do while
4. break continue
5. switch

## Function

1. Return value

| value          | description                              |
| -------------- | ---------------------------------------- |
| `0`            | The program was successful               |
| `EXIT_SUCCESS` | The program was successful (same as above).This value is defined in header ``. |
| `EXIT_FAILURE` | The program failed.This value is defined in header ``. |

2. Arguments passed by value and by reference
3. Efficiency considerations and const reference
4. Inline functions 

```
inline string concatenate (const string& a, const string& b)
{
  return a+b;
}
```

5. default value in parameters( last value )

## Overloads and templates

1. The compiler knows which one to call in each case by examining the types passed as arguments
2. `template  <template-parameters> function-declaration` 

```C++
template <class SomeType>
SomeType sum (SomeType a, SomeType b)
{
  return a+b;
}
```

```C++
// template arguments
#include <iostream>

using namespace std;

template <class T, int N>
T fixed_multiply (T val)
{
  return val * N;
}

int main() {
  std::cout << fixed_multiply<int,2>(10) << '\n';
  std::cout << fixed_multiply<int,3>(10) << '\n';
}
```

## Name visibility

1. Scope ( global, local )
2. Namespaces
3. `using namespace::name`
4. `namespace new_name = current_name;`
5. Storage classes

```
- Variables with static storage (such as global variables) that are not explicitly initialized are automatically initialized to zeroes.
- Variables with automatic storage (such as local variables) that are not explicitly initialized are left uninitialized, and thus have an undetermined value.
```

## Arrays

```C++
// The initializer can even have no values, just the braces:
 int baz [5] = { }; 
// This creates an array of five int values, each initialized with a value of zero:
```

`Library arrays`

```C++
#include <iostream>
#include <array>

using namespace std;

int main()
{
  array<int,3> myarray {10,20,30};

  for (int i=0; i<myarray.size(); ++i)
    ++myarray[i];

  for (int elem : myarray)
    cout << elem << '\n';
}
```

## Character sequences

## Pointers

```
*p++   // same as *(p++): increment pointer, and dereference unincremented address
*++p   // same as *(++p): increment pointer, and dereference incremented address
++*p   // same as ++(*p): dereference pointer, and increment the value it points to
(*p)++ // dereference pointer, and post-increment the value it points to 
```

```
int x;
      int *       p1 = &x;  // non-const pointer to non-const int
const int *       p2 = &x;  // non-const pointer to const int
      int * const p3 = &x;  // const pointer to non-const int
const int * const p4 = &x;  // const pointer to const int 
```

```
int (* minus)(int,int) = subtraction;
```

## Dynamic memory

1. Operators new and new[]

```C++
int * foo;
foo = new int [5];
```

2. Operators delete and delete[]

```C++
delete pointer;
delete[] pointer;
```

3. Dynamic memory in C

```
with the functions malloc, calloc, realloc and free, defined in the header <cstdlib>
```

## Data structures

Structure

| Expression | What is evaluated                        | Equivalent |
| ---------- | ---------------------------------------- | ---------- |
| `a.b`      | Member `b` of object `a`                 |            |
| `a->b`     | Member `b` of object pointed to by `a`   | `(*a).b`   |
| `*a.b`     | Value pointed to by member `b` of object `a` | `*(a.b)`   |

## Other data types

1. type aliases ( Typedef / using )

```c++
typedef existing_type new_type_name ;
typedef char C;
typedef unsigned int WORD;
typedef char * pChar;
typedef char field [50]; 
```

```C++
using new_type_name = existing_type ;
using C = char;
using WORD = unsigned int;
using pChar = char *;
using field = char [50]
```

2. Unions

```c++
union mytypes_t {
  char c;
  int i;
  float f;
} mytypes;
mytypes.c
mytypes.i
mytypes.f
```

3. Enumerated types ( enum )

```c++
enum type_name {
  value1,
  value2,
  value3,
  .
  .
} object_names;
```
## Class

1. Overloading constructors
2. Uniform initialization

```C++
// classes and uniform initialization
#include <iostream>



using namespace std;

class Circle {
    double radius;
  public:
    Circle(double r) { radius = r; }
    double circum() {return 2*radius*3.14159265;}
};

int main () {
  Circle foo (10.0);   // functional form
  Circle bar = 20.0;   // assignment init.
  Circle baz {30.0};   // uniform init.
  Circle qux = {40.0}; // POD-like

  cout << "foo's circumference: " << foo.circum() << '\n';
  return 0;
}
```

3.Pointer

| expression | can be read as                           |
| ---------- | ---------------------------------------- |
| `*x`       | pointed to by `x`                        |
| `&x`       | address of `x`                           |
| `x.y`      | member `y` of object `x`                 |
| `x->y`     | member `y` of object pointed to by `x`   |
| `(*x).y`   | member `y` of object pointed to by `x` (equivalent to the previous one) |
| `x[0]`     | first object pointed to by `x`           |
| `x[1]`     | second object pointed to by `x`          |
| `x[n]`     | (`n+1`)th object pointed to by `x`       |

4.Overloading Operators

Overloadable operators : `+    -    *    /    =    <    >    +=   -=   *=   /=   <<   >> <<=  >>=  ==   !=   <=   >=   ++   --   %    &    ^    !    \|~    &=   ^=   \|=   &&   \|\|   %=   []   ()   ,    ->*  ->   new delete    new[]     delete[]` 

```C++
// overloading operators example
#include <iostream>

using namespace std;

class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int a,int b) : x(a), y(b) {}
    CVector operator + (const CVector&);
};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

int main () {
  CVector foo (3,1);
  CVector bar (1,2);
  CVector result;
  result = foo + bar;
  cout << result.x << ',' << result.y << '\n';
  return 0;
}
```

5. The keyword this

```c++
CVector& CVector::operator= (const CVector& param)
{
  x=param.x;
  y=param.y;
  return *this;
}
```

6. Static members

```c++
// static members in classes
#include <iostream>

using namespace std;

class Dummy {
  public:
    static int n;
    Dummy () { n++; };
};

int Dummy::n=0;

int main () {
  Dummy a;
  Dummy b[5];
  cout << a.n << '\n';
  Dummy * c = new Dummy;
  cout << Dummy::n << '\n';
  delete c;
  return 0;
}
```

7. Const member functions

```c++
int get() const {return x;}        // const member function
const int& get() {return x;}       // member function returning a const&
const int& get() const {return x;} // const member function returning a const& 
```

8. Class template

```c++
// class templates
#include <iostream>

using namespace std;

template <class T>
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

int main () {
  mypair <int> myobject (100, 75);
  cout << myobject.getmax();
  return 0;
}
```

9. Special members

| Member function                          | typical form for class `C`: |
| ---------------------------------------- | --------------------------- |
| [Default constructor](http://www.cplusplus.com/doc/tutorial/classes2/#default_constructor) | `C::C();`                   |
| [Destructor](http://www.cplusplus.com/doc/tutorial/classes2/#destructor) | `C::~C();`                  |
| [Copy constructor](http://www.cplusplus.com/doc/tutorial/classes2/#copy_constructor) | `C::C (const C&);`          |
| [Copy assignment](http://www.cplusplus.com/doc/tutorial/classes2/#copy_assignment) | `C& operator= (const C&);`  |
| [Move constructor](http://www.cplusplus.com/doc/tutorial/classes2/#move) | `C::C (C&&);`               |
| [Move assignment](http://www.cplusplus.com/doc/tutorial/classes2/#move) | `C& operator= (C&&);`       |

## Friendship and inheritance

1. Friend function
2. Friend class
3. Inheritance between classes

## Polymorphism

1. Pointer to base class
2. Virtual members
3. Abstract base classes

## Type conversions

## Exceptions

## Preprocessor directives

## Input/Output with files