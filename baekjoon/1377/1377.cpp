#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<char, pii> pii2;
#define MAX 987654321

vector<pii> vec; // value, idx

int N;

int main() {
  FIO;

  cin >> N;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    vec.push_back({input, i});
  }

  sort(vec.begin(), vec.end());

  int ans = -1;

  for (int i = N - 1; i >= 0; i--)
    ans = max(ans, vec[i].second - i + 1);

  cout << ans << "\n";
}