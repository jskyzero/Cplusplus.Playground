/*

C++11将会把初始化列表的概念绑到类型上，称作std::initializer_list。
这允许构造函数或其他函数像参数般地使用初始化列表。

class SequenceClass
{
public:
  SequenceClass(std::initializer_list<int> list);
};

*/

#include <vector>
#include <string>

int main() {
  std::vector<std::string> v = {"hello", "world"};
}