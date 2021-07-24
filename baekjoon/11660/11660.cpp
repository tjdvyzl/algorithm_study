#include <iostream>
using namespace std;

typedef long long ll;

ll arr[1025][1025];
ll dp[1025][1025];
ll sum[100001];

ll n,m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			int input; cin >> input;
			arr[y][x] = input;
			dp[y][x] += arr[y][x] + dp[y][x - 1];
		}
	}

	for (int i = 1; i <= m; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int y = y1; y <= y2; y++) {
			sum[i] += dp[y][x2] - dp[y][x1 - 1];
		}
		cout << sum[i] << "\n";
	}
}