#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int ans = 1;

void f(int s, int e, string input)
{
    if (s >= e)
        return;

    int l = s;
    int r = e;
    while (l < r)
    {
        if (input[l++] == input[r--])
        {
            ans = 0;
            return;
        }
    }
    int m = (s + e) / 2;
    f(s, m - 1, input);
    f(m + 1, e, input);
}

int main()
{
    FIO;

    int T;
    cin >> T;
    while (T--)
    {
        ans = 1;
        string input;
        cin >> input;
        f(0, input.size() - 1, input);
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}