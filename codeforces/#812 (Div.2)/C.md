# 문제주소

https://codeforces.com/contest/1713/C

<br><br>

# 문제 해석

<pre>
각 테스트 케이스마다 n이 주어진다.
[0,1,2,3, ... , n-1]의 배열이 있고, 이 배열의 순열 p가 있다.
이 p는 Pi + i의 값이 제곱 수 이다. 이러한 순열 p를 구하면 된다.
예를 들어 n == 3이라고 치자. 그러면 배열은 [0,1,2]가 될 것이다.
여기서 p가 되기 위해선 [1,0,2]여야 한다. 
arr[0] + 1 == 1
arr[1] + 0 == 1
arr[2] + 2 == 4 이다. 
</pre>

<br><br>

# 문제 접근 방법

<pre>
나는 일단 n을 8까지 일일이 나열해봤다. 
나열하는 과정에서 p를 구하는데 규칙성이 있나 봤고 생각보다 간단하게 해결할 수 있었다.
n == 8일때 보자
arr == [0,1,2,3,4,5,6,7]
(가능한 제곱수들) ==> 0,1,4,9
0 => (4 - 0), (1 - 0), (0 - 0) (9는 9 - 0이 n보다 크거나 같기 때문에 불가능하다.)
1 => (4 - 1), (1 - 1) (9는 위와 같은 이유로 안되고 0은 0 - 1 < 0이므로 불가능하다. )
2 => (9 - 2), (4 - 2) (여기서부턴 이유 생략)
3 => (9 - 3), (4 - 3) 
4 => (9 - 4), (4 - 4)
5 => (9 - 5)
6 => (9 - 6)
7 => (9 - 7) 
이렇게 나열을 해보자.
n-1 idx부터 탐색을 해보면 결국 7번째 idx에서 제곱수로 만들 수 있는 경우의 수는 1가지이고, 7번쨰 idx에는 2가 들어가야 할 것이다.
즉, 2번째 idx에는 7이 들어갈 수 있다. 
똑같이 6번째 idx에서도 제곱수로 만들 수 있는 경우는 1가지이고 3이 들어가야 한다.
즉, 3번째 idx에도 6이 들어갈 수 있다.
지금까지 보면 arr 배열에서 벌써 2 3 6 7 을 썼으므로 경우의 수가 많이 줄어들었음을 알 수 있다.
똑같이 위 과정을 반복하다보면 결국 경우의 1번쨰 idx와 0번째 idx에서는 이미 더 큰 idx에서 한가지 경우의 수로 숫자들이 모두 사용되었으므로
얘네도 1가지 경우만 남게된다.


</pre>

<br><br>

# 착각했던 점

<p>
시간 제한이 1초길래 생각을 해봤는데 10만번씩 1만 테스트 케이스를 받으면 10억이라 무조건 타임오버 나겠구나 싶었는데
각 테스트 마다 1초인거같다..
그리고 처음에 제곱수들을 vec에 저장하는 과정에서 n이 10만이 들어와버리면 2 * (n - 1) 은 19만 9천쯤 된다.
하지만 내가 범위 조건을 i * i <= 20만으로 두어서 19만 8천쯤 나오므로 처음에 초기화 해두었던 0으로 값이 나와버린다.
즉, 최대 19만 8천까지 탐색을 했는데도 조건이 성립이 안된다면 그냥 vec의 size - 1 만큼 bound를 설정해주면 된다. 
</p>

<pre>
<code>

#include <iostream>
using namespace std;
#include <string.h>
#include <vector>

int tc;

vector<int> vec; // 제곱수들 저장

int arr[200005];

bool v[200005];

int main() {

  for (int i = 0; i * i <= 200000; i++) {
    vec.push_back(i * i);
  }

  cin >> tc;

  while (tc--) {
    memset(arr, 0, sizeof(arr));
    memset(v, false, sizeof(v));

    int n;
    cin >> n;

    int bound = -1;

    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] > 2 * (n - 1)) {
        bound = i - 1;
        break;
      }
    }

    bound = (bound == -1) ? vec.size() - 1 : bound;

    for (int i = n - 1; i >= 0; i--) {
      if (v[i])
        continue;
      int t = bound;
      while (t >= 0) {
        if (vec[t] - i >= n)
          t--;
        else
          break;
      }

      for (int e = t; e >= 0; e--) {
        if (vec[e] - i <= 0 || v[vec[e] - i])
          continue;
        arr[i] = vec[e] - i;
        arr[vec[e] - i] = i;
        v[vec[e] - i] = true;
        v[i] = true;
        break;
      }
    }

    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
}

</code>

</pre>

<br><br>

<p>

</p>
