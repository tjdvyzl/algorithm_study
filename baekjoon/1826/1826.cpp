#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>
#include <vector>

class node {
public:
  int current_pos;
  int current_oil;
  int cnt;
  int idx;
  node() { cnt = 0; }
  node(int idx, int current_pos, int current_oil, int cnt)
      : idx(idx), current_pos(current_pos), current_oil(current_oil), cnt(cnt) {
  }
};

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first)
    return a.second > b.second;

  else
    return a.first < b.first;
}

int N;

vector<pair<int, int>> vec; // 거리, 주유량

int ans = 1000005;

int arr[1000005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b; // 성경이의 시작 위치에서 주유소 까지의 거리, 그 주유소에서 채울
              // 수 있는 연료의 양
    cin >> a >> b;
    vec.push_back(make_pair(a, b));
  }
  int L, P; // 성경이의 위치에서 마을까지의 거리, 트럭에 원래 있던 연료의 양
  cin >> L >> P;

  if (P >= L) {
    cout << 0 << "\n";
    return 0;
  }

  // sort 다음 주유소 까지의 거리가 짧고, 주유할 수 있는 기름의 양이 많음
  sort(vec.begin(), vec.end(), compare);

  arr[0] = P;

  for (int i = 0; i < vec.size(); i++) { // i == 2
    int dis = vec[i].first;
    int oil = vec[i].second;
    for (int j = i + 1; j >= 0; j--) { // 주유소에 들린 횟수
      if (arr[j - 1] - dis < 0)
        continue;

      int sub = arr[j - 1] - dis;
      int total_oil = sub + oil;

      arr[j] = max(arr[j], dis + total_oil);
    }
  }

  for (int i = 0; i <= N; i++) {
    if (arr[i] >= L) {
      ans = i;
      break;
    }
  }

  ans = (ans == 1000005) ? -1 : ans;
  cout << ans << "\n";
}