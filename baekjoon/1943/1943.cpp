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

pair<int, int> arr[105]; // money, cnt;
int bound = 0;
bool dp[105][50005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int tc = 0; tc < 3; tc++) {
    cin >> N;
    for (int i = 0; i <= N + 1; i++)
      memset(dp[i], false, sizeof(dp[i]));
    memset(arr, 0, sizeof(arr));
    bound = 0;
    bool canDivide = false;
    for (int i = 1; i <= N; i++) {
      int money, money_cnt;
      cin >> money >> money_cnt;
      bound += money * money_cnt;
      arr[i] = {money, money_cnt};
    }
    if (bound % 2 != 0) {
      cout << 0 << "\n";
      continue;
    }
    sort(arr, arr + N + 1);
    int _max = 0;
    dp[0][0] = true;
    for (int i = 1; !canDivide && i <= N; i++) {
      int temp_max = 0;
      for (int e = 1; !canDivide && e <= arr[i].second; e++) {
        for (int j = 0; !canDivide && j <= _max; j++) {
          if (dp[i - 1][j]) {
            dp[i][j + e * arr[i].first] = true;
            dp[i][j] = true;
            temp_max = max(temp_max, j + e * arr[i].first);
            if (j + e * arr[i].first == bound / 2)
              canDivide = true;
          }
        }
      }
      _max = max(_max, temp_max);
    }

    cout << canDivide << "\n";
  }
}