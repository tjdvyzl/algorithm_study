#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 987654321

typedef long long ll;

int T;

ll dp[99];
/*
	Â¦¼ö ÀÏ¶§´Â +1
	È¦¼ö ÀÏ¶§´Â +1
*/


int main() {
	FIO;

	cin >> T;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= T; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[T] << "\n";
}