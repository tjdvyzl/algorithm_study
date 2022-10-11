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

int tc;

int arr[200005];

int dp[200005];

int main() {
  cin >> tc;

  while (tc--) {
    ll ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      int _max = min(dp[i - 1] + 1, arr[i]);
      ans += _max;
      dp[i] = _max;
    }

    cout << ans << "\n";
  }
}