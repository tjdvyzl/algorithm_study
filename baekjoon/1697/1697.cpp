#include <iostream>
using namespace std;
#include <vector>
#include <queue>

#define MAX 24700000

int n, k;

vector<int> graph[200001];

vector<int> dis(200001, MAX);

bool check[200001];

queue<int> q;

void bfs(int input) {
	q.push(input);
	dis[input] = 0;
	while (!q.empty()) {
		int t = q.front(); 
		q.pop();

		check[t] = true;

		int dir[3] = { t - 1,t + 1,t * 2 }; // 4 6 10
		
		for (int i = 0; i < 3; i++) {
			if (dir[i] < 0 || dir[i] >= 200001)
				continue;
			if (check[dir[i]] != true) {
				if (dis[dir[i]] > dis[t] + 1) {
					dis[dir[i]] = dis[t] + 1;
				}
				q.push(dir[i]);
			}
			else
				continue;
		}
	}
}


int main() {
	cin >> n >> k;

	bfs(n);

	cout << dis[k] << "\n";
}