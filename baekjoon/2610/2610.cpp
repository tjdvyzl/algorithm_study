#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>

#define MAX 987654321

int N, M;

vector<int> graph[105];

// 최단거리 저장
int dis[105][105];

// dfs 방문처리
bool total_v[105];

// sub_dfs 방문처리
bool temp_v[105];

// bfs를 통해 각 정점에 대해 연결된 정점들까지의 최단 거리를 구한다.
void bfs(int input) {
  queue<pair<int, int>> q; // pos, cost
  q.push({input, 0});

  dis[input][input] = 0;

  while (!q.empty()) {
    pair<int, int> t = q.front();
    q.pop();

    int current_pos = t.first;
    int cost = t.second;

    for (int i = 0; i < graph[current_pos].size(); i++) {
      int next_node = graph[current_pos][i];
      if (dis[input][next_node] <= cost + 1)
        continue;
      dis[input][next_node] = cost + 1;
      q.push({next_node, cost + 1});
    }
  }
}

void input() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      dis[i][j] = MAX;

  for (int i = 1; i <= N; i++)
    bfs(i);
}

int min_idx = -1;
int min_value = MAX;

int temp_max_value = -1;

void sub_dfs(int bound, int input) {
  temp_v[input] = true;

  temp_max_value = max(temp_max_value, dis[input][bound]);

  for (int i = 0; i < graph[input].size(); i++) {
    int e = graph[input][i];

    if (temp_v[e])
      continue;

    sub_dfs(bound, e);
  }
}

void dfs(int input) {
  memset(temp_v, false, sizeof(temp_v));
  temp_max_value = -1;

  total_v[input] = true;

  // sub_dfs를 통해 연결된 정점들에 대한 input까지의 최단 거리 중 최대값을
  // 찾는다.
  sub_dfs(input, input);

  // 만약 연결된 정점들에 대해 input까지의 최단 거리들의 최대값이 min_value보다
  // 작다면 최소값 갱신
  if (temp_max_value < min_value) {
    min_idx = input;
    min_value = temp_max_value;
  }

  for (int i = 0; i < graph[input].size(); i++) {
    int e = graph[input][i];
    if (total_v[e])
      continue;
    dfs(e);
  }
}

int main() {
  input();

  vector<int> ans;

  for (int i = 1; i <= N; i++) {
    if (total_v[i])
      continue;
    min_idx = -1;
    min_value = MAX;
    dfs(i);
    ans.push_back(min_idx);
  }

  cout << ans.size() << "\n";

  sort(ans.begin(), ans.end());

  for (auto e : ans)
    cout << e << "\n";
}