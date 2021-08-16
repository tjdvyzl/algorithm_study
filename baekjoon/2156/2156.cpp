#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 12345678912

typedef long long ll;

int n;

int dp[10001][3]; //0Àº Àü²¨ ¾È¸¶½É  1Àº Àü²¨ ¸¶½É   2´Â Àü²¨¶û ÀüÀü²¨¸¦ ¾È¸¶¼ÌÀ» ¶§ ÃÖ´ñ°ª

int main() {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input; cin >> input;

		if (i == 0) {
			dp[i][0] = input;
			dp[i][1] = input;
			dp[i][2] = 0;
		}
		else if (i == 1) {
			dp[i][0] = input;
			dp[i][1] = dp[i - 1][0] + input;
			dp[i][2] = 0;
		}
		else {
			dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + input;
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + input;
			dp[i][2] = max(dp[i - 3][0], dp[i - 3][1]) + input;
		}
	}

	int a = max(dp[n - 2][0], max(dp[n - 2][1], dp[n - 2][2]));
	int b = max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));

	cout << max(a, b) << "\n";
}