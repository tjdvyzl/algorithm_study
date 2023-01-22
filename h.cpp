#include <iostream>
using namespace std;
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <limits.h>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0)
#define MAX 2000000005

typedef long long int ll;

pair<int, ll> tree[2000005];

int arr[500005];

int N;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = {start, 1};
    return;
  }
  init(node * 2, start, (start + end) / 2);
  init(node * 2 + 1, (start + end) / 2 + 1, end);

  int tmp = tree[node * 2].second + tree[node * 2 + 1].second;

  int l = tree[node * 2].first;
  int r = tree[node * 2 + 1].first;

  if (arr[l] > arr[r])
    tree[node] = {l, tmp};
  else if (arr[l] < arr[r])
    tree[node] = {r, tmp};
  else
    tree[node] = {max(l, r), tmp};
}

void update(int node, int start, int end, int idx) {
  if (idx < start || idx > end)
    return;

  if (start == end) {
    tree[node].second--;
    return;
  }

  update(node * 2, start, (start + end) / 2, idx);
  update(node * 2 + 1, (start + end) / 2 + 1, end, idx);

  ll tmp = tree[node * 2].second + tree[node * 2 + 1].second;

  int l = (tree[node * 2].first == -1) ? 0 : tree[node * 2].first;
  int r = (tree[node * 2 + 1].first == -1) ? 0 : tree[node * 2 + 1].first;

  if (arr[l] > arr[r])
    tree[node] = {l, tmp};
  else if (arr[l] < arr[r])
    tree[node] = {r, tmp};
  else
    tree[node] = {max(l, r), tmp};
}

ll getValidCnt(int node, int start, int end, int left, int right) {
  if (end < left || start > right)
    return 0;

  if (start == end)
    return tree[node].second;

  if (left <= start && end <= right)
    return tree[node].second;

  ll lgmi = getValidCnt(node * 2, start, (start + end) / 2, left, right);
  ll rgmi = getValidCnt(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

  return lgmi + rgmi;
}

void show() {
  for (int i = 1; i <= 2 * N; i++) {
    cout << i << " --> " << tree[i].first << ", " << tree[i].second << "\n";
  }
  cout << "\n";
}

int main() {
  FIO;
  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> arr[i];

  init(1, 1, N);

  ll ans = 0;

  for (int i = 0; i < N; i++) {
    int gmi = tree[1].first;
    arr[gmi] = -1;
    update(1, 1, N, gmi);

    // cout << gmi << "!\n";
    // show();

    ll t = getValidCnt(1, 1, N, gmi + 1, N);

    ans += t;
  }

  cout << ans << "\n";
}
