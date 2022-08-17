# 문제주소

https://codeforces.com/contest/1719/problem/B

<br><br>

# 문제 해석

<pre>
테스트마다 n과 k가 주어진다.
여기서 (a + k) * b % 4 == 0인지 아닌지 판별하고 4로 (a + k) * b가 4로 나누어진다면 모든 정수 쌍을 출력해야한다.
여기서 a b는 (1 <= a, b <= n (a != b))이다.
</pre>

<br><br>

# 문제 접근 방법

<pre>
예를 들어보자. k가 짝수든 홀수든 신경쓸 필요가 없다. 일단은 풀이 이해를 위해 케이스를 분류해본다.

a가 7이라 가정하자. 

1) k가 만약 짝수라면 a+k는 홀수다. 
즉, 홀수 * b 꼴이므로 b는 무조건 (짝수면서 4의 배수)여야한다.

2) k가 만약 홀수라면 a+k는 짝수다.
즉, 짝수 * b 꼴이므로 b는 (짝수면 무조건 성립하고) 홀수여도 ((a + k) * b가 4로 나누어지는지만 성립하는 값)이면 된다.

위 조건들을 모두 만족하는 b는 [a-5, a-1], [a+1,a+5] 범위 안에 무조건 존재한다.
그래서 a의 값인 1 ~ n 을 탐색하는 과정에서 각 정점마다 위 범위를 조사해서 성립하는 쌍을 방문처리 해주어 중복되는 경우를 배제하면서
벡터에 담으면 된다. 

마지막 부분엔 1~n까지 모두 방문이 되었는지 확인줌으로써 1~n까지 모든 수를 사용했는지 여부를 판단한다.



</pre>

<br><br>

# 착각했던 점

<p>
문제 중간부분에 1~n까지 모든 수를 취한다고 나와있는데 이 부분을 안읽고 넘어가서 헤맸다..
심지어 O(n^2)으로 모든 경우를 출력했는데도 틀렸다고 나오길래 와.. 진짜 답없다 싶었는데 위 조건을 안걸어줘서 틀린거였다..
그리고 시간초과가 났는데 a의 값을 1~n까지 탐색하면서 b의 값도 똑같이 1~n까지 탐색해줄 필요가 없었다.
</p>

<pre>
<code>
#include < iostream >
using namespace std;
#include < string.h >
#include < vector >

int tc;

bool v[200005];

vector< pair< int, int >> vec;

int main() {
  cin >> tc;

  while (tc--) {
    vec.clear();
    memset(v, false, sizeof(v));
    int n, k;
    cin >> n >> k;

    for (int a = 1; a <= n; a++) {
      if (v[a])
        continue;
      // a를 기준으로 왼쪽
      for (int b = a - 1, cnt = 4; b >= 1 && cnt > 0; b--, cnt--) {
        if (v[b])
          continue;
        if ((a + k) * b % 4 == 0) {
          vec.push_back({a, b});
          v[a] = true;
          v[b] = true;
          break;
        }
      }
      // a를 기준으로 오른쪽
      for (int b = a + 1, cnt = 4; b <= n && cnt > 0; b++, cnt--) {
        if (v[b])
          continue;
        if ((a + k) * b % 4 == 0) {
          vec.push_back({a, b});
          v[a] = true;
          v[b] = true;
          break;
        }
      }
    }

    bool isalltrue = true;
    for (int i = 1; i <= n; i++) {
      if (!v[i]) {
        isalltrue = false;
        break;
      }
    }
    if (isalltrue) {
      cout << "YES\n";
      for (auto e : vec)
        cout << e.first << " " << e.second << "\n";
    } else
      cout << "NO\n";
  }
}
</code>

</pre>

<br><br>

<p>

</p>
