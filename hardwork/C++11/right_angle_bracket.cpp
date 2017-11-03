/*

当遇到连续的右角括号时，会在合理的情况下将右尖括号解析为模板引用的结束符号。
给使用>,>=,>>的表达式加上圆括号，可以避免其与圆括号外部的左尖括号相匹配：

*/

#include <vector>


template <bool b> class SomeType {};
std::vector<SomeType<(1 > 2)>> x1;

int main() {

}