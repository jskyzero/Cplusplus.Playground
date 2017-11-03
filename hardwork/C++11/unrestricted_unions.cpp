/*

在C++03中，并非任意的类型都能做为union的成员。
  比方说，带有non-trivial 构造函数的类型就不能是union的成员。
在新的标准里，移除了所有对union的使用限制，
  除了其成员仍然不能是引用类型。
这一改变使得union更强大，更有用，也易于使用

*/

struct point
{
  point() {}
  point(int x, int y): x_(x), y_(y) {}
  int x_, y_;
};
union u1
{
	 int z;
	 double w;
	 point p;  // 不合法的C++; point有一non-trivial建構式
             // 合法的C++11

	 u1(int x, int y):p(x,y) {}; 
};

int main() {

}