#include <iostream>
using namespace std;
#include <vector>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

/*
    Gi가 주어질 때 최대한 Gi의 값에 가까운 공항에 도킹시키자.
    예를 들어 4의 비행기가 온다면 1~4까지 4와 최대한 근접한 공항에 도킹을 시켜야되는데
    1~4까지 어떤 비행기가 도킹 되어있는지를 알아야 한다.
*/

int parent[100005]; // parent[idx]가 있다 가정하자. 1 ~ idx까지의 범위 내에 도킹 되어있는 비행기의 수를 저장

int cnt[100005];

int v[100005];

int arr[100005];

int G, P;

int ans = 0;

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;
    else if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    FIO;

    cin >> G >> P;

    for (int i = 1; i <= G; i++)
        parent[i] = i;

    for (int i = 0; i < P; i++)
    {
        int input;
        cin >> arr[i];
    }

    for (int i = 0; i < P; i++)
    {
        if (v[arr[i]] == 0)
        {
            v[arr[i]] = arr[i];
            ans++;
        }
        else
        {
            int t = find(arr[i]);

            while (t > 0 && v[t] != 0)
            {
                t = find(t - 1);
            }

            if (t > 0)
            {
                merge(t, arr[i]);
                v[t] = arr[i];
                ans++;
            }
            else
                break;
        }
    }

    cout << ans << "\n";
}