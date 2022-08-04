#include <exception>
#include <iostream>
using namespace std;
#include <algorithm>
#include <cstring>
#include <queue>
#include <string.h>
#include <string>
#include <vector>

class node {
public:
  int idx;
  int src;
  int dst;
  node(int idx, int src, int dst) : idx(idx), src(src), dst(dst) {}
  node() {}
};

vector<pair<int, string>> vec; // 몇번째로 받은 string인지
vector<node> area;
vector<node> ans;

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first < b.first;
  } else {
    return a.second > b.second;
  }
}

bool compare2(node a, node b) {
  if (a.src != b.src) {
    return a.src < b.src;
  } else {
    return a.dst > b.dst;
  }
}

int main() {

  int tc;
  cin >> tc;
  while (tc--) {

    vec.clear();
    area.clear();
    ans.clear();

    string input;
    cin >> input;

    int n;
    cin >> n;

    // 머리 문자만 따서 vec[a~z]에 저장하자.
    for (int i = 0; i < n; i++) {
      string temp;
      cin >> temp;
      vec.push_back(make_pair(i, temp));
    }

    for (int i = 0; i < input.length(); i++) {
      for (int j = 0; j < vec.size(); j++) {
        if (input[i] == vec[j].second[0]) {

          string sub = input.substr(i, vec[j].second.length());

          if (sub == vec[j].second)
            area.push_back(
                node(vec[j].first, i, i + vec[j].second.length() - 1));
        }
      }
    }

    // cout << input << " --> ";
    // for (auto e : area)
    //   cout << e.idx << ", " << e.src << ", " << e.dst << "\n";

    // cout << "\n\n";

    if (area.empty()) {
      cout << -1 << "\n";
      continue;
    }

    sort(area.begin(), area.end(), compare2);

    int src = area[0].src, dst = area[0].dst;

    ans.push_back(node(area[0].idx, src, dst));

    for (int i = 0; i < area.size() - 1; i++) {
      int temp_src = src, temp_dst = dst;
      bool isUpdate = false;
      int updateIdx = -1;
      for (int j = i + 1; j < area.size(); j++) {
        int s = area[j].src;
        int d = area[j].dst;
        if (d <= dst)
          continue;
        if (s >= src && s <= dst + 1) {
          if (d > temp_dst) {
            isUpdate = true;
            updateIdx = area[j].idx;
            temp_src = s;
            temp_dst = d;
          }
        }
      }
      if (isUpdate) {
        ans.push_back(node(updateIdx, temp_src, temp_dst));
        dst = temp_dst;
      }
    }

    if (src > 0 || dst < input.length() - 1) {
      cout << -1 << "\n";
      continue;
    }

    cout << ans.size() << "\n";
    for (auto e : ans)
      cout << e.idx + 1 << " " << e.src + 1 << "\n";
  }
}