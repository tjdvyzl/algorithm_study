#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

/*
    int d[4];
        d[0] = (e % 5 == 0) ? e : e - 1;
        d[1] = ((e + 1) % 5 == 0) ? e : e + 1;
        d[2] = (e - 5 < 0) ? e : (e / 5 - 1) * 5 + e % 5;
        d[3] = (e + 5 > 24) ? e : (e + 5);
*/

vector<int> vec; // 1차원 벡터로 백트래킹

string _map[5];

bool v[6][6];

int arr[8];

int ans = 0;

bool vis[26];

void dfs(int idx)
{
    vis[arr[idx]] = true;
    int d[4];
    int e = arr[idx];
    d[0] = (e % 5 == 0) ? e : e - 1;
    d[1] = ((e + 1) % 5 == 0) ? e : e + 1;
    d[2] = (e - 5 < 0) ? e : (e / 5 - 1) * 5 + e % 5;
    d[3] = (e + 5 > 24) ? e : (e + 5);
    for (int i = 0; i < 7; i++)
    {
        if (vis[arr[i]])
            continue;
        for (int dir = 0; dir < 4; dir++)
        {
            int next_pos = d[dir];
            if (next_pos == -1)
                continue;
            if (vis[next_pos])
                continue;
            for (int a = 0; a < 7; a++)
            {
                if (arr[a] == next_pos)
                {
                    dfs(a);
                    break;
                }
            }
        }
    }
}

// 현재 arr 배열들이 모두 연결되어있는지
bool isAllConected()
{
    memset(vis, false, sizeof(vis));
    dfs(0);
    for (int i = 0; i < 7; i++)
    {
        if (!vis[arr[i]])
            return false;
    }
    return true;
}

void f(int idx, int cnt)
{
    if (cnt >= 7)
    {
        // 만약 다 연결 되어 있다면
        if (isAllConected())
        {
            int cnt = 0;
            for (int i = 0; i < 7; i++)
            {
                if (_map[arr[i] / 5][arr[i] % 5] == 'S')
                    cnt++;
            }
            if (cnt >= 4)
                ans++;
        }
        return;
    }
    for (int i = idx; i < vec.size(); i++)
    {
        arr[cnt] = vec[i];
        f(i + 1, cnt + 1);
    }
}

int main()
{
    FIO;

    for (int i = 0; i < 5; i++)
        cin >> _map[i];

    for (int i = 0; i <= 24; i++)
        vec.push_back(i);

    f(0, 0);

    cout << ans << "\n";
}