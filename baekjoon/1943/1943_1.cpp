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

int N;

vector<pair<int, int>> vec; // idx, money

int bound = 0;

int cnt[105];

bool dp[100005];

bool canDivide = false;

vector<int> temp;

void f(int sum) {
  if (dp[sum])
    return;
  dp[sum] = true;

  if (dp[abs(sum - bound / 2)]) {
    canDivide = true;
    return;
  }

  for (int i = 0; !canDivide && i < vec.size(); i++) {
    if (cnt[vec[i].first] <= 0)
      continue;
    cnt[vec[i].first]--;
    f(sum + vec[i].second);
    cnt[vec[i].first]++;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int tc = 0; tc < 3; tc++) {
    cin >> N;
    vec.clear();
    memset(dp, false, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    bound = 0;
    canDivide = false;
    for (int i = 0; i < N; i++) {
      int money, money_cnt;
      cin >> money >> money_cnt;
      bound += money * money_cnt;
      cnt[i] = money_cnt;
      vec.push_back({i, money});
    }
    if (bound % 2 != 0) {
      cout << 0 << "\n";
      continue;
    }
    sort(vec.begin(), vec.end());
    f(0);
    cout << canDivide << "\n";
  }
}
