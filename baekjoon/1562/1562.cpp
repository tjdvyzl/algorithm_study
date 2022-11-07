#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 9876543211

typedef unsigned long long ll;

ll T, n;

ll mod = 1000000000;

ll dp[101][10][1 << 10];

int main() {
  FIO;

  cin >> n;

  for (int i = 1; i <= 9; i++)
    dp[1][i][(1 << i)] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int e = 0; e < (1 << 10); e++) {
        if (j == 0) {
          dp[i][j][e | (1 << j)] =
              (dp[i][j][e | (1 << j)] + dp[i - 1][j + 1][e]) % mod;
        } else if (j == 9) {
          dp[i][j][e | (1 << j)] =
              (dp[i][j][e | (1 << j)] + dp[i - 1][j - 1][e]) % mod;
        } else {
          dp[i][j][e | (1 << j)] =
              (dp[i][j][e | (1 << j)] + dp[i - 1][j + 1][e] % mod);
          dp[i][j][e | (1 << j)] =
              (dp[i][j][e | (1 << j)] + dp[i - 1][j - 1][e]) % mod;
        }
        dp[i][j][e | (1 << j)] %= mod;
      }
    }
  }

  ll ans = 0;

  for (int i = 0; i <= 9; i++) {
    ans = (ans + dp[n][i][(1 << 10) - 1]) % mod;
  }

  cout << ans << "\n";
}