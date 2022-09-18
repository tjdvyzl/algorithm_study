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

vector<int> graph[10005];

int N;

int arr[10005];

int dp[10005][2]; // 0은 자신의 마을이 우수 마을로 선정할 경우, 1은 인접한
                  // 마을이 우수 마을로 선정될 경우

bool v[10005];

void dfs(int cur) {
  v[cur] = true;

  for (int i = 0; i < graph[cur].size(); i++) {
    int e = graph[cur][i];
    if (v[e])
      continue;
    dfs(e);
    dp[cur][0] += dp[e][1];
    dp[cur][1] += max(dp[e][0], dp[e][1]);
  }
}

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++)
    cin >> arr[i];

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= N; i++)
    dp[i][0] = arr[i];

  dfs(1);
  cout << max(dp[1][0], dp[1][1]) << "\n";
}
