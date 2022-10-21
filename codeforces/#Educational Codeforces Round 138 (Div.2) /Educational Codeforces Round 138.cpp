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

#define MAX 1000000005
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

int tc;

ll a[200005];
ll b[200005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;

  while (tc--) {
    ll ans = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans += a[i];
    }

    stack<ll> st;

    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (st.empty())
        st.push(b[i]);
      else {
        while (!st.empty() && st.top() <= b[i]) {
          ans += st.top();
          st.pop();
        }
        st.push(b[i]);
      }
    }
    while (!st.empty()) {
      ll t = st.top();
      st.pop();
      if (st.empty())
        break;
      ans += t;
    }

    cout << ans << "\n";
  }
}
