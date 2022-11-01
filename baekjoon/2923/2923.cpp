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

#define MAX INT_MAX
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

int N;

int cnt_a[105];
int cnt_b[105];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    cnt_a[a]++;
    cnt_b[b]++;
    int temp_a[105], temp_b[105];
    for (int i = 1; i <= 100; i++)
      temp_a[i] = cnt_a[i], temp_b[i] = cnt_b[i];
    int _max = -1;
    while (1) {
      int left = 0;
      int right = 100;
      while (left <= 100 && temp_a[left] == 0) {
        left++;
      }
      while (right >= 1 && temp_b[right] == 0) {
        right--;
      }
      if (left == 101 || right == 0)
        break;
      _max = max(_max, left + right);
      int t = min(temp_a[left], temp_b[right]);
      temp_a[left] -= t;
      temp_b[right] -= t;
    }
    cout << _max << "\n";
  }
}