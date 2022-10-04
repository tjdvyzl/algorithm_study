#include <iostream>
#include <type_traits>
using namespace std;
#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
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

int N, H;

int cnt_up[500005];
int cnt_down[500005];

int sum_up[500005];
int sum_down[500005];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> H;
  for (int i = 1; i <= N; i++) {
    int input;
    cin >> input;
    //  석순
    if (i % 2 == 1)
      cnt_down[input]++;
    else
      cnt_up[input]++;
  }

  // 종유석 합
  int s = 0;
  for (int i = 1; i <= H; i++) {
    s += cnt_up[i];
    sum_up[i] = s;
  }

  // 석순 합
  s = 0;
  for (int i = 1; i <= H; i++) {
    s += cnt_down[i];
    sum_down[i] = s;
  }

  int _min = MAX;
  int c = 1;

  for (int h = 1; h <= H; h++) {
    int su = sum_up[H] - sum_up[h - 1];
    int sd = sum_down[H] - sum_down[H - h];
    int ss = su + sd; // 석순과 종유석 총합 -> 해당 높이로 갔을 때 파괴하는
                      // 장애물의 총 개수
    if (ss == _min) {
      c++;
    } else if (ss < _min) {
      _min = ss;
      c = 1;
    }
  }
  cout << _min << " " << c << "\n";
}