#include <iostream>
#include <list>
#include <algorithm>
#include <ciso646>
#include <cstring>

#define MAX_CARD_NUM 52
#define MAX_TIMES 100000

typedef std::list<int> List;

void hit_or_miss() {
  int people_num, temp_card_id, all_is_ok = 0, last_people_out = 0;
  std::cin >> people_num;
  List cards[people_num];
  int last_card_nums[people_num], count_nums[people_num];
  memset(last_card_nums, 0, sizeof(last_card_nums));
  memset(count_nums, 0, sizeof(count_nums));

  for (int i = 0; i < MAX_CARD_NUM; i++) {
    std::cin >> temp_card_id;
    cards[0].push_back(temp_card_id);
  }

  for (int times = 0; times < MAX_TIMES and not all_is_ok; times++) {
    for (int now_people = 0; now_people < people_num and not all_is_ok;
         now_people++) {
      if (cards[now_people].empty()) continue;

      count_nums[now_people] =
          count_nums[now_people] == 13 ? 1 : count_nums[now_people] + 1;

      temp_card_id = cards[now_people].front();
      cards[now_people].pop_front();

      if (count_nums[now_people] == temp_card_id) {
        // std::cout << now_people << temp_card_id << " ";
        last_card_nums[now_people] = cards[now_people].empty()
                                         ? temp_card_id
                                         : last_card_nums[now_people];
        if (now_people == people_num - 1) {
          last_people_out++;
          all_is_ok = (last_people_out == MAX_CARD_NUM) ? 1 : 0;
        } else {
          cards[now_people + 1].push_back(temp_card_id);
        }
      } else {
        cards[now_people].push_back(temp_card_id);
      }
    }
  }

  if (all_is_ok) {
    // for(auto & card_num : last_card_nums) {
    //   std::cout << " " << card_num;
    // }
    for (int i = 0; i < people_num; i++) {
      std::cout << " " << last_card_nums[i];
    }
  } else {
    std::cout << " unwinnable";
  }
}

int main() {
  int times;
  std::cin >> times;
  for (int now_case = 0; now_case < times; now_case++) {
    std::cout << "Case " << now_case + 1 << ":";
    hit_or_miss();
    std::cout << std::endl;
  }

  return 0;
}