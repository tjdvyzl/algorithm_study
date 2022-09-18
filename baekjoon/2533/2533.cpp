#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

#define MAX 987654321
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

/*
    연결된 노드중에 연결된 간선이 없는 노드가 존재한다면 해당 노드는 무조건
   얼리어답터 여야함.
*/

vector<int> graph[1000005];

int N;

int dp[1000005];

bool v[1000005];

bool early[1000005];

int cnt = 0;

void dfs(int cur) {
  v[cur] = true;

  for (int i = 0; i < graph[cur].size(); i++) {
    int e = graph[cur][i];
    if (v[e])
      continue;
    if (!early[cur] && graph[e].size() == 1) {
      early[cur] = true;
      early[e] = true;
      dp[cur]++;
      continue;
    }
    dfs(e);
    if (!early[cur] && !early[e]) {
      early[cur] = true;
      early[e] = true;
      dp[cur] += dp[e];
      dp[cur]++;
    } else
      dp[cur] += dp[e];
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(1);
  cout << dp[1] << "\n";
}
