#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<pair<int, int>> graph[20001];

struct edge {
	int dst;
	int cost;

	edge(int dst, int cost):dst(dst),cost(cost){}

	bool operator<(const edge &b)const{
		return cost > b.cost;
	}
};

int main() {
	ios_base::sync_with_stdio(0);

	priority_queue<edge> q;

	cin >> V >> E;

	int k; cin >> k;

	while (E--) {
		int src, dst, cost;
		cin >> src >> dst >> cost;
		if (dst == k) continue;
		graph[src].push_back(make_pair(dst, cost));
	}
	
	q.push(edge(k, 0));

	vector<int> dist(V + 1, 2147000000);

	dist[k] = 0;

	while (!q.empty()) {
		int now = q.top().dst;
		int now_cost = q.top().cost;

		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int next_cost = graph[now][i].second;

			if (dist[next] > next_cost + now_cost) {
				dist[next] = next_cost + now_cost;
				q.push(edge(next, next_cost + now_cost));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] > 200000)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	cout << "\n";
}