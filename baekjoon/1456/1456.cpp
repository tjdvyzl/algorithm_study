#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

typedef long long ll;

ll a, b;

vector<bool> era(10000011);

void setEra()
{
    era[1] = true;
    for (ll i = 2; i * i <= b; i++)
    {
        if (era[i])
            continue;
        for (ll j = i * i; j <= 10000010; j += i)
            era[j] = true;
    }
}

int main()
{

    cin >> a >> b;

    setEra();

    ll ans = 0;

    for (ll i = 2; i * i <= b; i++)
    {
        // i가 소수 일 때
        if (!era[i])
        {
            for (ll j = i * i; j <= b; j *= i)
            {
                if (j >= a && j <= b)
                    ans++;
                if ((j > ((long long)pow(2, 64) - 1) / i))
                    break;
            }
        }
    }

    cout << ans << "\n";
}