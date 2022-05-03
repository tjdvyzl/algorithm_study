#include <iostream>
using namespace std;
#include <vector>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef pair<int, int> pii;

int N;

int _map[11][11];

int max_even = -1;
int max_odd = -1;

vector<pii> even;
vector<pii> odd;

bool v[11][11];

bool check(int y, int x)
{
    // 11시 방향
    int dy, dx;
    for (int i = 1;; i++)
    {
        dy = y - i;
        dx = x - i;
        if (dy <= 0 || dx <= 0)
            break;
        if (v[dy][dx] == true)
            return false;
    }

    // 1시 방향
    for (int i = 1;; i++)
    {
        dy = y - i;
        dx = x + i;
        if (dy <= 0 || dx > N)
            break;
        if (v[dy][dx] == true)
            return false;
    }

    // 5시 방향
    for (int i = 1;; i++)
    {
        dy = y + i;
        dx = x + i;
        if (dy > N || dx > N)
            break;
        if (v[dy][dx] == true)
            return false;
    }

    // 7시 방향
    for (int i = 1;; i++)
    {
        dy = y + i;
        dx = x - i;
        if (dy > N || dx <= 0)
            break;
        if (v[dy][dx] == true)
            return false;
    }

    return true;
}

void f_even(int idx, int cnt)
{
    for (int i = idx; i < even.size(); i++)
    {
        int y = even[i].first;
        int x = even[i].second;
        if (check(y, x))
        {
            v[y][x] = true;
            f_even(i + 1, cnt + 1);
            v[y][x] = false;
        }
    }

    max_even = (max_even < cnt) ? cnt : max_even;
}

void f_odd(int idx, int cnt)
{
    for (int i = idx; i < odd.size(); i++)
    {
        int y = odd[i].first;
        int x = odd[i].second;
        if (check(y, x))
        {
            v[y][x] = true;
            f_odd(i + 1, cnt + 1);
            v[y][x] = false;
        }
    }

    max_odd = (max_odd < cnt) ? cnt : max_odd;
}

int main()
{
    FIO;

    cin >> N;

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            cin >> _map[y][x];
            if ((x + y) % 2 == 0 && _map[y][x] == 1)
                even.push_back(make_pair(y, x));
            if ((x + y) % 2 != 0 && _map[y][x] == 1)
                odd.push_back(make_pair(y, x));
        }
    }

    f_even(0, 0);
    f_odd(0, 0);

    cout << max_even + max_odd << "\n";
}