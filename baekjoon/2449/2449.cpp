#include <iostream>
using namespace std;
#include <vector>
#include <time.h>
#include <algorithm>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define MAX 654321

int N, K;

vector<int> vec;

int dp[222][222];

int main()
{
    FIO;

    cin >> N >> K;
    int bound = -1;
    // 중복되는 원소들은 한 묶음으로 취급하고 하나만 넣자.
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        if (bound != input)
        {
            bound = input;
            vec.push_back(input);
        }
        else
            continue;
    }

    for (int i = 1; i < vec.size(); i++)
        for (int j = 0; j < vec.size() - i; j++)
            dp[j][j + i] = MAX;

    for (int i = 1; i < vec.size(); i++)
        dp[i - 1][i] = 1;

    // dp[a][b];
    // vec.size() == 5 (1 2 3 2 1)

    for (int l = 2; l < vec.size(); l++) // b - a
    {
        for (int e = 0; e < vec.size() - l; e++) // a자리
        {
            if (vec[e] == vec[e + l])
            {
                if (e + 1 == e + l - 1)
                    dp[e][e + l] = 1;
                else
                    dp[e][e + l] = dp[e + 1][e + l - 1] + 1;

                for (int i = 1; i < l; i++)
                    dp[e][e + l] = min(dp[e][e + l], dp[e][e + i] + dp[e + i][e + l]);
            }
            else
                for (int i = 1; i < l; i++)
                    dp[e][e + l] = min(dp[e][e + l], dp[e][e + i] + dp[e + i][e + l]);
        }
    }

    cout << dp[0][vec.size() - 1] << "\n";
}