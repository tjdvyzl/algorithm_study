#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];
int cnt[10001];

//10 20 10 30 20 50

int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		dp[i] = input;
		cnt[i]++;
		int _max = 0;
		for (int j = 0; j < i; j++) {
			if (dp[i] > dp[j]) {
				if (cnt[j] > _max)
					_max = cnt[j];
			}
		}
		cnt[i] += _max;
	}

	int mmax = -1;
	for (int i = 0; i < n; i++)
		if (cnt[i] > mmax)
			mmax = cnt[i];

	cout << mmax << "\n";

}