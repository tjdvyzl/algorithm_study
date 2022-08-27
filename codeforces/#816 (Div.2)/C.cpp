#include <iostream>
using namespace std;

typedef long long ll;

ll n, m;

ll arr[100005];

ll b[100005];

int main() {
  cin >> n >> m;
  ll s = 0;
  b[1] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (i > 1) {
      if (arr[i] == arr[i - 1])
        b[i] = b[i - 1];
      else
        b[i] = b[i - 1] + 1;
    }
    s += b[i];
  }

  ll ans = s;

  for (int i = 2; i <= n; i++) {
    if (b[i] == b[i - 1]) {
      ans += (s - 1);
      s = s - 1;
    } else {
      ans += s - (n - (i - 1) + 1);
      s = s - (n - (i - 1) + 1);
    }
  }

  for (int e = 0; e < m; e++) {
    int i, x;
    cin >> i >> x;

    if (i > 1) {
      // 왼쪽과 다를 때
      if (arr[i] != arr[i - 1]) {
        ans -= (i - 1) * (n - (i - 1));
      }
    }
    if (i < n) {
      // 오른쪽과 다를 때
      if (arr[i] != arr[i + 1]) {
        ans -= (i) * (n - i);
      }
    }

    arr[i] = x;

    if (i > 1) {
      // 왼쪽과 다를 때
      if (arr[i] != arr[i - 1]) {
        ans += (i - 1) * (n - (i - 1));
      }
    }
    if (i < n) {
      // 오른쪽과 다를 때
      if (arr[i] != arr[i + 1]) {
        ans += (i) * (n - i);
      }
    }
    cout << ans << "\n";
  }
}