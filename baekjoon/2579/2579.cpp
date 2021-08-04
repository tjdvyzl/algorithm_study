#include <iostream>
#include <algorithm>
using namespace std;

int T; 
int arr[333];
int dp[333][2]; // 0은 전 계단을 안밞음, 1은 전 계단을 밞음 --> 최댓값들

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
		if (i == 1) 
			dp[i][0] += arr[i];
		
		if (i == 2) {
			dp[i][0] += arr[i];
			dp[i][1] += dp[i - 1][0] + arr[i];
		}
		if (i >= 3)
		{
			dp[i][0] += max(dp[i - 2][0], dp[i - 2][1]) + arr[i];
			dp[i][1] += max(dp[i - 1][0], max(dp[i - 2][0], dp[i - 2][1])) + arr[i];
		}
	}
	cout << max(dp[T][1], dp[T][0]) << "\n";
}