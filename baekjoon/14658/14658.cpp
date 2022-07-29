#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

vector<pair<int, int>> vec;

int N, M, L, K;

int max_count = -1;

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

int main() {
  FIO;
  cin >> N >> M >> L >> K;
  for (int i = 0; i < K; i++) {
    int y, x;
    cin >> x >> y;
    vec.push_back(make_pair(y, x));
  }

  sort(vec.begin(), vec.end(), compare);

  for (int i = 0; i < K; i++) {
    int count = 0;
    int y2 = (vec[i].first + L > M) ? M : vec[i].first + L;
    int y1 = y2 - L;

    while (y1 >= vec[i].first - L) {
      count = 0;
      for (int j = 0; j < K; j++) {
        if (vec[j].first >= y1 && vec[j].first <= y2 &&
            vec[j].second >= vec[i].second &&
            vec[j].second <= vec[i].second + L) {
          count++;
        }
      }

      max_count = max(max_count, count);
      y1--;
      y2--;
    }
  }

  cout << K - max_count << "\n";
}