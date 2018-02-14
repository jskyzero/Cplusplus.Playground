#include <iostream>

template <typename T>
struct Point{
  T x, y;
  Point(T x = 0, T y = 0) : x(x), y(y) {}
};

template <typename T>
Point<T> operator + (Point<T> left, Point<T> right) {
  return Point<T>(left.x + right.x, left.y + right.y);
}

template <typename T>
std::ostream& operator << (std::ostream & out, const Point<T> & p) {
  out << "(" << p.x << "," << p.y << ")";
  return out;
}

int main() {
  Point<double> p1(1.0, 2.0), p2(1.1, 2.2);
  std::cout << p1 + p2 << std::endl;
}