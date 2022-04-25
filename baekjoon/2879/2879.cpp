#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define MAX 987654321

int N;

int arr[1005];
int bound[1005];
int d[1005];

int ans = 0;

int main()
{
    FIO;

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < N; i++)
    {
        cin >> bound[i];
        d[i] = bound[i] - arr[i];
    }

    if (N == 1)
    {
        cout << abs(d[0]) << "\n";
    }

    int a = d[0] / abs(d[0]); // 부호가 같은지

    int b = d[0]; // 오름차순 or 내림차순 확인

    for (int i = 1; i < N; i++)
    {
        // 양수 오름차순
        if (d[i] >= 0)
        {
            // 부호가 다르다면
            if (a < 0)
            {
                a = -a;
                ans += abs(b);
                b = d[i];
            }
            else
            {
                // 오름차순이 깨졌다면
                if (b > d[i])
                    ans += abs(b) - abs(d[i]);

                b = abs(d[i]);
            }
        }

        // 음수 내림차순
        else
        {
            // 부호가 다르다면
            if (a > 0)
            {
                a = -a;
                ans += abs(b);
                b = d[i];
            }
            else
            {
                // 내림차순이 깨졌다면
                if (b < d[i])
                {
                    ans += abs(b) - abs(d[i]);
                }
                b = d[i];
            }
        }
    }

    ans += abs(b);

    cout << ans << "\n";
}