#include <iostream> // for std::cin std::cout  
#include <string> // for std::string
#include <map> // for std::map 

typedef std::string String;
typedef std::map<int, String> InMap;
typedef std::map<String, int> Map;

void academy_awards(int list_num) {
  int total_num = 0, award_size, max_num = 0;
  InMap in;
  Map data;
  String str;

  for (int i = 0; i < list_num; i++) {
    std::cin >> str >> award_size;
    for (int j = 0; j < award_size; j++) {
      std::cin >> str;

      in[total_num] = str;
      total_num++;

      data[str] ++;
    }
  }
   for (auto & each_data : data) {
      max_num = each_data.second > max_num ? each_data.second : max_num;
    }
    for (auto & each_in : in) {
      if (data[each_in.second] == max_num) {
      std::cout << each_in.second << std::endl;
        break;
      }
    }  
}

int main() {
  int list_num;
  while(std::cin >> list_num && list_num) {
    academy_awards(list_num);
  }
}