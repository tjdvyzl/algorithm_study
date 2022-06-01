#include <iostream>
using namespace std;
#include <vector>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int arr[1000005];

// dp[n] --> n 번호 까지 연속된 수열의 개수
int dp[1000005];

int N;

int _max = -1;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];

        dp[arr[i]] = dp[arr[i] - 1] + 1;

        _max = (_max < dp[arr[i]]) ? dp[arr[i]] : _max;
    }

    cout << N - _max << "\n";
}