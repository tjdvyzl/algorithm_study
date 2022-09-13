#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <vector>

#define MAX 987654321
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

int N;

pair<int, int> arr[100005];

bool compare(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

ll sum[100005];

int main() {
  FIO;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr, arr + N, compare);

  sum[0] = arr[0].second;

  for (int i = 1; i < N; i++) {
    sum[i] = arr[i].second + sum[i - 1];
  }

  int ans = MAX;

  int l = 0, r = N - 1;
  while (l <= r) {
    int mid = (l + r) / 2;

    //왼쪽 영역 사람들의 수
    ll leftArea = sum[mid];
    // 오른쪽 영역 사람들의 수
    ll rightArea = sum[N - 1] - sum[mid];

    if (leftArea >= rightArea) {
      r = mid - 1;
      ans = min(ans, arr[mid].first);
    } else
      l = mid + 1;
  }

  cout << ans << "\n";
}