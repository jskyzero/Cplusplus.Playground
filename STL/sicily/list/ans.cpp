#include <iostream>  
#include <queue>  
#include <string.h>  
using namespace std;  
  
#define MAX_TIMES 10000//最大的轮数，这个只能猜了  
  
int main() {  
      
    int case_num, i, j, player_num;  
      
    cin >> case_num;  
    for (j = 1; j <= case_num; j++) {  
          
        cin >> player_num;  
        queue<int> deck[player_num];//用队列来模拟  
        int temp;  
        for (i = 0; i < 52; i++) {  
            cin >> temp;  
            deck[0].push(temp);//刚开始只有第一个人受伤有牌  
        }  
        int last_deck[player_num];//用来记录每个人拥有的最后一张牌  
        memset(last_deck, 0, sizeof(last_deck));  
        int count[player_num];//用来给每个人计数  
        memset(count, 0, sizeof(count));  
        int times = 0;//轮数  
        int discard = 0;//游戏中最后一个人抛弃的牌数  
        bool is_ok = false;  
          
        while (times <= MAX_TIMES && !is_ok) {  
              
            for (i = 0; i < player_num && !is_ok; i++) {  
                  
                if (deck[i].empty())  
                    continue;  
                  
                count[i] = count[i] == 13 ? 1 : count[i] + 1;  
                  
                temp = deck[i].front();  
                deck[i].pop();//无论能否匹配，第一张牌总是要改变位置的  
                  
                if (temp == count[i]) {//匹配了  
                    if (deck[i].empty()) {//如果这个人手上拿走了这张牌之后没有牌，记录这张牌为最后牌  
                        last_deck[i] = temp;  
                    }  
                    if (i == player_num - 1) {  
                        discard++;//最后一个人抛弃的牌数  
                        if (discard == 52) {//牌都抛弃完了  
                            is_ok = true;  
                        }  
                    } else {  
                        deck[i + 1].push(temp);//给下一个人牌的最底  
                    }  
                } else {  
                    deck[i].push(temp);//给自己最底  
                }  
            }  
            times++;  
        }  
        cout << "Case " << j << ":";  
        if (is_ok) {  
            for (i = 0; i < player_num; i++) {  
                cout << " " << last_deck[i];  
            }  
        } else {  
            cout << " unwinnable";  
        }  
        cout << endl;  
    }  
    return 0;  
} 