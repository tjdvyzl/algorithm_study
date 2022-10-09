#include <iostream>
#include <type_traits>
using namespace std;
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
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

int N;
bool v[500005];

stack<int> st;

int ans = 0;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout.tie(0);

  cin >> N;

  while (N--) {
    int x, y;
    cin >> x >> y;
    while (!st.empty() && y <= st.top()) {
      if (y < st.top())
        ans++;
      st.pop();
    }
    if (y > 0)
      st.push(y);
  }

  while (!st.empty()) {
    ans++;
    st.pop();
  }

  cout << ans << "\n";
}
