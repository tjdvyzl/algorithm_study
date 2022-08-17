#include <iostream>
using namespace std;
#include <algorithm>
#include <deque>
#include <string.h>
#include <vector>

class node {
public:
  int idx;
  int i;
  int k;
  node() {}
  node(int idx, int i, int k) : idx(idx), i(i), k(k) {}
};

bool compare(node a, node b) { return a.k < b.k; }

int tc;

int arr[100005];

int wincnt[100005];

deque<int> dq;

vector<node> vec;

int ans[100005];

int main() {
  cin >> tc;

  while (tc--) {

    int n, q; // 토너먼트 참가자의 수, 질문의 수
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
      cin >> arr[i];

    dq.clear();
    vec.clear();

    for (int i = 1; i <= n; i++) {
      wincnt[i] = 0;
      dq.push_back(arr[i]);
    }

    for (int idx = 0; idx < q; idx++) {
      int i, k;
      cin >> i >> k;
      vec.push_back(node(idx, i, k));
    }

    sort(vec.begin(), vec.end(), compare);

    int bound = 0;

    for (int i = 0; i < vec.size(); i++) {
      int t = vec[i].k - bound;
      while (t && dq.front() != n) {
        int f = dq.front();
        dq.pop_front();
        int s = dq.front();
        dq.pop_front();
        if (f > s) {
          wincnt[f]++;
          dq.push_front(f);
          dq.push_back(s);
        } else {
          wincnt[s]++;
          dq.push_front(s);
          dq.push_back(f);
        }
        t--;
        bound++;
      }

      ans[vec[i].idx] = (arr[vec[i].i] == n) ? wincnt[arr[vec[i].i]] + t
                                             : wincnt[arr[vec[i].i]];
    }

    for (int i = 0; i < q; i++) {
      cout << ans[i] << "\n";
    }
  }
}