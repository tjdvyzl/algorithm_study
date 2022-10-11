#include <ctime>
#include <iostream>
#include <type_traits>
using namespace std;
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>

#define MAX 987654321
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

ll a[100005];

int tc;

int gcd(ll x, ll y) {
  ll temp;
  if (x < y) {
    temp = x;
    x = y;
    y = temp;
  }
  ll rest;
  while (y != 0) {
    rest = x % y;
    x = y;
    y = rest;
  }
  return x;
}

int main() {
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    bool isYes = true;

    for (int i = 1; i < n; i++) {
      if (i == n - 1)
        break;
      ll gcd_left = gcd(a[i - 1], a[i]);
      ll gcd_right = gcd(a[i], a[i + 1]);
      ll _gcd = gcd((a[i - 1] / gcd_left) * (a[i] / gcd_left) * gcd_left,
                    (a[i] / gcd_right) * (a[i + 1] / gcd_right) * gcd_right);
      if (_gcd > a[i]) {
        isYes = false;
        break;
      }
    }

    if (isYes)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}