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

int N;

pair<string, int> temp[20005];

pair<string, int> arr[20005];

int getPrefixLength(string a, string b) {
  int res;
  for (res = 0; (res < a.size() && res < b.size()) && (a[res] == b[res]); res++)
    ;
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
    temp[i] = arr[i];
  }

  sort(temp, temp + N);

  // unique(temp, temp + N);

  int _max = -1;
  int preLength = -1;
  pair<int, int> pre_t = {MAX, MAX};
  pair<int, int> ans;

  for (int i = 1; i < N; i++) {
    int l = getPrefixLength(temp[i - 1].first, temp[i].first);

    // 그 전 prefixLength 와 l이 다르다면
    if (l != preLength) {
      preLength = l;
      pre_t = {temp[i - 1].second, temp[i].second};
    }
    // 그 전 prefixLength 와 l이 같을 때
    // pre_t의 first는 second보다 무조건 작기 때문에 second만 비교해서 바꿔주는
    // 식으로 하자.
    else if (pre_t.second > temp[i].second) {
      pre_t.second = temp[i].second;
    }

    if (pre_t.first > pre_t.second)
      swap(pre_t.first, pre_t.second);

    if (_max < l || (_max == l && ans.first > pre_t.first)) {
      ans = pre_t;
      _max = l;
    }
  }
  cout << arr[ans.first].first << "\n" << arr[ans.second].first << "\n";
}
