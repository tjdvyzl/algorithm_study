#include <iostream>
using namespace std;
#include <cmath>
#include <string.h>
#include <vector>

typedef long long ll;

int tc;

ll x, y;

int main() {
  cin >> tc;
  while (tc--) {
    cin >> x >> y;
    y -= x, x = 0;
    ll j = 0;
    for (; (j + 1) * (j + 1) <= (y - 1) || (j + 1) * (j + 1) <= y; j++) {
    }
    ll sub = (y - 1) - (j * (j + 1) / 2);
    ll x1 = j * (j - 1) / 2;
    ll x2 = j * (j + 1) / 2 - 1;

    if (x1 > sub)
      cout << j + (j - 2) + 1 << "\n";
    else if (x1 <= sub && sub <= x2)
      cout << j + (j - 2) + 2 << "\n";
    else
      cout << j + (j - 2) + 3 << "\n";
  }
}