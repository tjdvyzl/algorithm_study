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

#define MAX INT_MAX
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

class node {
public:
  int y;
  int x;
  int cost;
  int state;
  node() {}
  node(int y, int x, int cost, int state)
      : y(y), x(x), cost(cost), state(state) {}
};

int N, M;

string _map[55];

int dp[55][55][64];

// 상 하 좌 우
int dir_y[4] = {-1, 1, 0, 0};
int dir_x[4] = {0, 0, -1, 1};

int ans = MAX;

/*
my sol>
  특정 위치에 도달했을 때 확인할 점
  1. a, b, c, d, e, f  총 2^6가지의 경우의 수에 대해서 어떤 열쇠들을 가지고
  0에서 해당 위치까지 최단 거리로 방문을 했는지 체크해야함.

  새로운 상태에서 해당 위치를 방문했다면 큐에 넣어주자.
    ㄴ 여기서 새로운 상태는 어떤 열쇠를 갖고 있는지. 공집합 포함
*/

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  queue<node> q; // pos, state

  cin >> N >> M;
  for (int y = 0; y < N; y++) {
    cin >> _map[y];
    for (int x = 0; x < M; x++) {
      if (_map[y][x] == '0')
        q.push(node(y, x, 0, 0));
      for (int i = 0; i < 64; i++)
        dp[y][x][i] = MAX;
    }
  }

  while (!q.empty()) {
    pair<int, int> t = {q.front().y, q.front().x};
    int curCost = q.front().cost;
    int curState = q.front().state;
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int dy = t.first + dir_y[dir];
      int dx = t.second + dir_x[dir];
      if (dy > N - 1 || dy < 0 || dx > M - 1 || dx < 0 || _map[dy][dx] == '#')
        continue;
      if ('A' <= _map[dy][dx] && _map[dy][dx] <= 'F') {
        int i = (int)_map[dy][dx] - 65;
        if (!(curState & (1 << i))) {
          continue;
        }
      }
      if (dp[dy][dx][curState] > curCost + 1) {
        dp[dy][dx][curState] = curCost + 1;
        if (_map[dy][dx] == '.' || _map[dy][dx] == '0')
          q.push({dy, dx, dp[dy][dx][curState], curState});
        else if (_map[dy][dx] == '1') {
          ans = min(ans, curCost + 1);
          continue;
        } else { // 97
          q.push({dy, dx, dp[dy][dx][curState],
                  (curState | (1 << ((int)_map[dy][dx] - 97)))});
        }
      }
    }
  }

  if (ans == MAX)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}