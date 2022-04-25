#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N, L;
vector<pair<int, int>> vec;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main()
{
    FIO;

    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }

    sort(vec.begin(), vec.end(), compare);

    int t = vec[0].second - vec[0].first;
    int ans = (t % L == 0) ? t / L : t / L + 1;
    int cnt = ans;
    int bound_start = vec[0].first;
    int bound_end = vec[0].second;

    int tt;

    for (int i = 1; i < vec.size(); i++)
    {
        tt = bound_start + cnt * L - 1;
        if (vec[i].second <= tt)
            continue;
        else
        {
            // bound_end = 12 , tt == 13
            // 13 17
            if (vec[i].first > tt)
            {
                bound_start = vec[i].first;
                bound_end = vec[i].second;
                t = bound_end - bound_start;
                cnt = (t % L == 0) ? t / L : t / L + 1;
                ans += cnt;
            }
            // vec[i].first == 13, 17    tt == 13
            else
            {
                bound_start = tt + 1;
                bound_end = vec[i].second;
                t = bound_end - bound_start;
                cnt = (t % L == 0) ? t / L : t / L + 1;
                ans += cnt;
            }
        }
    }

    cout << ans << "\n";
}