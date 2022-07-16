#include <iostream>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int r, c;

string _map[10005];

bool v[10001][505];

bool isFinish[10001];

int answer = 0;

bool check(int num, int y, int x) {
  if (isFinish[num])
    return false;
  if (y < 0 || y >= r || x < 0 || x >= c)
    return false;
  if (v[y][x])
    return false;
  if (_map[y][x] == 'x')
    return false;
  return true;
}

void dfs(int num, int y, int x) {
  v[y][x] = true;

  if (x == c - 1) {
    isFinish[num] = true;
    answer++;
    return;
  }
  // 오른쪽 위
  if (check(num, y - 1, x + 1))
    dfs(num, y - 1, x + 1);

  // 오른쪽
  if (check(num, y, x + 1))
    dfs(num, y, x + 1);

  // 오른쪽 야래
  if (check(num, y + 1, x + 1))
    dfs(num, y + 1, x + 1);
}

int main() {
  FIO;

  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    cin >> _map[i];
  }

  for (int rr = 0; rr < r; rr++) {
    dfs(rr, rr, 0);
  }

  cout << answer << "\n";
}