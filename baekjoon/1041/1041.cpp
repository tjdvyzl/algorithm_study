#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

int main() {
	FIO;

	vector<ll> vec;

	int three_min = -1;
	int two_min = -1;
	int one_min = -1;
	int one_max = -1;

	ll n; cin >> n;
	for (int i = 0; i < 6; i++) {
		ll input; cin >> input;
		vec.push_back(input);
		if (one_min == -1)
			one_min = input;
		if (one_min > input)
			one_min = input;
		if (one_max < input)
			one_max = input;
	}

	for (int i = 0; i <= 4; i++) {
		ll sum = vec[i];
		for (int j = i + 1; j < 6; j++) {
			if (j != 5 - i) {
				sum += vec[j];
				if (two_min == -1)
					two_min = sum;
				if (two_min > sum)
					two_min = sum;
				sum -= vec[j];
			}
		}
	}

	//1 6¿Ã ∂—≤±   0 1 2 3 4 5 
	int u = -1, d = -1;
	for (int i = 0; i < 3; i++) {
		if (i == 0)
			u = 0, d = 5;
		else if (i == 1)
			u = 1, d = 4; // 0 2 3 5
		else
			u = 2, d = 3;
		for (int j = 0; j < 5; j++) {
			ll sum = 0;
			int bound = 5 - j;
			if (j != u && j != d) {
				sum += vec[j];
				for (int e = j + 1; e < 6; e++) {
					if (e != u && e != d && e != bound) {
						sum += vec[e];
						if (three_min == -1)
							three_min = sum + vec[u];
						if (three_min > sum + vec[u])
							three_min = sum + vec[u];
						if (three_min > sum + vec[d])
							three_min = sum + vec[d];
						sum -= vec[e];
					}
				}
			}
		}
	}

	if (n == 1) {
		ll sum = 0;
		for (auto e : vec)
			sum += e;
		cout << sum - one_max << "\n";
	}
	else {
		ll sum = 0;
		sum += ((n - 2) * (n - 1) * 4 * one_min) + ((n - 2) * (n - 2) * one_min); // 1
		sum += (4 * (n - 1) * two_min) + (4 * (n - 2) * two_min); // 2
		sum += 4 * three_min; // 3
		cout << sum << "\n";
	}
}