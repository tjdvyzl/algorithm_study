#include <iostream>
#include <type_traits>
using namespace std;
#include <algorithm>
#include <bitset>
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
// 124          //1234
bool isAllHave(string input, string temp) {
  // input안에 temp가 전부 다 있는지 확인
  if (input.size() > temp.size())
    return false;
  int input_pos = 0;
  for (int i = 0; i < temp.size(); i++) {
    if (input[input_pos] == temp[i])
      input_pos++;
  }
  if (input_pos == input.size())
    return true;
  return false;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout.tie(0);

  string input;
  cin >> input;

  string temp = "";

  for (int i = 1;; i++) {
    temp += to_string(i);
    if (isAllHave(input, temp)) {
      cout << i << "\n";
      break;
    }
  }
}
