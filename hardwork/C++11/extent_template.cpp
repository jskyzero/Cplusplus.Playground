#include <vector>
#include <string>

// 告诉编译器不要在该编译单元内将该模板实例化。
extern template class std::vector<std::string>;
// 强制编译器在特定位置开始实例化的语法
template class std::vector<std::string>;

int main() {
}