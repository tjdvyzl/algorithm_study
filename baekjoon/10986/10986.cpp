#include <iostream>
#include <type_traits>
using namespace std;
#include <algorithm>
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

int arr[1000005];
int cnt[1005];

ll sum[1000005];

ll ans = 0;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  ll s = 0;

  for (int i = 0; i < N; i++) {
    s += arr[i];
    cnt[s % M]++;
  }

  ans += cnt[0];

  ll bound = arr[0] % M;

  cnt[bound]--;

  for (int i = 1; i < N; i++) {
    ans += cnt[bound];
    bound = (bound + arr[i]) % M;
    cnt[bound]--;
  }

  cout << ans << "\n";
}