#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 24700000


int N, M;

int m[55][55];
vector<pair<int, int>> pos_one;
vector<pair<int, int>> pos_two;

pair<int,int> a[55];
int s[55][55];

int ans = MAX;

void dfs(int idx, int cnt) {
	if (cnt >= M) {
		for (int i = 0; i < M; i++) {
			int y = a[i].first;
			int x = a[i].second;

			for (int e = 0; e < pos_one.size(); e++) {
				int yy = pos_one[e].first;
				int xx = pos_one[e].second;

				s[yy][xx] = min(s[yy][xx], abs(yy - y) + abs(xx - x));
			}
		}

		int tmp = 0;

		for (int i = 0; i < pos_one.size(); i++)
		{
			tmp += s[pos_one[i].first][pos_one[i].second];
			s[pos_one[i].first][pos_one[i].second] = MAX;
		}

		ans = min(ans, tmp);

		return;
	}
	for (int i = idx; i < pos_two.size(); i++) {
		a[cnt] = pos_two[i];
		dfs(i + 1, cnt + 1);
	}
}

void input() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> m[y][x];
			if (m[y][x] == 1) 
				pos_one.push_back(make_pair(y, x));
			if (m[y][x] == 2)
				pos_two.push_back(make_pair(y, x));

			s[y][x] = MAX;
		}
	}
}

int main() {
	FIO;

	cin >> N >> M;

	input();

	dfs(0, 0);

	cout << ans << "\n";
}
