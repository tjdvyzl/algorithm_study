#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;
#define MAX 9999999999999


ll n, m; 
ll a, b;

class node {
public:
	int dst;
	int cost;
	node(int dst, int cost) :dst(dst), cost(cost) { }
};

vector<node> graph[1001];

vector<ll> dijkstra(int src) {
	vector<ll> dis(n + 1, MAX);
	dis[src] = 0;
	queue<node> q;
	q.push(node(src, 0));

	while (!q.empty()) {
		node t = q.front(); q.pop();
		ll current_pos = t.dst;
		ll current_cost = t.cost;

		if (dis[current_pos] < current_cost)
			continue;


		for (int i = 0; i < graph[current_pos].size(); i++) {
			ll next_pos = graph[current_pos][i].dst;
			ll next_cost = graph[current_pos][i].cost + current_cost;

			if (next_cost < dis[next_pos]) {
				dis[next_pos] = next_cost;
				q.push(node(next_pos, next_cost));
			}
		}
	}
	return dis;
}

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		ll src, dst, cost;
		cin >> src >> dst >> cost;
		graph[src].push_back(node(dst, cost));
		graph[dst].push_back(node(src, cost));
	}
	cin >> a >> b;
}

int main() {
	FIO;

	ll sum_dis1 = 0; // 1 -> a -> b -> n
	ll sum_dis2 = 0; // 1 -> b -> a -> n
	input();


	queue<node> q;

	vector<ll> dis_1_to_src1 = dijkstra(1);
	vector<ll> dis_src_to_dst1 = dijkstra(a);
	vector<ll> dis_dst_to_n1 = dijkstra(b);

	vector<ll> dis_1_to_src2 = dijkstra(1);
	vector<ll> dis_src_to_dst2 = dijkstra(b);
	vector<ll> dis_dst_to_n2 = dijkstra(a);

	sum_dis1 = dis_1_to_src1[a] + dis_src_to_dst1[b] + dis_dst_to_n1[n];
	sum_dis2 = dis_1_to_src2[b] + dis_src_to_dst2[a] + dis_dst_to_n2[n];

	ll ans = (sum_dis1 > sum_dis2) ? sum_dis2 : sum_dis1;
	if (ans >= MAX)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}
