#include <iostream>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int arr[100005];

bool v[100005];

long long ans = 0;

int main()
{
    FIO;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int l = 0, r = 1;

    v[arr[l]] = true;

    while (l < N)
    {
        if (v[arr[r]])
        {
            ans += (r - l) - 1;
            v[arr[l]] = false;
            l++;
            continue;
        }

        v[arr[r]] = true;

        r++;

        if (r >= N)
            r = N;
    }
    cout << ans + N << "\n";
}