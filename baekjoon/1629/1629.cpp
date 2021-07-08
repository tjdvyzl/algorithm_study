#include <bits/stdc++.h>
using namespace std;

int A, B, C;

int p(int n, int k) {

	if (k == 0)
		return 1;
	

	int temp = p(n, k / 2);

	int r = 1LL * temp * temp % C;

	if (k % 2)
		 r = 1LL * r * n % C;

	return r;
}

int main() {
	cin >> A >> B >> C;
	cout << p(A, B) << "\n";
}