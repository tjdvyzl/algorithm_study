#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N;

vector<pair<int, int>> vec;

int v[1000005];

int arr[1000005];

int lower_bound(int key)
{
    int l = 0, r = vec.size(), mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (vec[mid].second < key)
        {
            l = mid + 1;
        }
        else
            r = mid;
    }
    return r;
}

int main()
{
    FIO;

    cin >> N;

    memset(v, -1, sizeof(v));

    int _max = -1;
    int max_idx = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];

        if (vec.empty())
            vec.push_back({i, arr[i]});

        else
        {
            int t = lower_bound(arr[i]);
            if (t >= vec.size())
            {
                v[i] = vec.back().first;
                vec.push_back({i, arr[i]});
                _max = arr[i];
                max_idx = i;
            }
            else
            {
                if (v[vec[t].first] != -1)
                    v[i] = vec[t - 1].first;
                else
                    v[i] = -1;
                vec[t] = {i, arr[i]};
            }
        }
    }

    vector<int> ans;

    int t = max_idx;
    while (t != -1)
    {
        ans.push_back(arr[t]);
        t = v[t];
    }

    cout << ans.size() << "\n";

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << "\n";
}