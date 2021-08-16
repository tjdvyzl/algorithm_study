#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 12345678912

typedef long long ll;

int n;

int dp[1234];
int arr[1234];

int main() {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int input; cin >> input;

		arr[i] = input;

		if (i == 1)
			dp[1] = arr[1];
		else if (i == 2)
			dp[2] = max(dp[1] * 2, arr[2]);
		else {
			for (int j = 1; ((i - j >= j) && j < i); j++) {
				dp[i] = max(dp[i], dp[j] + dp[i - j]);
			}
			dp[i] = max(dp[i], arr[i]);
		}
	}

	cout << dp[n] << "\n";
}