#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int M, N; // 세로 가로

int m[505][505];

int dp[505][505];

bool v[505][505];

int dir_y[4] = {-1, 1, 0, 0};
int dir_x[4] = {0, 0, -1, 1};

bool check(int dy, int dx, int current_value)
{
    if (dy <= 0 || dx <= 0 || dy > M || dx > N)
        return false;
    if (m[dy][dx] >= current_value)
        return false;
    return true;
}

void dfs(int y, int x)
{
    v[y][x] = true;

    if (y == M && x == N)
    {
        dp[y][x]++;
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int dy = y + dir_y[dir];
        int dx = x + dir_x[dir];

        if (!check(dy, dx, m[y][x]))
            continue;

        if (!v[dy][dx])
            dfs(dy, dx);

        dp[y][x] += dp[dy][dx];
    }
}

int main()
{
    FIO;

    cin >> M >> N;
    for (int y = 1; y <= M; y++)
        for (int x = 1; x <= N; x++)
            cin >> m[y][x];

    dfs(1, 1);

    cout << dp[1][1] << "\n";
}