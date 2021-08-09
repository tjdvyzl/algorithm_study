#include <bits/stdc++.h>
using namespace std;

int N;
int arr[21][21];
int shark = 2;
int current_shark_y = 0;
int current_shark_x = 0;
int ans = 0;
int eat = 0;
int c = 0;

class node {
public:
	int y;
	int x;
	int cnt;

	node(int y, int x, int cnt):y(y),x(x),cnt(cnt) {}
};

struct compare {
	bool operator()(node a, node b) {
		if (a.cnt != b.cnt)
			return a.cnt > b.cnt;
		else {
			if (a.y != b.y)
				return a.y > b.y;
			else
				return a.x > b.x;
		}
	}
};


void bfs(int y, int x) {
	arr[y][x] = 0;

	priority_queue<node, vector<node>, compare> pq;

	queue<node> q;
	q.push(node(y, x, 0));

	bool visit[21][21];

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			visit[y][x] = false;

	visit[y][x] = true;

	while (!q.empty()) {
		node t = q.front(); q.pop();
		//╩С
		if (t.y - 1 >= 1 && visit[t.y - 1][t.x] != true && arr[t.y - 1][t.x] <= shark) {
			if (arr[t.y - 1][t.x] > 0 && arr[t.y - 1][t.x] < shark)
				pq.push(node(t.y - 1, t.x, t.cnt + 1));
			visit[t.y - 1][t.x] = true;
			q.push(node(t.y - 1, t.x, t.cnt + 1));
		}
		//го
		if (t.y + 1 <= N && visit[t.y + 1][t.x] != true && arr[t.y + 1][t.x] <= shark) {
			if (arr[t.y + 1][t.x] > 0 && arr[t.y + 1][t.x] < shark)
				pq.push(node(t.y + 1, t.x, t.cnt + 1));
			visit[t.y + 1][t.x] = true;
			q.push(node(t.y + 1, t.x, t.cnt + 1));
		}
		//аб
		if (t.x - 1 >= 1 && visit[t.y][t.x - 1] != true && arr[t.y][t.x - 1] <= shark) {
			if (arr[t.y][t.x - 1] > 0 && arr[t.y][t.x - 1] < shark)
				pq.push(node(t.y, t.x - 1, t.cnt + 1));
			visit[t.y][t.x - 1] = true;
			q.push(node(t.y, t.x - 1, t.cnt + 1));
		}
		//©Л
		if (t.x + 1 <= N && visit[t.y][t.x + 1] != true && arr[t.y][t.x + 1] <= shark) {
			if (arr[t.y][t.x + 1] > 0 && arr[t.y][t.x + 1] < shark)
				pq.push(node(t.y, t.x + 1, t.cnt + 1));
			
			visit[t.y][t.x + 1] = true;
			q.push(node(t.y, t.x + 1, t.cnt + 1));
		}
	}

	if (pq.empty())
		return;

	eat++;
	if (eat >= shark) {
		eat = 0;
		shark++;
	}

	node t = pq.top();
	ans += t.cnt;
	current_shark_y = t.y, current_shark_x = t.x;
	bfs(current_shark_y, current_shark_x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 9)
				current_shark_y = y, current_shark_x = x;
		}
	}

	bfs(current_shark_y, current_shark_x);

	cout << ans << "\n";
}