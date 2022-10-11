# 문제주소

<br><br>

# 문제 해석

<pre>

</pre>

<br><br>

# 문제 접근 방법

<pre>
dp로 해결했나..? 그냥 무지성 구현같기도하고 
dp[i] --> [(1 ~ i-1), i] 집합의 원소 개수 
        1 2 3 4 3 4 1 2를 봐보자

              4   4
            3 3 3 3
          2 2 2 2 2   2
        1 1 1 1 1 1 1 1
1) dp : 0 
2) dp :   1
3) dp :     2
4) dp :       3
5) dp :         2
6) dp :           3
7) dp :             0
8) dp :               1
일단 DP[i-1]의 값과 현재 입력된 값을 비교해야한다. 
입력되는 값은 중요하지않다. 어차피 Ai가 얼마나 크든 Ai-1의 값이 1이라면 결국 집합은 1 이외에는 존재하지 않기 때문이다.
우리가 여기서 봐야될 것은 그 전 원소까지 몇 개의 [(1 ~ i-2), i-1]집합의 원소 개수가 존재했느냐 이다. (이 값을 K라고 하자)
그래서 K + 1과 Ai의 값 중 작은 값을 ans에 더해주면 된다.

1번 과정에서 보면 [1,1]이 존재한다. dp[1] = 1
2번 과정에서 보면 [1,2] [2,2]이 존재한다. dp[2] = 2
3번 과정에서 보면 [1,3] [2,3] [3,3]이 존재한다. dp[3] = 3
4번 과정에서 보면 [1,4] [2,4] [3,4] [4,4]이 존재한다. dp[4] = 4
5번 과정에서 보면 [3,5] [4,5] [5,5]이 존재한다.  dp[5] = 3
    ㄴ 그 전 idx까진 [(1 ~ 3), 4]의 원소개수가 4개가 존재했지만
    ㄴ 5 idx에서 입력된 값이 3으로 K + 1보다 작기때문에 dp[5] = min(dp[i-1] + 1, Ai) = 3이다.



</pre>

<br><br>

# 착각했던 점

<p>

</p>

<pre>
<code>
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

int tc;

int arr[200005];

int dp[200005];

int main() {
  cin >> tc;

  while (tc--) {
    ll ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      int _max = min(dp[i - 1] + 1, arr[i]);
      ans += _max;
      dp[i] = _max;
    }

    cout << ans << "\n";
  }
}
</code>

</pre>

<br><br>

<p>

</p>
