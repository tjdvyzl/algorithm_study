#include <iostream>
using namespace std;
#include <string.h>
#include <vector>

int tc;

bool v[200005];

vector<pair<int, int>> vec;

int main() {
  cin >> tc;

  while (tc--) {
    vec.clear();
    memset(v, false, sizeof(v));
    int n, k;
    cin >> n >> k;

    for (int a = 1; a <= n; a++) {
      if (v[a])
        continue;
      // a를 기준으로 왼쪽
      for (int b = a - 1, cnt = 4; b >= 1 && cnt > 0; b--, cnt--) {
        if (v[b])
          continue;
        if ((a + k) * b % 4 == 0) {
          vec.push_back({a, b});
          v[a] = true;
          v[b] = true;
          break;
        }
      }
      // a를 기준으로 오른쪽
      for (int b = a + 1, cnt = 4; b <= n && cnt > 0; b++, cnt--) {
        if (v[b])
          continue;
        if ((a + k) * b % 4 == 0) {
          vec.push_back({a, b});
          v[a] = true;
          v[b] = true;
          break;
        }
      }
    }

    bool isalltrue = true;
    for (int i = 1; i <= n; i++) {
      if (!v[i]) {
        isalltrue = false;
        break;
      }
    }
    if (isalltrue) {
      cout << "YES\n";
      for (auto e : vec)
        cout << e.first << " " << e.second << "\n";
    } else
      cout << "NO\n";
  }
}