#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

char dir[4] = {'U', 'D', 'L', 'R'};

int dir_y[4] = {-1, 1, 0, 0};
int dir_x[4] = {0, 0, -1, 1};
int N, M;

string _map[555];

bool v[555][555]; // dfs 동안 방문했는지 여부

bool dp[555][555]; // true면 탈출 가능

bool isOut(int y, int x)
{
    if (y < 0 || x < 0 || y >= N || x >= M)
        return true;
    return false;
}

int cnt = 0;

void dfs(char input, int y, int x)
{
    v[y][x] = true;

    int d;
    for (int i = 0; i < 4; i++)
        if (dir[i] == input)
            d = i;

    int dy = dir_y[d] + y;
    int dx = dir_x[d] + x;

    if (isOut(dy, dx))
    {
        dp[y][x] = true;

        return;
    }

    if (v[dy][dx])
    {
        if (dp[dy][dx])
            dp[y][x] = true;

        return;
    }

    dfs(_map[dy][dx], dy, dx);

    if (dp[dy][dx])
        dp[y][x] = true;
}

int main()
{
    FIO;

    cin >> N >> M;

    for (int y = 0; y < N; y++)
        cin >> _map[y];

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (v[y][x])
                continue;

            dfs(_map[y][x], y, x);
        }
    }

    int ans = 0;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (dp[y][x])
                ans++;

    cout << ans << "\n";
}