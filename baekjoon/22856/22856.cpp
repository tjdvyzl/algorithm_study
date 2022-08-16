#include <iostream>
using namespace std;
#include <string.h>
#include <vector>

int graph[100005][2]; // 0 leftChild,  1 rightChild

int N;

bool v[100005];

int cnt = 0;

int endNode = 1;

bool temp = false;

void dfs(int input) {
  int left_child = graph[input][0];
  int right_child = graph[input][1];

  // 1번
  if (!temp && left_child != -1 && !v[left_child]) {
    cnt++;
    v[left_child] = true;
    dfs(left_child);
  }

  // 2번
  if (!temp && right_child != -1 && !v[right_child]) {
    cnt++;
    v[right_child] = true;
    dfs(right_child);
  }

  // 3번
  if (input == endNode) {
    temp = true;
    return;
  }

  // 4번
  bool isLeftChildVisit = (left_child == -1 || v[left_child]) ? true : false;
  bool isRightChildVisit = (right_child == -1 || v[right_child]) ? true : false;
  if (!temp && isLeftChildVisit && isRightChildVisit) {
    cnt++;
    return;
  }
}

int find_endNode(int input) {
  int right_child = graph[input][1];

  if (right_child != -1) {
    return find_endNode(right_child);
  }

  else {
    return input;
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, a_left, a_right;
    cin >> a >> a_left >> a_right;
    graph[a][0] = a_left;
    graph[a][1] = a_right;
  }
  endNode = find_endNode(1);
  if (endNode == 1) {
    if (graph[endNode][0] != -1) {
      dfs(graph[endNode][0]);
      cnt++;
    }
  } else {
    dfs(1);
  }

  cout << cnt << "\n";
}