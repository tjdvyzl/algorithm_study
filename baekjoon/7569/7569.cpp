#include <iostream>
#include <queue>
using namespace std;

int m, n, h; // 가로 세로 높이
int arr[101][101][101];
bool check[101][101][101];

class node {
public:
	int height;
	int hor;
	int ver;

	node(int height, int ver, int hor) :height(height), hor(hor), ver(ver) {}
};

queue<node> q;
int cnt = -1;
int one_cnt = 0;
int _minus = 0;

void bfs() {
	if (q.empty())
		return;
	queue<node> temp;
	while (!q.empty()) {
		node t = q.front(); q.pop();

		if (t.height <= h - 1 && arr[t.height + 1][t.ver][t.hor] != -1) {	// 위
			if (check[t.height + 1][t.ver][t.hor] != true) {
				check[t.height + 1][t.ver][t.hor] = true;
				temp.push(node(t.height + 1, t.ver, t.hor));
				one_cnt++;
			}
		}
		if (t.height > 1 && arr[t.height - 1][t.ver][t.hor] != -1) {	// 아래
			if (check[t.height - 1][t.ver][t.hor] != true) {
				check[t.height - 1][t.ver][t.hor] = true;
				temp.push(node(t.height - 1, t.ver, t.hor));
				one_cnt++;
			}
		}
		if (t.ver > 1 && arr[t.height][t.ver - 1][t.hor] != -1) { // 왼쪽
			if (check[t.height][t.ver - 1][t.hor] != true) {
				check[t.height][t.ver - 1][t.hor] = true;
				temp.push(node(t.height, t.ver - 1, t.hor));
				one_cnt++;
			}
		}
		if (t.ver <= n - 1 && arr[t.height][t.ver + 1][t.hor] != -1) { // 오른쪽
			if (check[t.height][t.ver + 1][t.hor] != true) {
				check[t.height][t.ver + 1][t.hor] = true;
				temp.push(node(t.height, t.ver + 1, t.hor));
				one_cnt++;
			}
		}
		if (t.hor <= m - 1 && arr[t.height][t.ver][t.hor + 1] != -1) { // 앞
			if (check[t.height][t.ver][t.hor + 1] != true) {
				check[t.height][t.ver][t.hor + 1] = true;
				temp.push(node(t.height, t.ver, t.hor + 1));
				one_cnt++;
			}
		}
		if (t.hor > 1 && arr[t.height][t.ver][t.hor - 1] != -1) { // 뒤
			if (check[t.height][t.ver][t.hor - 1] != true) {
				check[t.height][t.ver][t.hor - 1] = true;
				temp.push(node(t.height, t.ver, t.hor - 1));
				one_cnt++;
			}
		}
	}
	cnt++;
	q = temp;
	bfs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;
	for (int hh = h; hh >= 1; hh--) {
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= m; x++) {
				cin >> arr[hh][y][x];
				if (arr[hh][y][x] == 1) {
					q.push(node(hh, y, x));
					check[hh][y][x] = true;
					one_cnt++;
				}
				else if (arr[hh][y][x] == -1)
					_minus++;
			}
		}
	}
	bfs();
	if (one_cnt + _minus < h * m * n)
		cout << -1 << "\n";
	else
		cout << cnt << "\n";
}