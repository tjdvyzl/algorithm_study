#include <iostream>
using namespace std;
#include <string.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 0x3f3f3f3f3f3f3f3f

typedef long long ll;

ll dp[222][222];

int N, M, K;

ll combi(int n, int r)
{
    r = (r > n - r) ? n - r : r;

    if (n == r || r == 0)
        return 1;

    if (r == 1)
        return n;

    if (dp[n][r] != -1)
        return dp[n][r];

    ll a = combi(n - 1, r - 1);
    ll b = combi(n - 1, r);

    if (a + b > 1000000000)
        return dp[n][r] = dp[n][n - r] = INF;

    return dp[n][r] = dp[n][n - r] = a + b;
}

void f(string sum, int a, int z, ll k)
{
    if (a == 0 || z == 0)
    {
        if (a == 0)
            for (int i = 0; i < z; i++)
                sum += "z";
        else
            for (int i = 0; i < a; i++)
                sum += "a";
        cout << sum << "\n";
        return;
    }

    ll r = combi(a + z - 1, a - 1);

    if (a > 0 && k <= r)
        f(sum + "a", a - 1, z, k);

    else if (z > 0)
        f(sum + "z", a, z - 1, k - r);
}

int main()
{
    FIO;

    memset(dp, -1, sizeof(dp));

    cin >> N >> M >> K;

    ll r = combi(N + M, M);

    if (r < K)
        cout << -1 << "\n";
    else
        f("", N, M, K);
}