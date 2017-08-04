#include <iostream>
#include <stack>
// The MAX_SIZE is suitable for 1001(at least), but I set it to 1003 for safe.
#define MAX_SIZE 1003
using namespace std;

bool picture[MAX_SIZE][MAX_SIZE];  // bipartite graph
int color[MAX_SIZE];               // The color of elements
int temp[MAX_SIZE];   // The storage of elements that we want to sort
int small[MAX_SIZE];  // An array use for judge whether the two numbers obey the
                      // rule
int num;              // The number of elements we want to enter
bool
    flag;  // Make up whether the string of number can fit into  two－stack sort

/* set_color: use dfs to set the color */
void set_color(int i, int c) {
  color[i] = c;
  for (int j = 0; j < num; j++) {
    if (picture[i][j]) {  // Find the adjacent point
      if (color[j] ==
          c) {  // adjacent points have the same color it will be wrong
        flag = false;
      }
      if (!color[j]) {  // if the point has never be drawn, set the color of it
        set_color(j, 3 - c);  // 3-c only have two result: 1, 2, represent
                              // stack1 and stack2
      }
    }
  }
}
/* Creat_Picture: create the bipartite graph with regard to the rule */
void Creat_Picture() {
  small[num] = 0x7FFFFFFF;  // INT_MAX_SIZE, you can set the number that bigger
                            // than the elements you put
  for (int i = num - 1; i >= 0; i--) {
    small[i] = temp[i];
    if (small[i + 1] < small[i]) {  // create the array for the rule
      small[i] = small[i + 1];
    }
  }
  for (int i = 0; i < num - 1; i++) {
    for (int j = i + 1; j < num; j++) {
      if (temp[i] < temp[j] && small[j + 1] < temp[i]) {
        picture[i][j] = picture[j][i] =
            1;  // create the gragh according to the rule
      }
    }
  }
  for (int i = 0; i < num; i++) {
    if (!color[i]) {  // set the default color to 1 for the unsigned one
      set_color(i, 1);
    }
  }
}

void Calculate() {
  if (flag == false) {
    cout << "0" << endl;
    return;
  }
  stack<int> stack1;  // store the element that has color one
  stack<int> stack2;  // store the element that has color two
  int count = 0;      // Use for judging whether we should add the space
  int aim = 1;        // Use for judging whether we should pop the element
  for (int i = 0; i < num; i++) {
    if (color[i] == 1) {
      stack1.push(temp[i]);
      count++;
      cout << "a";
      if (count < num * 2) {
        cout << " ";
      }
    } else {
      stack2.push(temp[i]);
      count++;
      cout << "c";
      if (count < num * 2) {
        cout << " ";
      }
    }
    // while-loop is important, we should pop the element after we push the
    // element
    while ((!stack1.empty() && stack1.top() == aim) ||
           (!stack2.empty() && stack2.top() == aim)) {
      if (!stack1.empty() && stack1.top() == aim) {
        stack1.pop();
        count++;
        aim++;
        cout << "b";
        if (count < num * 2) {
          cout << " ";
        }
      } else {
        stack2.pop();
        count++;
        aim++;
        cout << "d";
        if (count < num * 2) {
          cout << " ";
        }
      }
    }
  }
  cout << endl;
}

int main(void) {
  while (cin >> num) {
    flag = true;
    for (int i = 0; i < MAX_SIZE; i++) {
      color[i] = 0;
      temp[i] = 0;
      small[i] = 0;
      for (int j = 0; j < MAX_SIZE; j++) {
        picture[i][j] = 0;
      }
    }
    for (int i = 0; i < num; i++) {
      cin >> temp[i];
    }
    Creat_Picture();
    Calculate();
  }
  return 0;
}