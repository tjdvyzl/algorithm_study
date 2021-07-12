#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

string c[101][101];
bool check[101][101];

string numToString(string a, string b) {
    ll sum = 0;
    string ret;
    while (a.size() || b.size() || sum) {
        if (a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        ret.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string combination(int n, int r) {
    if (r * 2 > n)
        r = n - r;

    if (r == 0)
    {
        check[n][r] = true;
        return "1";
    }
    else if (r == 1) {
        check[n][r] = true;
        return to_string(n);
    }
    if (check[n][r] == true)
        return c[n][r];
    else {
        check[n][r] = true;
        string first = combination(n - 1, r - 1);
        string second = combination(n - 1, r);
        c[n][r] = numToString(first,second);
        return c[n][r];
    }
}

// n C r = n-1 C r-1 + n-1 C r

int main() {
	int n, m;
	cin >> n >> m;

    cout << combination(n, m) << "\n";
}