#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1000000001

typedef long long ll;

int N, M; // 세로 가로

int _map[9][9];
bool _visit[9][9];

int one = 0;
int two = 0;

int tmp_two;
int tmp_one;

int _max = -1;

pair<int,int> s[3] = {}; // 세운 벽 위치
vector<pair<int, int>> vec; // 2의 위치 저장

int dir_y[4] = { -1, 1,0,0 };
int dir_x[4] = { 0,0,-1,1 };

bool check(int y, int x) {
	if (y > N || y < 1 || x > M || x < 1)
		return false;

	for (int i = 0; i < 3; i++)
		if (s[i].first == y && s[i].second == x)
			return false;
	
	if (_map[y][x] == 1 || _map[y][x] == 2)
		return false;

	if (_visit[y][x] == true)
		return false;

	return true;
}

void bfs() {
	tmp_one = one;
	tmp_two = two;
	memset(_visit, 0, sizeof(_visit));

	queue<pair<int, int>> q;
	for (int i = 0; i < vec.size(); i++) {
		q.push(make_pair(vec[i].first, vec[i].second));
	}
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = t.first + dir_y[i];
			int dx = t.second + dir_x[i];

			if (check(dy, dx)) {
				_visit[dy][dx] = true;
				q.push(make_pair(dy, dx));
				tmp_two++;
			}
		}
	}
}

void setWall(int cnt, int before_y, int before_x) {
	if (cnt >= 3) {
		//for(int i=0;i<3;i++)
		//	cout << "(" << s[i].first << ", " << s[i].second << ")" << " ";
		//cout << "\n";
		bfs();

		_max = max(_max, (N * M - tmp_two - tmp_one - 3));
	}
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (_map[y][x] == 0) {
				bool isExist = false;
				for (int i = 0; i < 3; i++) {
					if (y == s[i].first && x == s[i].second)
					{
						isExist = true;
						break;
					}
				}
				if (isExist == true)
					continue;
				else if(isExist == false && cnt < 3 && (y > before_y || x > before_x)){
					s[cnt] = make_pair(y, x);
					setWall(cnt + 1, y,x);
				}
			}
		}
	}
}

int main() {
	FIO;

	cin >> N >> M;

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= M; x++) {
			cin >> _map[y][x];
			if (_map[y][x] == 1)
				one++;
			else if (_map[y][x] == 2) {
				vec.push_back(make_pair(y, x));
				two++;
			}
		}

	setWall(0, 0, 0);

	cout << _max << "\n";
}