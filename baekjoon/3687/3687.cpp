#include <iostream>
#include <type_traits>
using namespace std;
#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
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

string _max = "0";
string _min = "99999999999999999999999999999999999999999999999999";

int numbers[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string dp[105][2]; // 0은 min 1은 max

bool isBig(string a, string b) {
  if (a.length() == b.length())
    return (a > b);
  else
    return (a.length() > b.length());
}

void f(int input) {
  int l = 2;
  int r = input - 2;
  while (l <= r) {
    // 최솟값
    string temp_min = "";
    if (l == 6 && r == 6)
      temp_min = min(dp[l][0] + "0", dp[r][0] + "0");
    else if (l == 6)
      temp_min = min(dp[r][0] + "0", dp[l][0] + dp[r][0]);
    else if (r == 6)
      temp_min = min(dp[l][0] + "0", dp[r][0] + dp[l][0]);
    else
      temp_min = min(dp[r][0] + dp[l][0], dp[l][0] + dp[r][0]);

    if (isBig(_min, temp_min))
      _min = temp_min;

    // 최댓값
    string temp_max = max(dp[r][1] + dp[l][1], dp[l][1] + dp[r][1]);
    if (isBig(temp_max, _max))
      _max = temp_max;

    l++, r--;
  }
  dp[input][0] = _min, dp[input][1] = _max;
}

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  dp[2][0] = "1", dp[2][1] = "1";
  dp[3][0] = '7', dp[3][1] = '7';
  dp[4][0] = '4', dp[4][1] = "11";
  dp[5][0] = '2', dp[5][1] = "71";
  dp[6][0] = '6', dp[6][1] = "111";
  dp[7][0] = '8', dp[7][1] = "711";

  for (int i = 8; i <= 100; i++) {
    _max = "0";
    _min = "99999999999999999999999999999999999999999999999999";
    f(i);
  }

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    cout << dp[input][0] << " " << dp[input][1] << "\n";
  }
}
