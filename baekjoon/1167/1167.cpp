#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

class node {
public:
	int dst;
	int cost;

	node(int dst, int cost) : dst(dst), cost(cost) {}
};

vector<node> tree[100001];

int T;
int max_dis = -1;

bool check[100001];
bool sub_check[100001];

int max_cost = 0;
int temp_max_cost = 0;


void input() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		int parent; cin >> parent;
		int dst, cost;
		while (cin >> dst && dst != -1 && cin >> cost) 
			tree[parent].push_back(node(dst, cost));
		
	}
}

void dfs2(int input, int cost) { // 3 2
	sub_check[input] = true;
	for (int i = 0; i < tree[input].size(); i++) {
		int next_dst = tree[input][i].dst;
		int next_cost = tree[input][i].cost;
		
		if (sub_check[next_dst] != true && check[next_dst] != true) {
			dfs2(next_dst, cost + next_cost);
		}
	}

	if (cost > temp_max_cost)
		temp_max_cost = cost;
}

int getMax(int input) { // 1

	priority_queue<int> pq;

	for (int i = 0; i < tree[input].size(); i++) {
		int next_dst = tree[input][i].dst;
		int next_cost = tree[input][i].cost;

		dfs2(next_dst, next_cost); // 3 2
		
		pq.push(temp_max_cost);
		temp_max_cost = 0;
	}

	int _max = 0;
	if (!pq.empty())
	{
		_max += pq.top(); pq.pop();
	}
	if (!pq.empty())
	{
		_max += pq.top(); pq.pop();
	}
	return _max;
}

void dfs(int input) { // 1
	check[input] = true;
	if (input != 1 && tree[input].size() == 1)
		return;
	max_cost = max(max_cost, getMax(input));
	memset(sub_check, 0, sizeof(sub_check));
	for (int i = 0; i < tree[input].size(); i++)
	{
		int next_dst = tree[input][i].dst;
		if(check[next_dst] != true)
			dfs(next_dst);
	}
}

int main() {
	FIO;

	input();

	dfs(1);

	cout << max_cost << "\n";
}