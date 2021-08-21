#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define MAX 987654321

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix ans = { {1,0}, {0,1} };
matrix bound = { {1,1},{1,0} };

ll m = 1000000007;

matrix operator * (const matrix& a, const matrix& b) {
	matrix c(2, vector<ll>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int e = 0; e < 2; e++) {
				c[i][j] += a[i][e] * b[e][j];
			}
			c[i][j] %= m;
		}
	}
	return c;
}

ll n;

matrix p(ll k) {
	if (k == 1) {
		return bound;
	}

	matrix temp = p(k / 2);

	matrix r = temp * temp ;

	if (k % 2) {
		r = r * bound;
	}

	return r;
}

int main() {
	FIO;

	cin >> n;

	if (n <= 1)
		cout << n << "\n";
	else {
		matrix ans = p(n - 1);

		cout << ans[0][0] << "\n";
	}
	
}