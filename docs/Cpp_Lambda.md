# Cpp_Lambda

> 从某处复制而来的,出处已经不可考.

Lambda函数（since C++11）

 

[C++](http://zh.cppreference.com/w/cpp) [C++语言](http://zh.cppreference.com/w/cpp/language) 

构造一个[闭包](http://en.wikipedia.com/wiki/Closure_(computer_science))：能在作用域内捕获变量一个的匿名函数对象。

语法

| [ capture ] ( params ) mutable exception attribute -> ret { body } | (1)  |
| ---------------------------------------- | ---- |
| [ capture ] ( params ) -> ret { body }   | (2)  |
| [ capture ] ( params ) { body }          | (3)  |
| [ capture ] { body }                     | (4)  |

1) 完整的声明

2)一个常lambda的声明：按副本捕获的对象不能被修改。

3)省略后缀返回值类型：闭包的operator()的返回值类型是根据以下规则推导出的：

- 如果body仅包含单一的return语句，那么返回值类型是返回表达式的类型（在此隐式转换之后的类型：右值到左值、数组与指针、函数到指针）
- 否则，返回类型是void

4) 省略参数列表：函数没有参数，即参数列表是()

解释

| mutable   | -    | 允许body修改传值进来的形参，以及调用它们的非常成员函数。           |
| --------- | ---- | ---------------------------------------- |
| exception | -    | 提供闭包类型的operator()成员函数的[异常说明](http://zh.cppreference.com/w/cpp/language/except_spec)或[noexcept语句](http://zh.cppreference.com/w/cpp/language/noexcept_spec) |
| attribute | -    | 提供闭包类型的operator()成员函数的[属性说明](http://zh.cppreference.com/w/cpp/language/attributes) |
| capture   | -    | 指定哪些在函数声明处的作用域中可见的符号将在函数体内可见。   符号表可按如下规则传入：       [a,&b]，按值捕获a，并按引用捕获b    [this]，按值捕获了[this指针](http://zh.cppreference.com/mwiki/index.php?title=this%E6%8C%87%E9%92%88&action=edit&redlink=1)    [&] 按引用捕获在lambda表达式所在函数的函数体中提及的全部自动储存持续性变量    [=] 按值捕获在lambda表达式所在函数的函数体中提及的全部自动储存持续性变量    [] 什么也没有捕获 |
| params    | -    | 参数列表，与[命名函数](http://zh.cppreference.com/w/cpp/language/function)一样 |
| ret       | -    | 返回值类型。如果不存在，它由该函数的return语句来隐式决定（或者是void，例如当它不返回任何值的时候） |
| body      | -    | 函数体                                      |

