#include <iostream>
#include <new>
#include <type_traits>
using namespace std;
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>

#define MAX 987654321
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

int N, M;

int arr[5][5];

int p[5]; // 0은 가로, 1은 세로

int ans = 0;

int checked[5];

int v(int level, int i) {
  int res = 0;
  int dir = p[level] & (1 << i);
  int cnt = 0;
  // 진행하던 방향이 가로일 때
  if (dir == 0) {
    for (int x = i; x <= M - 1; x++) {
      if ((checked[level] & (1 << x)) == 0) {
        if ((p[level] & (1 << x)) == dir) {
          res += arr[level][M - x - 1] * (int)pow(10, cnt++);
          checked[level] |= (1 << x);
        } else
          break;
      }
    }
  } else {
    for (int y = level; y >= 0; y--) {
      if ((checked[y] & (1 << i)) == 0) {
        if ((p[y] & (1 << i)) == dir) {
          res += arr[y][M - i - 1] * (int)pow(10, cnt++);
          checked[y] |= (1 << i);
        } else
          break;
      }
    }
  }
  return res;
}

void f(int level, int p[5]) {
  if (level >= N) {
    int sum = 0;
    for (int i = 0; i < N; i++)
      checked[i] = 0;

    for (int y = N - 1; y >= 0; y--) {
      for (int i = 0; i < M; i++) {
        if ((checked[y] & (1 << i)) == 1)
          continue;
        int t = v(y, i);
        sum += t;
      }
    }

    ans = max(ans, sum);
    return;
  }
  for (int i = p[level]; i <= (int)pow(2, M) - 1; i++) {
    int t = p[level];
    p[level] = i;
    f(level + 1, p);
    p[level] = t;
  }
}

int main() {
  cin >> N >> M;

  for (int y = 0; y < N; y++)
    for (int x = 0; x < M; x++)
      scanf("%1d", &arr[y][x]);

  f(0, p);

  cout << ans << "\n";
}
