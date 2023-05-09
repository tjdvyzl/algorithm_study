#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0);
#define MAX 1000000005
typedef pair<int, int> pii;
typedef pair<long long, long long> pllll;
typedef long long ll;

int N, S;

vector<ll> vec;

ll cnt_plus[4000005];
ll cnt_minus[4000005];

vector<ll> dp;

int main() {
  FIO;

  cin >> N >> S;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    vec.push_back(input);
  }

  if (vec[0] < 0)
    cnt_minus[-vec[0]]++;
  else
    cnt_plus[vec[0]]++;

  dp.push_back(vec[0]);

  vector<pllll> tmp_vec;

  for (int i = 1; i < N; i++) {
    tmp_vec.clear();
    for (auto e : dp) {
      ll tmp_cnt = (e < 0) ? cnt_minus[-e] : cnt_plus[e];
      ll t = vec[i] + e;
      tmp_vec.push_back({t, tmp_cnt});
    }

    for (auto e : tmp_vec) {
      if (e.first < 0) {
        if (cnt_minus[-e.first] == 0)
          dp.push_back(e.first);
        cnt_minus[-e.first] += e.second + (e.second == 0);
      } else {
        if (cnt_plus[e.first] == 0)
          dp.push_back(e.first);
        cnt_plus[e.first] += e.second + (e.second == 0);
      }
    }

    if (vec[i] < 0) {
      if (cnt_minus[-vec[i]] == 0)
        dp.push_back(vec[i]);
      cnt_minus[-vec[i]]++;
    } else {
      if (cnt_plus[vec[i]] == 0)
        dp.push_back(vec[i]);
      cnt_plus[vec[i]]++;
    }
  }

  if (S < 0)
    cout << cnt_minus[-S] << "\n";
  else
    cout << cnt_plus[S] << "\n";
}
