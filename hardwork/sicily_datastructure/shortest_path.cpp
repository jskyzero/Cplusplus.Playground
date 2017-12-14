#include <iostream>
#include <queue>
#include <cstring>

typedef std::queue<int> Queue;

bool graph[10001][10001];
int visit[10001];

int bfs(int begin_point, int point_num, int end_point) {
  Queue myqueue;
  myqueue.push(begin_point);
  int ans = 0;

  while (!myqueue.empty()) {
    int size = myqueue.size();
    while (size--) {
      int temp = myqueue.front();
      myqueue.pop();
      if (temp == end_point) return ans;
      for (int i = 1; i <= point_num; i++) {
        if (graph[temp][i] && !visit[i]) {
          if (i == end_point) return ans + 1;
          myqueue.push(i);
          visit[i] = 1;
        }
      }
    }
    ans++;
  }
  return -1;
}

void shortest_path(int point_num, int edge_num) {
  memset(graph, 0, sizeof(graph));

  int begin, end;
  for (int i = 0; i < edge_num; i++) {
    std::cin >> begin >> end;
    graph[begin][end] = true;
    graph[end][begin] = true;
  }

  for (int i = 1; i <= point_num; i++) {
    std::cout << bfs(i, point_num, 1) << " ";
  }
}

int main() {
  int point_num, edge_num;
  while (std::cin >> point_num >> edge_num && point_num && edge_num) {
    memset(visit, 0, sizeof(visit));
    shortest_path(point_num, edge_num);
    std::cout << std::endl;
  }
}