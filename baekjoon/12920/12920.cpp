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
#include <map>
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

int dp[1500][10005];

vector<pair<int, int>> vec; // weight, cost

int N, M; // 물건의 종류 수, 민호가 들 수 있는 최대 무게

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  vec.push_back({0, 0});

  for (int i = 1; i <= N; i++) {
    int w, c, k;
    cin >> w >> c >> k;
    for (int e = k; e > 0; e >>= 1) {
      int t = e - (e >> 1);
      vec.push_back({w * t, c * t});
    }
  }

  /*
  최적화 2
      for (int i = 1; i <= N; i++) {
    int w, c, k;
    cin >> w >> c >> k;

    int j = 1;
    for (; (j * 2) - 1 <= k; j *= 2)
      vec.push_back({w * j, c * j});
    vec.push_back({w * (k - (j - 1)), c * (k - (j - 1))});
  }*/

  sort(vec.begin(), vec.end());

  for (int i = 1; i <= vec.size(); i++) {
    for (int w = 1; w <= M; w++) {
      dp[i][w] = max(dp[i - 1][w], dp[i][w - 1]);
      if (vec[i].first <= w) {
        dp[i][w] = max(dp[i][w], vec[i].second + dp[i - 1][w - vec[i].first]);
      }
    }
  }

  cout << dp[vec.size()][M] << "\n";
}
