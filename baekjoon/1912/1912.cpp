#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 12345678912

typedef long long ll;

int T;

ll _min = MAX; // ���� ���� ������ �� �ߴ� sum �� ���� ���� ��
ll max_sum = -MAX;
ll sum = 0;

int main() {
	FIO;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int input; cin >> input;
		sum += input;

		if (i == 0)
			max_sum = sum;

		max_sum = max(max_sum, max(sum, (sum - _min)));
		_min = min(_min, sum);
	}

	cout << max_sum << "\n";
}