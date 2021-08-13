#include <bits/stdc++.h>
using namespace std;

#define MAX 987654321

int main() {
	int n; cin >> n;
	vector<int> d; // 제곱 수들 저장
	vector<int> dp(n + 1, 0);

	dp[1] = 1;

	for (int i = 1; i <= 230; i++)
		d.push_back(i * i);

	for (int i = 2; i <= n; i++) {
		int _min = MAX;
		for (int j = 0; d[j] <= i; j++) {	
			int temp = i - d[j];
			_min = min(_min, dp[temp]);
		}
		dp[i] = _min + 1;
	}
	
	cout << dp[n] << "\n";
	
}