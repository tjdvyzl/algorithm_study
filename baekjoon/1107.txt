#include <bits/stdc++.h>
using namespace std;

int len = 0;
int c;

vector<int> vec;

int _min = 500001;
int bound = 0;
int min_bound = 500001;

int getLength(int input) {
	if (input == 0)
		return 1;

	int l = input;
	int ccc = 0;
	while (l > 0) {
		l /= 10;
		ccc++;
	}
	return ccc;
}

void check(int cnt) {
	for (int e = 0; e < vec.size(); e++) {
		bound += vec[e] * pow(10, cnt);

		if (abs(c - bound) < _min) {
			min_bound = bound;
			_min = abs(c - bound);
		}

		if (abs(c - bound) == _min && min_bound > bound)
			min_bound = bound;

		if (cnt < len)
			check(cnt + 1);
		
		bound -= vec[e] * pow(10, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(0);

	int arr[10] = { 1,1,1,1,1,1,1,1,1,1 };

	cin >> c;

	int cc = c;
	while (cc > 0) {
		cc /= 10;
		len++;
	}

	int n; cin >> n;

	while (n--) {
		int input; cin >> input;
		arr[input] = -1;
	}

	for (int i = 0; i < 10; i++) 
		if (arr[i] != -1)
			vec.push_back(i);

	if (c == 100) {
		cout << 0 << "\n";
		return 0;
	}

	check(0);

	int ans = _min + getLength(min_bound);

	if (abs(c - 100) < ans)
		cout << abs(c - 100) << "\n";
	else
		cout << ans << "\n";
}