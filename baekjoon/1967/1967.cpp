#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

class node {
public:
	int dst;
	int cost;

	node(int dst, int cost) : dst(dst), cost(cost) {}
};

vector<node> tree[10001];

bool check[10001];

int max_cost = 0;
int temp_max_cost = 0;

int T;

void input() {
	cin >> T;

	for (int i = 0; i < T - 1; i++) {
		int par, chi, cost;
		cin >> par >> chi >> cost;
		tree[par].push_back(node(chi, cost));
	}
}

void dfs(int input, int cost) {
	check[input] = true;
	for (int i = 0; i < tree[input].size(); i++) {
		int next_dst = tree[input][i].dst;
		int next_cost = tree[input][i].cost;

		dfs(next_dst, cost + next_cost);
	}

	if (cost > temp_max_cost)
		temp_max_cost = cost;
}

int main() {
	FIO;

	input();

	for (int i = 1; i <= T; i++) {
		priority_queue<int> pq;

		for (int j = 0; j < tree[i].size(); j++) {
			int next_dst = tree[i][j].dst;
			int next_cost = tree[i][j].cost;
			dfs(next_dst, next_cost);
			pq.push(temp_max_cost);
			temp_max_cost = 0;
		}

		int e = 0;
		if (!pq.empty()) {
			e += pq.top(); pq.pop();
		}
		if (!pq.empty()) {
			e += pq.top(); pq.pop();
		}
		max_cost = max(max_cost, e);

	}

	cout << max_cost << "\n";
}