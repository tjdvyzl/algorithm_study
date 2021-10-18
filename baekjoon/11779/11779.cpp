#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;
#define MAX 99999999

int n, m; 
int src, dst;

class node {
public:
	int dst;
	int cost;
	node(int dst, int cost) :dst(dst), cost(cost) { }
};

vector<node> graph[1001];
string ans = "";
int ans_count = 0;
int arr[1005];

//vector<int> vec;
//
//void dfs(int current_pos, int current_cost, int count) {
//	if (current_pos == dst) {
//		if (current_cost < min_dis) {
//			min_dis = current_cost;
//			ans_count = count;
//			vec.clear();
//			for (int i = 0; i < count + 1; i++)
//				vec.push_back(arr[i]); 
//		}
//		return;
//	}
//	for (int i = 0; i < graph[current_pos].size(); i++) {
//		int next_pos = graph[current_pos][i].dst;
//		int next_cost = graph[current_pos][i].cost + current_cost;
//
//		if (next_cost < dis[next_pos])
//		{
//			dis[next_pos] = next_cost;
//			arr[count + 1] = next_pos;
//
//			dfs(next_pos, next_cost, count + 1);
//		}
//		else
//			continue;
//	}
//}

int main() {
	FIO;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int src, dst, cost;
		cin >> src >> dst >> cost;
		graph[src].push_back(node(dst, cost));
	}

	cin >> src >> dst;

	queue<node> q;
	vector<int> dis(n + 1, MAX);

	dis[src] = 0;

	arr[src] = -1;

	q.push(node(src, 0));

	while (!q.empty()) {
		node t = q.front(); q.pop();
		int current_pos = t.dst;
		int current_cost = t.cost;

		if (dis[current_pos] < current_cost) {
			continue;
		}

		for(int i=0;i<graph[current_pos].size();i++){
			int next_pos = graph[current_pos][i].dst;
			int next_cost = graph[current_pos][i].cost + current_cost;

			if (next_cost < dis[next_pos]) {
				dis[next_pos] = next_cost;
				arr[next_pos] = current_pos;
				cout << "arr[" << next_pos << "] = " << current_pos << "\n";
				q.push(node(next_pos, next_cost));
			}
		}
	}

	int t = dst;

	vector<int> vec;

	while (t != -1) {
		vec.push_back(t);
		t = arr[t];
	}
	cout << dis[dst] << "\n";

	cout << vec.size() << "\n";

	for (int i = vec.size() - 1; i >= 0; i--)
		cout << vec[i] << " ";
	cout << "\n";
}
