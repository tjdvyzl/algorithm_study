#include <bits/stdc++.h>
using namespace std;

vector<int> tree[101];
bool check[101];

void bfs(int e, vector<int> &distance) {
	queue<int> q;
	q.push(e);
	check[e] = true;

	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = 0; i < tree[t].size(); i++) {
			int d = tree[t][i];
			if (check[d] != true) {
				distance[d] = distance[t] + 1;
				check[d] = true;
				q.push(d);
			}
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	vector<int> cnt(101);

	for (int i = 1; i <= n; i++)
		check[i] = false;


	for (int i = 1; i <= n; i++) {
		vector<int> distance(101);

		bfs(i,distance);

		for (int e = 1; e <= n; e++)
			check[e] = false;

		int total = 0;

		for (int e = 1; e <= n; e++) 
			total += distance[e];
		
		cnt[i] = total;
	}

	int min_index = n;

	for (int i = n; i >= 1; i--) {
		if (cnt[min_index] >= cnt[i])
			min_index = i;
	}

	cout << min_index << "\n";
}