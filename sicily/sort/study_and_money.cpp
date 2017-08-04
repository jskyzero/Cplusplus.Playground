#include <iostream>
#include <algorithm>

class Marks{
 public:
  int chinese, math, english, id;
  int total_marks() {
    return chinese + math  + english;
  }

  friend std::ostream &operator<<(std::ostream &out, Marks &marks);
  friend std::istream &operator>>(std::istream &in, Marks &marks);
  friend bool operator>(Marks &left, Marks &right);
};

std::ostream &operator<<(std::ostream &out, Marks &marks) {
  out << marks.id << " " << marks.total_marks();
  return out;
}

std::istream &operator>>(std::istream &in, Marks &marks) {
  in >> marks.chinese >> marks.math >> marks.english;
  return in;
}

bool operator>(Marks &left, Marks &right) {
  if(left.total_marks() > right.total_marks()) return true;
  if(left.total_marks() == right.total_marks() && 
     left.chinese > right.chinese) return true;
  if(left.total_marks() == right.total_marks() && 
     left.chinese == right.chinese &&
     left.id < right.id) return true;
  return false;
}

bool comp(Marks left, Marks right) {
  return left > right;
}

void study_and_money(int size) {
  Marks *data =  new Marks[size];
  for (int i = 0; i < size; i++) {
    std::cin >> data[i];
    data[i].id = i+1;
  }

  std::sort(data, data+size, comp);

  bool first = true;
  for (int i = 0; i < 5; i++) {
    // if(first) {
    //   first = false;
    // } else {
    //   std::cout << std::endl;
    // }
    std::cout << data[i] << std::endl;
  }
}

int main() {
  int size;
  bool first = true;
  while (std::cin >> size) {
    if (first) {
      first = false;
    } else {
      std::cout << std::endl;
    }
    study_and_money(size);
  }
}