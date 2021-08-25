#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define MAX 9876543211

typedef long long ll;

class wall {
public:
	int xx;
	int yy;
	bool isBroken = false;
	int dis = 0;

	wall(int yy, int xx, int dis, bool isBroken) :xx(xx), yy(yy), dis(dis), isBroken(isBroken) {};
};

int Y, X;
char mmap[1001][1001];
bool v[1001][1001][2]; // 0은 안부수고 방문  1은 부수고 방문

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

bool check(int y, int x) {
	if (y < 1 || y > Y || x < 1 || x > X)
		return false;
	else
		return true;
}

int bfs() {
	queue<wall> q;

	q.push(wall(1, 1, 1, false));

	while (!q.empty()) {
		wall t = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = t.xx + dx[dir];
			int ny = t.yy + dy[dir];

			if (!check(ny, nx))
				continue;

			if (nx == X && ny == Y)
				return (t.dis + 1);

			if (mmap[ny][nx] == '1') {
				if (t.isBroken)
					continue;

				q.push(wall(ny, nx, t.dis + 1, true));
			}
			else if(mmap[ny][nx] == '0') {
				if (!t.isBroken) {
					if (v[ny][nx][0])
						continue;
					else
						v[ny][nx][0] = true;
				}
				else {
					if (v[ny][nx][1])
						continue;
					else
						v[ny][nx][1] = true;
				}

				q.push(wall(ny, nx, t.dis + 1, t.isBroken));
			}
		}
	}
	return -1;
}

int main() {
	FIO;

	cin >> Y >> X;


	for (int yy = 1; yy <= Y; yy++)
		for (int xx = 1; xx <= X; xx++)
			cin >> mmap[yy][xx];

	if (Y == 1 && X == 1)
	{		
		cout << 1 << "\n";
		return 0;
	}
		

	cout << bfs() << "\n";
}