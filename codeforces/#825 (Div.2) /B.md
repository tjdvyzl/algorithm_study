# 문제주소

https://codeforces.com/contest/1736/problem/B
<br><br>

# 문제 해석

<pre>
n 개의 a배열이 주어진다.
그리고 가상의 n+1 개의 b배열이 있다고 가정하자.
모든 i에 대해서 a[i] = gcd(b[i], b[i+1])가 가능한 b가 존재하는지 판별하는 문제다.
</pre>

<br><br>

# 문제 접근 방법

<pre>
수학으로 접근했다. 
Bi를 구성하는데에 Ai-1이 영향을 끼치므로 해당 i 인덱스와 i-1 인덱스의 관계를 이해해야한다.

a -> 4 2 k
b -> a b c d
1. a는 4의 배수여야한다.
2. b는 2의 배수면서 4의 배수여야한다. --> (4 / gcd(4,2)) * (2 / gcd(4,2)) * gcd(4,2) * x == t
3. c는 2의 배수면서 k의 배수여야한다. --> (2 / gcd(2,k)) * (k / gcd(2,k)) * gcd(2,k) * x == p
    ㄴ gcd(t,p) * x == 2여야한다.
4. d는 k의 배수여야한다.
    ㄴ d를 결정할 때에는 이미 i가 n-1이므로 고려할 필요 없다.


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

ll a[100005];

int tc;

int gcd(ll x, ll y) {
  ll temp;
  if (x < y) {
    temp = x;
    x = y;
    y = temp;
  }
  ll rest;
  while (y != 0) {
    rest = x % y;
    x = y;
    y = rest;
  }
  return x;
}

int main() {
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    bool isYes = true;

    for (int i = 1; i < n; i++) {
      if (i == n - 1)
        break;
      ll gcd_left = gcd(a[i - 1], a[i]);
      ll gcd_right = gcd(a[i], a[i + 1]);
      ll _gcd = gcd((a[i - 1] / gcd_left) * (a[i] / gcd_left) * gcd_left,
                    (a[i] / gcd_right) * (a[i + 1] / gcd_right) * gcd_right);
      if (_gcd > a[i]) {
        isYes = false;
        break;
      }
    }

    if (isYes)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
</code>

</pre>

<br><br>

<p>

</p>
