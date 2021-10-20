#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;
#define MAX 9999999999999

class node {
public:
	ll dst, cost;
	node(ll dst, ll cost) :dst(dst), cost(cost) {}
};

vector<node> graph[111];
ll arr[111];
ll ans[111]; 
ll max_ans = -1;
vector<ll> dis;

ll n, m, r; // 지역의 개수, 예은이의 수색 범위, 길의 개수

ll dijkstra(ll idx) {
	queue<node> q;
	q.push(node(idx, 0));
	ll s = 0;

	while (!q.empty()) {
		node t = q.front(); q.pop();
		ll dst = t.dst;
		ll cost = t.cost;
		for (int i = 0; i < graph[dst].size(); i++) {
			ll next_dst = graph[dst][i].dst;
			ll next_cost = cost + graph[dst][i].cost;

			if (next_cost <= m && next_cost < dis[next_dst]) {
				dis[next_dst] = next_cost;
				q.push(node(next_dst, next_cost));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dis[i] <= m)
			s += arr[i];
	}
	

	return s;
}

int main() {
	FIO;

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	
	for (int i = 0; i < r; i++) {
		ll src, dst, cost;
		cin >> src >> dst >> cost;
		graph[src].push_back(node(dst, cost));
		graph[dst].push_back(node(src, cost));
	}
	for (int i = 1; i <= n; i++) {
		dis.clear();
		dis = vector<ll>(n + 1, MAX);
		dis[i] = 0;

		ll t = dijkstra(i);
		if (max_ans < t)
			max_ans = t;
	}
	cout << max_ans << "\n";
}
