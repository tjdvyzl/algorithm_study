#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define MAX 987654321

int N;
int arr[22][22];
int cnt = 0;

pair<int, int> s[22];

bool isPromising(int yy, int xx) {
	for (int i = 1; i < yy; i++) {
		if (s[i].first == yy)
			return false;
		if (s[i].second == xx)
			return false;

		int e = 1;
		int y = s[i].first;
		int x = s[i].second;

		if ((double)abs(y - yy) / (double)abs(x - xx) == 1)
			return false;
	}
	return true;
}

void N_Queen(int level) {
	if (level > N)
	{
		cnt += 1;
		return;
	}
	else {
		for (int x = 1; x <= N; x++) {
			if (isPromising(level, x)) {
				s[level] = make_pair(level, x);
				N_Queen(level + 1);
			}
		}
	}
}

int main() {
	cin >> N;
	N_Queen(1);
	cout << cnt << "\n";
}