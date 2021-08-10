#include <bits/stdc++.h>
using namespace std;

int N, M; // 사다리의 수 , 뱀의 수

int ladder[101];
int snake[101];

class node {
public:
	int src;
	int dst;
	int cnt;

	node(int src, int dst, int cnt) :src(src), dst(dst), cnt(cnt) {}
};

vector<pair<int, bool>> getDir(int src) {
	vector<pair<int, bool>> vec;
	for (int i = src + 1; (i <= src + 6 && i <= 100); i++) {
		if (ladder[i] != 0)
			vec.push_back(make_pair(ladder[i], true));
		else if (snake[i] != 0)
			vec.push_back(make_pair(snake[i], true));
		else
			vec.push_back(make_pair(i, false));
	}


	return vec;
}

void bfs() {
	queue<node> q;
	q.push(node(1, 1, 0));

	vector<int> dis(101, 24700000);
	dis[1] = 0;

	while (!q.empty()) {
		node t = q.front(); q.pop();
		vector<pair<int, bool>> dst = getDir(t.dst);

		for (auto e : dst)
		{
			if (t.cnt + 1 < dis[e.first]) {
				q.push(node(t.dst, e.first, t.cnt + 1));
				dis[e.first] = t.cnt + 1;
			}
		}
	}
	cout << dis[100] << "\n";
}

int main() {
	cin >> N >> M;
	while (N--) { // 사다리 입력
		int a, b; cin >> a >> b;
		ladder[a] = b;
	}

	while (M--) { // 뱀 입력
		int a, b; cin >> a >> b;
		snake[a] = b;
	}

	bfs();
}