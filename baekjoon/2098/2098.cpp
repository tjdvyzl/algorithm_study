#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 987654321

typedef unsigned long long ll;

class node {
public:
  int lvn; // lastVisitNode
  int sum;
  int bit;
  node() {}
  node(int lvn, int s, int b) : lvn(lvn), sum(s), bit(b) {}
};

int N;

int value[17][17];

int dp[17][(1 << 17)];

void bfs() {
  queue<node> q;
  q.push(node(0, 0, (1 << 0)));
  dp[0][1] = 0;
  int ans = MAX;

  while (!q.empty()) {
    node t = q.front();
    q.pop();
    if (t.bit == (1 << N) - 1) {
      if (value[t.lvn][0] != 0)
        ans = min(ans, t.sum + value[t.lvn][0]);
      continue;
    }
    for (int i = 0; i < N; i++) {
      if (t.bit & (1 << i))
        continue;
      if (value[t.lvn][i] == 0)
        continue;
      if (dp[i][t.bit | (1 << i)] != MAX) {
        if (dp[i][t.bit | (1 << i)] <= dp[t.lvn][t.bit] + value[t.lvn][i])
          continue;
        dp[i][t.bit | (1 << i)] = dp[t.lvn][t.bit] + value[t.lvn][i];
      } else {
        dp[i][t.bit | (1 << i)] = (dp[t.lvn][t.bit] == MAX)
                                      ? t.sum + value[t.lvn][i]
                                      : dp[t.lvn][t.bit] + value[t.lvn][i];
      }
      q.push(node(i, dp[i][t.bit | (1 << i)], t.bit | (1 << i)));
    }
  }
  cout << ans << "\n";
}

int main() {
  FIO;

  cin >> N;
  for (int y = 0; y < N; y++)
    for (int x = 0; x < N; x++)
      cin >> value[y][x];

  for (int i = 0; i < N; i++)
    for (int e = 0; e < (1 << 17); e++)
      dp[i][e] = MAX;

  bfs();
}