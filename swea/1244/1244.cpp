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
#include <limits.h>
#include <map>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>

#define MAX LLONG_MAX
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

void swap(int temp[11], int a, int b) {
  int t = temp[a];
  temp[a] = temp[b];
  temp[b] = t;
}

vector<int> vec;
int temp[11];
string input;
int change_cnt;
int bound = 0;
int _max = 0;

void f(int idx, int cnt, int sum) {
  if (cnt > change_cnt)
    return;
  if (cnt != 0 && (change_cnt - cnt) % 2 == 0) {
    if (sum < _max)
      return;
    _max = max(_max, sum);
  }

  for (int i = idx; i < vec.size(); i++) {
    for (int j = i + 1; j < vec.size(); j++) {
      int m_sum = temp[i] * (int)pow(10, vec.size() - i - 1) +
                  temp[j] * (int)pow(10, vec.size() - j - 1);
      int p_sum = temp[j] * (int)pow(10, vec.size() - i - 1) +
                  temp[i] * (int)pow(10, vec.size() - j - 1);
      int temp_sum = sum - m_sum + p_sum;

      swap(temp, i, j);
      f(i, cnt + 1, temp_sum);
      swap(temp, i, j);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int testcase;
  cin >> testcase;
  for (int tc = 1; tc <= testcase; tc++) {
    vec.clear();
    _max = 0;
    bound = 0;
    cin >> input >> change_cnt;
    for (int i = 1; i <= input.size(); i++) {
      temp[vec.size()] = (input[i - 1] - '0');
      bound +=
          (input[i - 1] - '0') * (int)pow(10, input.size() - vec.size() - 1);
      vec.push_back((input[i - 1] - '0'));
    }
    f(0, 0, bound);
    if (_max == 0)
      _max = bound;
    cout << "#" << tc << " " << _max << "\n";
  }
}