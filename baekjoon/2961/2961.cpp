#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1000000001

typedef long long ll;

int main() {
	FIO;

	int n;
	cin >> n;
	
	pair<int, int> arr[11];
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}

	ll min_sub = 21000000000;

	for (int i = 1; i < (1 << n); ++i) {
		ll s = 1; // ½Å¸À
		ll ss = 0; // ¾´¸À
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				s *= arr[j].first;
				ss += arr[j].second;
			}
		}
		min_sub = min(min_sub, abs(s - ss));
	}

	cout << min_sub << "\n";
}