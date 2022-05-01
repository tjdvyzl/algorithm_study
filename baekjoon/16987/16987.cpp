#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N;

int _max = -1;

vector<pair<int, int>> vec;

void f(int idx)
{
    if (idx == N)
    {
        int cnt = 0;
        for (auto e : vec)
            if (e.first <= 0)
                cnt++;
        _max = max(_max, cnt);
        return;
    }

    if (vec[idx].first <= 0)
    {
        f(idx + 1);
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (i == idx || vec[i].first <= 0)
                continue;
            vec[i].first -= vec[idx].second;
            vec[idx].first -= vec[i].second;
            f(idx + 1);
            vec[i].first += vec[idx].second;
            vec[idx].first += vec[i].second;
        }
    }
    int cnt = 0;
    for (auto e : vec)
        if (e.first <= 0)
            cnt++;
    _max = max(_max, cnt);
}

int main()
{
    FIO;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int s, w; // 내구도, 무게
        cin >> s >> w;
        vec.push_back(make_pair(s, w));
    }

    f(0);

    cout << _max << "\n";
}
