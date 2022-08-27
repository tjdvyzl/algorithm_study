#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

typedef long long ll;

ll N, K;

ll arr[201010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  ll lo = 1;
  ll hi = (N * N > 1000000000) ? 1000000000 : N * N;

  ll ans = 0;

  while (lo <= hi) {
    ll mid = (lo + hi) / 2;
    ll cnt = 0;
    for (ll y = 1; y <= N; y++) {
      ll x; // N 에서 x번째 idx를 빼서 mid보다 큰 숫자의 개수를 구함 N - x + 1
      if (mid >= y)
        x = (mid / y + 1 > N) ? N + 1 : mid / y + 1;

      else
        x = 1;

      cnt += N - x + 1;
    }
    cout << mid << " --> " << cnt << "\n";
    cout << lo << ", " << hi << "\n";
    // 현재 mid의 최소 index값이 K보다 작을 때
    if (N * N - cnt < K) {
      lo = mid + 1;
    } else {
      ans = mid;
      hi = mid - 1;
    }
  }

  cout << ans << "\n";
}
