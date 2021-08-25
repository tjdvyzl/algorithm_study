#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define MAX 9876543211

typedef long long ll;

ll T, n;

ll mod = 1000000000;

ll dp[101][10];

int main() {
	FIO;
	
	cin >> n;

	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j <= 9; j++)
		{
			if (i == 1) {
				dp[i][j] = 1;
				dp[i][0] = 0;
			}
			else {
				if (j == 0)
					dp[i][j] = dp[i - 1][1];
				else if (j == 9)
					dp[i][j] = dp[i - 1][8];
				else
					dp[i][j] = (dp[i - 1][j - 1]) % mod + (dp[i - 1][j + 1]) % mod;
			}
		}
	}

	ll cnt = 0;

	for (int i = 0; i <= 9; i++) {
		cnt =  (cnt + dp[n][i]) % mod;
	}

	cout << cnt << "\n";
}