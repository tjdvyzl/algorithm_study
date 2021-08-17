#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define MAX 987654321

int TC;

int main() {
	cin >> TC;

	while (TC--) {
		int N, M, W; // 지점의 수, 도로의 개수, 웜홀의 개수
		cin >> N >> M >> W;

		vector<pair<int, int>> graph[555];
		vector<int> dis(N + 1, MAX);

		for (int i = 2; i <= M + 1; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back(make_pair(e, t));
			graph[e].push_back(make_pair(s, t));
		}
		for (int i = M + 2; i <= M + W + 1; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back(make_pair(e, -t));
		}

		dis[1] = 0;

		bool check;

		for (int i = 1; i <= N; i++) {
			check = false;
			for (int e = 1; e <= N; e++) {

				for (int r = 0; r < graph[e].size(); r++) {
					int dst = graph[e][r].first;
					int cost = graph[e][r].second;

					if (dis[dst] > dis[e] + cost)
					{
						dis[dst] = dis[e] + cost;
						check = true;
					}
				}
			}
			if (check == false)
				break;
		}
		if (check == true)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}