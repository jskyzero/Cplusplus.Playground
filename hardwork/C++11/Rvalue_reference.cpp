// the cstdint header is part of the C++11 standard
// #include <cstdint>   // for uint8_t

#include <string.h>  // for std::string
#include <iostream>  // for std::cout
#include <vector>

class A {
 public:
  A(std::string name) : name_(name) {
    std::cout << "create name is " << name_ << std::endl;
  };
  // two copy constructor
  A(const A& a) : name_(a.getName()) {
    std::cout << "copy& name is " << name_ << std::endl;
  };
  A(const A&& a) : name_(a.getName()) {
    std::cout << "copy&& name is " << name_ << std::endl;
  };
  ~A() { std::cout << "remove name is " << name_ << std::endl; };

  // for private name_
  void setName(std::string name) {
    name_ = name;
    std::cout << "change name is " << name_ << std::endl;
  }
  std::string getName() const { return name_; }
  void print_name() const {
    std::cout << "now name is " << name_ << std::endl << std::endl;
  }

  // this two `=` is just used to show process
  A& operator=(const A& a) {
    setName(a.getName());
    std::cout << "=& name is " << a.getName() << std::endl;
  }

  A& operator=(const A&& a) {
    setName(a.getName());
    std::cout << "=&& name is " << a.getName() << std::endl;
  }

 private:
  std::string name_;
};

void f1(A a) {
  a.setName("1");
  a.print_name();
}

// better not do like this
// use const to reference
void f2(A& a) {
  a.setName("2");
  a.print_name();
}

A f3(A&& a) {
  a.setName("3");
  a.print_name();
  return a;
}
A& f4(A&& a) {
  a.setName("4");
  a.print_name();
  return a;
}
A&& f5(A&& a) {
  a.setName("5");
  a.print_name();
  return std::move(a);
}

int main() {
  A a("0");

  // f1(a);
  // a.print_name();

  // f2(a);
  // a.print_name();

  a = f5(std::move(a));

  // f2(f4(std::move(a)));

  // a = f5(f5(std::move(a)));
  // a.print_name();

  // A a0(f5(A("0")));
  // a0.print_name();

  return 0;
}