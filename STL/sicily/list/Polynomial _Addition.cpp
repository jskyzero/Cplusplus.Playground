#include <iostream>
#include <map>

class polynomial {
 public:
  polynomial();
  friend polynomial operator+(const polynomial &p, const polynomial &q);
  friend std::ostream &operator<<(std::ostream &output, const polynomial &p);
  friend std::istream &operator>>(std::istream &input, polynomial &p);
  std::map<int, int, std::greater<int>> data;

 private:
};
std::ostream &operator<<(std::ostream &output, const polynomial &p);
std::istream &operator>>(std::istream &input, polynomial &p);

polynomial::polynomial() {}

polynomial operator+(const polynomial &p, const polynomial &q) {
  polynomial temp_polynomial;
  for (auto x : p.data) {
    if (temp_polynomial.data.find(x.first) == temp_polynomial.data.end()) {
      temp_polynomial.data[x.first] = x.second;
    } else {
      temp_polynomial.data[x.first] += x.second;
    }
  }
  for (auto x : q.data) {
    if (temp_polynomial.data.find(x.first) == temp_polynomial.data.end()) {
      temp_polynomial.data[x.first] = x.second;
    } else {
      temp_polynomial.data[x.first] += x.second;
    }
  }

  for (auto x : temp_polynomial.data) {
    if (x.second == 0) {
      temp_polynomial.data.erase(temp_polynomial.data.find(x.first));
    }
  }
  return temp_polynomial;
}

std::ostream &operator<<(std::ostream &output, const polynomial &p) {
  output << p.data.size() << std::endl;
  for (auto x : p.data) {
    output << x.second << " " << x.first << std::endl;
  }
}
std::istream &operator>>(std::istream &input, polynomial &p) {
  int num = 0, key = 0, value = 0;
  input >> num;
  while (num--) {
    input >> value >> key;
    p.data[key] = value;
  }
}

int main() {
  int num = 0;
  // std::stringstream ss;
  // ss << "2 2 1 2 3 0 3 1 9 -2 5 -3 0 2 2 4 1 0 0";
  std::cin >> num;
  while (num--) {
    polynomial a, b;
    std::cin >> a;
    std::cin >> b;
    std::cout << a + b;
  }
  return 0;
}