#include <iostream>
using namespace std;
#include <queue>
#include <vector>

#define MAX 987654321

int N, K;

int ans = MAX;

bool v[2][500004]; // 0은 짝수, 1은 홀수

int dis[500004];

vector<int> getDir(int input) {
  vector<int> ans;
  ans.push_back(input + 1);
  ans.push_back(input - 1);
  ans.push_back(input * 2);
  return ans;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> K;

  if (N == K) {
    cout << 0 << "\n";
    return 0;
  }

  int t = 0;
  while (K + t * (t + 1) / 2 <= 500000) {
    dis[K + t * (t + 1) / 2] = t;
    t++;
  }

  queue<pair<int, int>> q;

  q.push({N, 0});

  int _time = 0;

  while (!q.empty()) {
    pair<int, int> t = q.front(); // pos, time
    q.pop();

    if (t.second >= ans)
      continue;

    if (dis[t.first] > 0) {
      if (dis[t.first] % 2 == t.second % 2 && dis[t.first] >= t.second) {
        ans = (ans > dis[t.first]) ? dis[t.first] : ans;
      }
    }

    vector<int> dir = getDir(t.first);
    for (auto e : dir) {
      if (e < 0 || e > 500000 || v[(t.second + 1) % 2][e])
        continue;
      v[(t.second + 1) % 2][e] = true;
      q.push({e, t.second + 1});
    }
  }

  ans = (ans == MAX) ? -1 : ans;
  cout << ans << "\n";
}