/*


在标准C++中，枚举类型不是类型安全的。
枚举类型被视为整数，这使得两种不同的枚举类型之间可以进行比较。
C++03唯一提供的安全机制是一个整数或一个枚举型值不能隐式转换到另一个枚举别型。
此外，枚举所使用整数类型及其大小都由实现方法定义，皆无法明确指定。
最后，枚举的名称全数暴露于枚举类型的作用域中，
  因此两个不同的枚举，不可以有相同的枚举名。（
  好比enum Side{ Right, Left }; 和 enum Thing{ Wrong, Right }; 
  不能一起使用。）


*/

enum class myEnumeration
{
  Val1,
  Val2,
  Val3 = 100,
  Val4 /* = 101 */,
};

enum class Enum2 : unsigned int {Val1, Val2};

int main() {
  
}