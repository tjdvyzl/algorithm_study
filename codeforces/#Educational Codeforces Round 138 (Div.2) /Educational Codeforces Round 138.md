# 문제주소

https://codeforces.com/contest/1749/problem/B
<br><br>

# 문제 해석

<pre>
2 6 7 3  --> a배열
3 6 0 5  --> b배열
0 1 2 3  --> idx
idx번째 몬스터를 죽이면 a[idx]초 만큼 걸리며,
(idx > 0) a[idx-1] += b[idx]
(idx < n - 1) a[idx + 1] += b[idx] 와 같이 사이드가 존재한다면 사이드 인덱스의 몬스터 체력이 b[idx]만큼 증가한다.
모든 몬스터를 죽이는데에 최소 시간을 구하라는 문제다.
</pre>

<br><br>

# 문제 접근 방법

<pre>
그리디 + 스택으로 해결했다.
일단 문제 조건을 잘 이해해보면 가장 큰 수를 제외하고 모든 b[i]값을 더해야한다. 
물론, 사이드가 존재한다면 사이드의 개수만큼 더 더해줘야한다.
즉, 최소 시간을 구하기 위해선 가장 자리 몬스터를 공략해야한다.

내가 세운 조건은 다음과 같다.
내림차순이면 stack에 그때그때 b[i]값을 담아준다. 이때 값이 같으면 안된다.
담는 과정에서 st.top()보다 크거나 같은 값이 존재한다면 
stack이 빌 때 까지 st의 top값을 더해준다. 
이 과정을 예시로 설명해보겠다. 
4 3 2 1 2 이런식의 b배열이 존재한다고 가정하자.
이때 연산 과정은 이렇다.
1 + 2  --> 4 3 2
2 + 3 --> 4
sum : 8
이렇게 되면 사이드 몬스터부터 잡으면서 왼쪽과 오른쪽 중 더 작은 값을 처치할 수 있다.
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

#define MAX 1000000005
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

int tc;

ll a[200005];
ll b[200005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;

  while (tc--) {
    ll ans = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans += a[i];
    }

    stack<ll> st;

    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (st.empty())
        st.push(b[i]);
      else {
        while (!st.empty() && st.top() <= b[i]) {
          ans += st.top();
          st.pop();
        }
        st.push(b[i]);
      }
    }
    while (!st.empty()) {
      ll t = st.top();
      st.pop();
      if (st.empty())
        break;
      ans += t;
    }

    cout << ans << "\n";
  }
}


</code>

</pre>

<br><br>

<p>

</p>
