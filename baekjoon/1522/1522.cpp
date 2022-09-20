#include <iostream>
using namespace std;

string s;

int a_size = 0;
int b_size = 0;

int ans = 987654321;

int main() {
  cin >> s;

  for (auto e : s) {
    if (e == 'a')
      a_size++;
    else
      b_size++;
  }

  int a_cnt = 0;
  int b_cnt = 0;

  int x1 = 0, x2 = a_size - 1;

  for (int i = x1; i <= x2; i++) {
    if (s[i] == 'a')
      a_cnt++;
    else
      b_cnt++;
  }

  while (x1 < s.size()) {
    ans = (ans > b_cnt) ? b_cnt : ans;
    if (s[x1] == 'a')
      a_cnt--;
    else
      b_cnt--;

    x1++, x2++;

    if (x2 >= s.size())
      x2 = 0;

    if (s[x2] == 'a')
      a_cnt++;
    else
      b_cnt++;
  }

  cout << ans << "\n";
}