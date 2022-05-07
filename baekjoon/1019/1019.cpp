#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

typedef long long ll;

ll N;

ll arr[11];

void calc(ll input, ll r)
{
    while (input > 0)
    {
        arr[input % 10] += 1 * r;
        input /= 10;
    }
}

int main()
{
    FIO;

    cin >> N;

    ll a = 1;
    ll b = N;

    int c = 0;

    while (a <= b)
    {
        while (b % 10 != 9 && a <= b)
        {
            calc(b, pow(10, c));

            b--;
        }

        if (a > b)
            break;

        while (a % 10 != 0 && a <= b)
        {
            calc(a, pow(10, c));

            a++;
        }
        a /= 10;
        b /= 10;

        for (int i = 0; i <= 9; i++)
        {
            arr[i] += (b - a + 1) * pow(10, c);
        }

        c++;
    }

    for (int i = 0; i <= 9; i++)
        cout << arr[i] << " ";
    cout << "\n";
}