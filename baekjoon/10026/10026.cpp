#include <iostream>
#include <queue>
using namespace std;

int N;

char arr[101][101];
bool check[101][101]; // юШ╥о╩Ж╬Ю
int cnt_a = 0;
int cnt_b = 0;

void bfs_a(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		//╩С
		if (t.first > 1 && check[t.first - 1][t.second] != true && (arr[t.first - 1][t.second] == 'R' || arr[t.first - 1][t.second] == 'G')) {
			check[t.first - 1][t.second] = true;
			q.push(make_pair(t.first - 1, t.second));
		}
		//го
		if (t.first < N && check[t.first + 1][t.second] != true && (arr[t.first + 1][t.second] == 'R' || arr[t.first + 1][t.second] == 'G')) {
			check[t.first + 1][t.second] = true;
			q.push(make_pair(t.first + 1, t.second));
		}
		//аб
		if (t.second > 1 && check[t.first][t.second - 1] != true && (arr[t.first][t.second - 1] == 'R' || arr[t.first][t.second - 1] == 'G')) {
			check[t.first][t.second - 1] = true;
			q.push(make_pair(t.first, t.second - 1));
		}
		//©Л
		if (t.second < N && check[t.first][t.second + 1] != true && (arr[t.first][t.second + 1] == 'R' || arr[t.first][t.second + 1] == 'G')) {
			check[t.first][t.second + 1] = true;
			q.push(make_pair(t.first, t.second + 1));
		}
	}
}

void bfs_aa(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		//╩С
		if (t.first > 1 && check[t.first - 1][t.second] != true && arr[t.first - 1][t.second] == 'B') {
			check[t.first - 1][t.second] = true;
			q.push(make_pair(t.first - 1, t.second));
		}
		//го
		if (t.first < N && check[t.first + 1][t.second] != true && arr[t.first + 1][t.second] == 'B') {
			check[t.first + 1][t.second] = true;
			q.push(make_pair(t.first + 1, t.second));
		}
		//аб
		if (t.second > 1 && check[t.first][t.second - 1] != true && arr[t.first][t.second - 1] == 'B') {
			check[t.first][t.second - 1] = true;
			q.push(make_pair(t.first, t.second - 1));
		}
		//©Л
		if (t.second < N && check[t.first][t.second + 1] != true && arr[t.first][t.second + 1] == 'B') {
			check[t.first][t.second + 1] = true;
			q.push(make_pair(t.first, t.second + 1));
		}

	}
}

void bfs_b(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		//╩С
		if (t.first > 1 && check[t.first - 1][t.second] != true && arr[t.first - 1][t.second] == 'R') {
			check[t.first - 1][t.second] = true;
			q.push(make_pair(t.first - 1, t.second));
		}
		//го
		if (t.first < N && check[t.first + 1][t.second] != true && arr[t.first + 1][t.second] == 'R') {
			check[t.first + 1][t.second] = true;
			q.push(make_pair(t.first + 1, t.second));
		}
		//аб
		if (t.second > 1 && check[t.first][t.second - 1] != true && arr[t.first][t.second - 1] == 'R') {
			check[t.first][t.second - 1] = true;
			q.push(make_pair(t.first, t.second - 1));
		}
		//©Л
		if (t.second < N && check[t.first][t.second + 1] != true && arr[t.first][t.second + 1] == 'R') {
			check[t.first][t.second + 1] = true;
			q.push(make_pair(t.first, t.second + 1));
		}
	}
}

void bfs_bb(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		//╩С
		if (t.first > 1 && check[t.first - 1][t.second] != true && arr[t.first - 1][t.second] == 'G') {
			check[t.first - 1][t.second] = true;
			q.push(make_pair(t.first - 1, t.second));
		}
		//го
		if (t.first < N && check[t.first + 1][t.second] != true && arr[t.first + 1][t.second] == 'G') {
			check[t.first + 1][t.second] = true;
			q.push(make_pair(t.first + 1, t.second));
		}
		//аб
		if (t.second > 1 && check[t.first][t.second - 1] != true && arr[t.first][t.second - 1] == 'G') {
			check[t.first][t.second - 1] = true;
			q.push(make_pair(t.first, t.second - 1));
		}
		//©Л
		if (t.second < N && check[t.first][t.second + 1] != true && arr[t.first][t.second + 1] == 'G') {
			check[t.first][t.second + 1] = true;
			q.push(make_pair(t.first, t.second + 1));
		}
	}
}

void bfs_bbb(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		//╩С
		if (t.first > 1 && check[t.first - 1][t.second] != true && arr[t.first - 1][t.second] == 'B') {
			check[t.first - 1][t.second] = true;
			q.push(make_pair(t.first - 1, t.second));
		}
		//го
		if (t.first < N && check[t.first + 1][t.second] != true && arr[t.first + 1][t.second] == 'B') {
			check[t.first + 1][t.second] = true;
			q.push(make_pair(t.first + 1, t.second));
		}
		//аб
		if (t.second > 1 && check[t.first][t.second - 1] != true && arr[t.first][t.second - 1] == 'B') {
			check[t.first][t.second - 1] = true;
			q.push(make_pair(t.first, t.second - 1));
		}
		//©Л
		if (t.second < N && check[t.first][t.second + 1] != true && arr[t.first][t.second + 1] == 'B') {
			check[t.first][t.second + 1] = true;
			q.push(make_pair(t.first, t.second + 1));
		}
	}
}

int main() {
	cin >> N;

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> arr[y][x];

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (check[y][x] == true)
				continue;
			cnt_a++;
			if (arr[y][x] == 'R' || arr[y][x] == 'G')
				bfs_a(y, x);
			if (arr[y][x] == 'B')
				bfs_aa(y, x);
		}
	}

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			check[y][x] = false;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (check[y][x] == true)
				continue;
			cnt_b++;
			if (arr[y][x] == 'R')
				bfs_b(y, x);
			if (arr[y][x] == 'G')
				bfs_bb(y, x);
			if (arr[y][x] == 'B')
				bfs_bbb(y, x);
		}
	}

	cout << cnt_b << " " << cnt_a << "\n";
}