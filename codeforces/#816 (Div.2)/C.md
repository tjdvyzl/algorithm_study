# 문제주소

https://codeforces.com/contest/1715/problem/C

<br><br>

# 문제 해석

<pre>
배열이 주어진다. 배열의 연속하는 수가 존재한다면 그 수들을 하나의 집합으로 생각하자.
그렇게 해서 해당 idx까지의 집합의 개수가 그 수의 값이 될 것이다. 
문제에서 m개의 i, x가 주어진다. arr[i] = x를 할당한 후, g(l,r)의 합을 구하면 된다.
ex) g(1,1) == arr[1], g(1,2) == arr[1] + arr[2] ... g(1,5) = arr[1] + arr[2] + ... + arr[5];
배열의 길이가 5라면 l[1,5]r[1,5]g(l,r)을 구하면 된다.
</pre>

<br><br>

# 문제 접근 방법

<pre>
1 2 3 4 5 -> 1 2 2 4 5 의 예를 들어보자. arr[3] = 2
1 2 3 4 5 의 경우 각 인덱스에 해당하는 값은 1 2 3 4 5 가 될 것이고, 
1 2 2 4 5 의 경우 각 인덱스에 해당하는 값은 1 2 2 3 4 가 될 것이다.
여기서 주요하게 봐야될 점은 배열의 값이 하나 바뀜으로써 이 배열에 얼마만큼의 영향을 주는지이다.
1 2 3 4 5
1 -> arr[1] + arr[2] + arr[3] + arr[4] + arr[5] == 1 + 2 + (3 + 4 + 5) ==  15
2 -> arr[2] + arr[3] + arr[4] + arr[5] == 1 + (2 + 3 + 4) == 10
3 -> arr[3] + arr[4] + arr[5]  == 1 + 2 + 3 == 6
4 -> arr[4] + arr[5] == 1 + 2 == 3
5 -> arr[5] == 1
sum == 35  l[1,5]r[1,5]g(l,r) == 35가 된다.

1 2 2 4 5의 경우를 봐보자
1 -> arr[1] + arr[2] + arr[3] + arr[4] + arr[5] == 1 + 2 + (2 + 3 + 4) == 12
2 -> arr[2] + arr[3] + arr[4] + arr[5] == 1 + (1 + 2 + 3) == 7
3 -> arr[3] + arr[4] + arr[5] == 1 + 2 + 3 == 6
4 -> arr[4] + arr[5] == 1 + 2 == 3
5 -> arr[5] == 1

i == 3, x == 2일 때 배열에 끼친 영향을 보자. 
첫번째와 두번째 케이스를 비교해보면 g(1~)을 구할 때 3 + 4 + 5 --> 2 + 3 + 4로 되었고
g(2~)을 구할 때 2 + 3 + 4 --> 1 + 2 + 3이 되었다. 
즉, idx 1과 2의 입장에선 3개만큼의 영향을 받은 것이다. 왜냐하면 arr[3] = 2를 할당함으로써 idx가 3이상인 집합의 개수가 하나씩 내려갔기 때문이다.
위 정보를 통해 알 수 있는 점은 idx i를 바꿀 경우 i 이후의 인덱스에는 영향을 끼치지 않고 -> 3 4 5
i까지의 인덱스들에게 영향을 끼친 다는 점이다. -> 1 2
즉, 일단 배열의 값들을 입력받으면 l[1,5]r[1,5]g(l,r)을 구한다. 이 값을 s라고 하겠다.
그리고 나서 i, x값을 받았을 때를 보자.
해당 i의 값이 배열에 끼치는 영향을 일단 s에서 뺀다. 
그리고 나서 i의 값에 x를 할당한 후 배열에 끼치는 영향을 s에 더해주는 것이다.
이렇게 되면 O(N)시간으로 i와 x값이 주어졌을 때 배열에 끼치는 영향들의 합을 구할 수 있다.
이때 계산식은 i * (n - i)가 된다. 
    ㄴ 편하게 생각하기 위해서 i가 위의 예시처럼 3이라고 가정하자. 배열은 위와 같다.
    ㄴ i의 값이 바뀜으로써 왼쪽값은 같아지고 오른쪽값은 그대로 다른 상황이다.
    ㄴ 왼쪽값이 같아졌기 때문에 idx 0과 1의 입장에선 3개만큼의 영향을 받은 것이다. 
    (왜냐하면 idx 0의 입장에선 2 3 4 5 -> 2 2 4 5가 되었으므로 1 2 3 4 에서 1 1 2 3 이 되었기 때문에 총 3의 영향을 받았다.
              idx 1의 입장에선 3 4 5 -> 2 3 4가 되었으므로 1 2 3 에서 0 1 2가 되었기 때문에 총 3의 영향을 받았다.)
    ㄴ 즉, s += (i-1) * (n - (i - 1)),  s += i * (n - i)를 해주면 된다.
    
나중에 왼쪽과 오른쪽을 나눈 이유가 헷갈릴거같아서 정리해둬야겠다.
1 2 3 4 5에서 1 2 4 4 5로 바꿨을 때를 가정해보자.
ㄴ 값은 각각 1 2 3 4 5, 1 2 3 3 4가 될 것이다.
일단은 바꾸기 전에 idx 3이 배열에 끼치는 영향은 왼쪽과 다름 -> 2 * 3 == 6, 오른쪽과 다름 -> 3 * 2 == 6이다.
바꾸고 난 후에 idx 3이 배열에 끼치는 영향은 왼쪽과 다름 -> 2 * 3 == 6, 오른쪽과 같음 -> x이다.
위에 나온 결과를 보면 바꾸기전에는 idx 3이 배열에 12만큼의 영향을 주었고, 바꾸고 난 후엔 배열에 6만큼의 영향을 주었으므로
바꾸기 전 총합에서 -6 만큼의 영향을 끼친 것이다. 
</pre>

<br><br>

# 착각했던 점

<p>

</p>

<pre>
<code>
#include <iostream>
using namespace std;

typedef long long ll;

ll n, m;

ll arr[100005];

ll b[100005];

int main() {
  cin >> n >> m;
  ll s = 0;
  b[1] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (i > 1) {
      if (arr[i] == arr[i - 1])
        b[i] = b[i - 1];
      else
        b[i] = b[i - 1] + 1;
    }
    s += b[i];
  }

  // 1 2 2 4 5
  // 1 2 2 3 4

  ll ans = s; // 12

  for (int i = 2; i <= n; i++) {
    if (b[i] == b[i - 1]) {
      ans += (s - 1);
      s = s - 1;
    } else {
      ans += s - (n - (i - 1) + 1);
      s = s - (n - (i - 1) + 1);
    }
  }

  for (int e = 0; e < m; e++) {
    int i, x;
    cin >> i >> x;

    if (i > 1) {
      // 왼쪽과 다를 때
      if (arr[i] != arr[i - 1]) {
        ans -= (i - 1) * (n - (i - 1));
      }
    }
    if (i < n) {
      // 오른쪽과 다를 때
      if (arr[i] != arr[i + 1]) {
        ans -= (i) * (n - i);
      }
    }

    arr[i] = x;

    if (i > 1) {
      // 왼쪽과 다를 때
      if (arr[i] != arr[i - 1]) {
        ans += (i - 1) * (n - (i - 1));
      }
    }
    if (i < n) {
      // 오른쪽과 다를 때
      if (arr[i] != arr[i + 1]) {
        ans += (i) * (n - i);
      }
    }
    cout << ans << "\n";
  }
}
</code>

</pre>

<br><br>

<p>
이해하기 조금 까다롭다..
</p>
