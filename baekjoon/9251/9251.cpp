#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

string a, b;

int dp[1001][1001];

int main() {
	FIO;

	cin >> a >> b; // a가 가로축 b가 세로축

	a.insert(a.begin(), '0');
	b.insert(b.begin(), '1');
	
	for (int x = 0; x <= a.size(); x++)
		dp[0][x] = 0;

	for (int y = 1; y < b.size(); y++) {
		for (int x = 1; x < a.size(); x++) {
			if (a[x] == b[y]) {
				dp[y][x] = dp[y - 1][x - 1] + 1;
				dp[y][x] = dp[y - 1][x - 1] + 1;
			}
			
			else 
				dp[y][x] = max(dp[y][x - 1], dp[y - 1][x]);
			
		}
	}

	cout << dp[b.size() - 1][a.size() - 1] << "\n";
}