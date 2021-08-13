#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
int T, M, N, x, y;

int gcd() {
	int a = M, b = N;
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int getAns() {
	if (x == y)
		return x;

	int limit = M * N / gcd(); // 60
	int cnt, plus;

	cnt = (x < y) ? x : y; // 10
	plus = (x < y) ? M : N; // 10

	int xx = cnt, yy = cnt;

	while (cnt <= limit) {
		xx = (xx + plus) % M;
		yy = (yy + plus) % N;

		if (xx == 0)
			xx = M;
		if (yy == 0)
			yy = N;
		cnt += plus;
		if (xx == x && yy == y)
			break;
	}

	if (cnt > limit) {
		return -1;
	}
	else
		return cnt;
}

int main() { // 10 12 10 12
	FIO;
	
	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;
		cout << getAns() << "\n";
	}
}