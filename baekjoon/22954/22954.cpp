#include <ctime>
#include <iostream>
#include <type_traits>
using namespace std;
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>

#define MAX LLONG_MAX
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

int N, M; // 100000 200000

vector<pair<int, int>> graph[100005]; // node, edge_number

int parent[100005];

int N1, N2;

int find(int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

// false면 cycle 존재
bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b)
    return false;
  if (a > b)
    parent[a] = b;
  else
    parent[b] = a;
  return true;
}

bool v[100005];

bool temp[100005];

// 각 정점마다 dfs를 돌려서 분리되어있는 트리 루트 정점을 저장
vector<int> temp_srcvertex;

int temp_cnt[100005];

vector<int> vertex;

vector<int> edge;

void checkCnt(int bound, int input) {
  temp[input] = true;
  temp_cnt[bound]++;
  for (int i = 0; i < graph[input].size(); i++) {
    int e = graph[input][i].first;
    if (temp[e])
      continue;
    checkCnt(bound, e);
  }
}

void dfs(int input) {
  v[input] = true;
  vertex.push_back(input);

  for (int i = 0; i < graph[input].size(); i++) {
    int e = graph[input][i].first;
    int edge_num = graph[input][i].second;
    if (v[e])
      continue;
    edge.push_back(edge_num);
    dfs(e);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++)
    parent[i] = i;

  for (int i = 1; i <= M; i++) {
    int a, b;
    cin >> a >> b;
    if (merge(a, b)) {
      graph[a].push_back({b, i});
      graph[b].push_back({a, i});
    }
  }

  for (int i = 1; i <= N; i++) {
    if (!temp[i]) {
      temp_srcvertex.push_back(i);
      checkCnt(i, i);
    }
  }

  if (temp_srcvertex.size() != 1 && temp_srcvertex.size() != 2) {
    cout << -1 << "\n";
  } else {
    if (temp_srcvertex.size() == 2) {
      if (temp_cnt[temp_srcvertex[0]] == temp_cnt[temp_srcvertex[1]])
        cout << -1 << "\n";
      else {
        cout << temp_cnt[temp_srcvertex[0]] << " "
             << temp_cnt[temp_srcvertex[1]] << "\n";
        dfs(temp_srcvertex[0]);
        for (auto e : vertex)
          cout << e << " ";
        cout << "\n";
        for (auto e : edge)
          cout << e << " ";
        cout << "\n";
        vertex.clear();
        edge.clear();
        dfs(temp_srcvertex[1]);
        for (auto e : vertex)
          cout << e << " ";
        cout << "\n";
        for (auto e : edge)
          cout << e << " ";
        cout << "\n";
      }
    }
    // 하나의 트리로 이루어짐
    else {
      if (N == 1 || N == 2) {
        cout << -1 << "\n";
        return 0;
      }
      int bound = -1;

      for (int i = 1; i <= N; i++) {
        if (graph[i].size() == 1) {
          N1 = 1, N2 = N - 1;
          v[i] = true;
          bound = i;
          break;
        }
      }
      cout << N1 << " " << N2 << "\n";
      cout << bound << "\n";
      cout << "\n";
      for (int i = 1; i <= N; i++) {
        if (i == bound)
          continue;
        dfs(i);
        break;
      }
      for (auto e : vertex)
        cout << e << " ";
      cout << "\n";
      for (auto e : edge)
        cout << e << " ";
    }
  }
}