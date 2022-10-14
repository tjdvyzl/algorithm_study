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
#include <map>
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

bool input[100005];
bool bound[100005];

int ans = MAX;

// 바꾼 횟수, 현재 바꿀 idx, 전 string, 현재 string
void f(int cnt, int change_idx, bool cur[100005]) {
  if (change_idx == N) {
    if (bound[change_idx - 2] == cur[change_idx - 2] &&
        bound[change_idx - 1] == cur[change_idx - 1])
      ans = min(ans, cnt);
    return;
  }
  if (change_idx == 0) {
    // 현재 idx 전구를 바꾸지 않음
    f(cnt, change_idx + 1, cur);
    // 현재 idx 전구를 바꿈
    cur[0] = !cur[0];
    cur[1] = !cur[1];
    f(cnt + 1, change_idx + 1, cur);
    cur[0] = !cur[0];
    cur[1] = !cur[1];
  } else {
    // 현재 idx 전구를 바꾸지 않음
    if (cur[change_idx - 1] == bound[change_idx - 1])
      f(cnt, change_idx + 1, cur);

    // 현재 idx 전구를 바꿈
    else {
      cur[change_idx - 1] = !cur[change_idx - 1];
      cur[change_idx] = !cur[change_idx];
      cur[change_idx + 1] = !cur[change_idx + 1];
      f(cnt + 1, change_idx + 1, cur);
      cur[change_idx - 1] = !cur[change_idx - 1];
      cur[change_idx] = !cur[change_idx];
      cur[change_idx + 1] = !cur[change_idx + 1];
    }
  }
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int temp;
    scanf("%1d", &temp);
    input[i] = temp;
  }

  for (int i = 0; i < N; i++) {
    int temp;
    scanf("%1d", &temp);
    bound[i] = temp;
  }

  f(0, 0, input);

  if (ans == MAX)
    printf("-1\n");
  else
    printf("%d\n", ans);
}
