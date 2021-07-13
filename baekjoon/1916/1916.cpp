#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 247000000

int N, M;
bool visit[1001];

class edge {
public:
	int dst;
	int cost;

	edge(int dst, int cost) :dst(dst), cost(cost) {}

	bool operator <(const edge& b)const {
		return this->cost > b.cost;
	}
};

vector<pair<int, int>> graph[1001];

int main() {
	ios_base::sync_with_stdio(0);

	priority_queue<edge> q;

	cin >> N >> M;

	while (M--) {
		int src, dst, cost;
		cin >> src >> dst >> cost;
		graph[src].push_back(make_pair(dst, cost));
	}

	vector<int>distance(N + 1, MAX);

	int s, d;
	cin >> s >> d;

	q.push(edge(s, 0));

	while (!q.empty()) {
		edge t = q.top();
		q.pop();
		int now_dst = t.dst;
		int now_cost = t.cost;

		if (visit[now_dst] == true) 
			continue;
		else
			visit[now_dst] = true;

		for (int i = 0; i < graph[now_dst].size(); i++) {
			int next_dst = graph[now_dst][i].first; // 4
			int next_cost = graph[now_dst][i].second + now_cost; // 2

			if (next_cost < distance[next_dst])
				distance[next_dst] = next_cost;

			else
				continue;

			q.push(edge(next_dst, next_cost));
		}
	}

	cout << distance[d] << "\n";
}