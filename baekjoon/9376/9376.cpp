#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
#define MAX 987654321

char _map[123][123];
int dis[3][123][123]; // 0은 상근이 1 2는 각각 죄수들
int ans = MAX;

int dir_y[4] = { -1,1,0, 0 };
int dir_x[4] = { 0,0,-1,1 };

int h, w;
int T;

struct node {
	int y;
	int x;
	int cost;


	bool operator<(const node& b)const {
		return cost > b.cost;
	}
	
};

void djk(int idx, int yy, int xx) {
	priority_queue<node> q;

	// 상근이는 외부에서 안으로 들어가야 하므로 0,0 에서 시작하여 
	// 다익스트라로 각 지점들까지의 최솟값들을 구한다.

	dis[idx][yy][xx] = 0;
	q.push({yy, xx, 0});
		
		
	while (!q.empty()) {
		node t = q.top(); q.pop();

		/*cout << t.y << ", " << t.x << " " << t.cost << "\n";*/

		if (dis[idx][t.y][t.x] < t.cost)
			continue;

		for (int dir = 0; dir < 4; dir++) {
			int dy = t.y + dir_y[dir];
			int dx = t.x + dir_x[dir];
			int next_cost = t.cost;
				
			if (dy <= -1 || dy >= h + 2 || dx <= -1 || dx >= w + 2)
				continue;

			if (_map[dy][dx] == '*')
				continue;

			if (_map[dy][dx] == '#')
				next_cost++;

			
			if (next_cost < dis[idx][dy][dx]) {
				dis[idx][dy][dx] = next_cost;
				q.push({ dy, dx, next_cost });
			}
				
		}
	}
	

}

int main() {
	FIO;

	cin >> T;

	while (T--) {
		vector<pair<int, int>> prison;

		cin >> h >> w;

		for (int y = 1; y <= h; y++)
		{
			for (int x = 1; x <= w; x++) {
				cin >> _map[y][x];
				if (_map[y][x] == '$') {
					prison.push_back(make_pair(y, x));
				}
			}
		}

		for (int y = 0; y <= h + 1; y++) {
			_map[y][0] = '.';
			_map[y][w + 1] = '.';
		}

		for (int x = 0; x <= w + 1; x++) {
			_map[0][x] = '.';
			_map[h+1][x] = '.';
		}

		memset(dis, 0xf, sizeof(dis));
		
		djk(0, 0, 0);
		djk(1, prison[0].first, prison[0].second);
		djk(2, prison[1].first, prison[1].second);

		/*for (int i = 0; i < 3; i++) {

			for (int y = 0; y <= h + 1; y++)
			{
				for (int x = 0; x <= w + 1; x++) {
					if (dis[i][y][x] == MAX)
						cout << 0 << " ";
					else
						cout << dis[i][y][x] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		}*/

		for (int y = 0; y <= h + 1; y++) {
			for (int x = 0; x <= w + 1; x++) {
				if (_map[y][x] == '*') 
					continue;
				
				int sum = dis[0][y][x] + dis[1][y][x] + dis[2][y][x];

				if (_map[y][x] == '#')
					sum -= 2;

				ans = min(ans, sum);
			}
		}

		cout << ans << "\n";
		ans = MAX;
	}
}

