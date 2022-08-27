# 문제주소

<br><br>

# 문제 접근 방법

<pre>
매개변수탐색으로 해결했다.
문제에선 지점 사이의 거리들 중 최솟값을 구하는데, n개만큼의 바위를 제거 한 후 제거하는 경우들의 최솟값들 중 가장 큰 값을
구하라고 한다.
거리들의 최솟값들 중 최대값을 구하라고 하였으므로, 우리가 여기서 집중적으로 봐야될 점은 "지점들 사이의 거리"이다.

문제에서 주어진 예시를 이용해서 이해해보자.
2 11 14 17 21 25이다. (여기서 25까지 포함한 이유는 지점들 사이의 거리이므로 21인 지점과 25인 지점 사이의 거리도 포함시켜줘야한다.)
거리들의 최솟값들 중 최대값을 K라고 하자.
K가 나올 수 있는 최솟값은 일단 1이다.
k가 나올 수 있는 최댓값은 문제에서 주어진 distance인 25이다. (바위가 전부 없다고 생각해보자)
그렇다면 여기서 lo를 1로 할당하고 hi를 25로 할당해서 매개변수탐색을 해보자.
조건은 다음과 같다.
i) 설정한 변수의 값보다 작다면 제거한다.
ii) 설정한 변수의 값보다 크거나 같다면 살려둔다.

1. lo == 1, hi == 25, mid == 13
   2 11 14 17 21 25
   2 9 3 3 4 4 --> 지점들 사이의 거리
   x x x x x x
   바위를 6개나 제거했다. 이 경우는 설정한 변수가 너무 큰 경우이다. 범위를 줄여주자.

2. lo == 1, hi == 12, mid == 6
   2 11 14 17 21 25
   x 11 x 6 x 8
   x o x o x o
   여기서 두번째 값이 11인 이유는 값이 2인 바위를 제거했으므로 처음 지점부터 11까지의 거리는 11이다.
   다음 네번재 값이 6인 이유는 값이 11인 바위를 살려두었으므로 11인 지점의 바위와 17인 지점의 바위 사이의 거리는 6이다.
   바위를 3개나 제거했다. 이 경우 또한 범위가 너무 크다

3. lo == 1, hi == 5, mid == 3
   2 11 14 17 21 25
   x 11 3 3 4 4
   x o o o o o
   바위를 1개만 제거했다. 이 경우는 변수가 작은 경우이므로 탐색할 수 있는 범위까지 모두 탐색하기 위해 범위를 높여주자.

4. lo == 4, hi == 5, mid == 4
   2 11 14 17 21 25
   x 11 x 6 4 4
   x o x o o o
   바위를 주어진 n만큼 제거했다. 이 경우는 변수가 답과 근접하지만 남아있는 경우가 있을 수 있으므로 범위를 줄여주자.

5. lo == 5, hi == 5, mid == 5
   2 11 14 17 21 25
   x 11 x o x o
   x o x o x o
   바위를 3개나 제거했으므로 변수를 높게 설정했다. 그러므로 범위를 줄여주는데, hi를 줄여줌으로써 lo가 hi보다 커지게 되고 while문이 종료된다.

   이렇게 답은 4이다.
</pre>

<br><br>

# 착각했던 점

<p>
어려웠다. 매개변수탐색을 많이 접해보지 않아서 조금 생소했던 것도 있지만 
어떤 요소를 변수로 설정하는지 이 문제가 왜 이분탐색 분류인지 처음엔 감이 안잡혔던 것 같다. 
</p>
<br><br>

# 코드

<pre>
<code>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
  int answer = 0;

  rocks.push_back(distance);

  sort(rocks.begin(), rocks.end());

  int lo = 1, hi = distance;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int cnt = 0;         // 제거한 바위의 수
    int current_pos = 0; // 현재 지
    for (int i = 0; i < rocks.size(); i++) {
      if (rocks[i] - current_pos < mid)
        cnt++;
      else
        current_pos = rocks[i];
    }
    if (cnt <= n) {
      answer = max(answer, mid);
      lo = mid + 1;
    } else
      hi = mid - 1;
  }

  return answer;
}

</code>
</pre>

<br><br>

<p>

</p>
