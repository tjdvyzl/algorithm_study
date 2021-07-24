#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int n; // 도시의 개수
int m; // 버스의 개수

class edge {
public:
	int dst;
	int cost;

	edge(int dst, int cost):dst(dst),cost(cost){}

	bool operator < (const edge& b) const{
		return this->cost > b.cost;
	}
};

vector<edge> graph[101];

int main() {
	ios_base::sync_with_stdio(0);
	

	cin >> n; 
	cin >> m;
	
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;  // src, dst, cost

		graph[a].push_back(edge(b, c));
	}

	priority_queue<edge> pq;

	for (int i = 1; i <= n; i++) {
		pq.push(edge(i, 0));
		vector<int> distance(101, 247000000);
		while (!pq.empty()) {
			int current_dst = pq.top().dst;
			int current_cost = pq.top().cost;
			pq.pop();
			for (int i = 0; i < graph[current_dst].size(); i++) { 
				int next_dst = graph[current_dst][i].dst;
				int next_cost = current_cost + graph[current_dst][i].cost;
				
				if (distance[next_dst] > next_cost) {
					distance[next_dst] = next_cost;
					pq.push(edge(next_dst, next_cost));
				}
			}
		}
		for (int e = 1; e <= n; e++) {
			if (e == i)
				cout << 0 << " ";
			else {
				if (distance[e] == 247000000)
					cout << 0 << " ";
				else
					cout << distance[e] << " ";
			}
		}
		cout << "\n";
	}
}