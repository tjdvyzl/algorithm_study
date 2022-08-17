# 문제주소

https://codeforces.com/contest/1719/problem/C

<br><br>

# 문제 해석

<pre>
테스트 마다 n과 q(토너먼트 참가자의 수, 질문의 수)가 주어진다. 

그리고 n 길이 만큼의 Ai 배열이 주어진다. 여기서 Ai배열의 값은 i번째 참가자가 가지는 힘의 세기이다.
그래서 Ai > Aj 라면 i번째 참가자는 무조건 j번째 참가자를 이긴다.

마지막으로 i와 k(참가자의 index, 라운드의 수)가 주어진다.

각 라운드마다 싸움을 한번 진행한다. 맨 앞 원소와 그 다음 원소가 싸워서
이긴 사람이 맨 앞에 남아있고 진 사람은 맨 뒤로 보낸다. 이 과정을 한번의 라운드동안 진행한다.

k번의 라운드를 진행한 후, i번째 참가자가 이긴 횟수를 출력하면 된다.
</pre>

<br><br>

# 문제 접근 방법

<pre>
DP를 이용해서 풀었다.

이긴 사람이 맨 앞에 남아있고 진 사람은 맨 뒤로 보내는 과정을 하기 위해 덱을 이용해서 풀었다.
구현은 위에서 말했듯이 말 그대로 구현하면 된다.

일단 결국 T번의 라운드를 진행했고 맨 앞에 원소의 값이 n이라면 어떤 라운드를 진행하든 n의 값을 가진 원소가 이길 것이다.
즉, 맨 앞 원소의 값이 n일 때 까지만 위 조건을 성립하면서 라운드를 진행시켜주면 된다.

문제는 시간초과다.
예를 들어보자.
100000번의 라운드를 먼저 진행했다고 하자. (물론 n값은 맨 뒤에 있다)
그리고 나서 99999번의 라운드를 진행해서 i번째 참가자의 우승 횟수를 구하고 싶다고 한다.
그렇다면 10만번을 진행시킨 후 9만번을 또 진행시켜야 될까?
이렇게되면 O(n^2) 값으로 시간초과가 날 것이다. 그리고 위 과정은 중복되는 경우가 많다.

결국 먼저 99999번의 라운드를 진행하여 진행하는 과정에서 (1 ~ n)까지의 참가자들의 우승 횟수를 모두 저장한다.
그리고 10만번의 라운드를 진행할 땐 99999번의 라운드를 진행시키는 동안의 결과값이 모두 저장되어있기 때문에 1번만 더 진행하면 된다.

위 과정을 구현하면 해결할 수 있다.
구현 과정을 간단히 설명하자면
q개의 질문을 받을 때 몇번째로 받은 질문인지, 그리고 질문에서 주는 i와 k를 vec에 저장한다.
vec를 k를 기준으로 오름차순 정렬한다. 이러면 앞으로 나올 라운드 횟수들은 고려하지 않아도 중복되는 과정을 배제할 수 있다.
그리고 문제에서 주어진 조건을 충족시키면서 라운드를 진행시킨다.
idx값 까지 저장해두었기 때문에 질문 하나를 끝냈다면 ans 배열의 vec[e].idx번째 인덱스에 i번째 참가자의 우승 횟수를 저장해준다.
여기서 주의할 점은 arr[vec[e].i]값이 n이라면 지금까지 진행하면서 vec[e].i번째 참가자가 우승했던 횟수 + 남은 라운드 수를 저장해주어야한다.
    ㄴ 이 이유는 덱의 맨 앞 원소가 n일때까지 while문을 돌리기 때문이다.
</pre>

<br><br>

# 착각했던 점

<p>
중복되는 과정을 생각안해서 시간초과가 났다.
</p>

<pre>
<code>
#include < iostream >
using namespace std;
#include < algorithm >
#include < deque >
#include < string.h >
#include < vector >

class node {
public:
  int idx;
  int i;
  int k;
  node() {}
  node(int idx, int i, int k) : idx(idx), i(i), k(k) {}
};

bool compare(node a, node b) { return a.k < b.k; }

int tc;

int arr[100005];

int wincnt[100005];

deque< int > dq;

vector< node > vec;

int ans[100005];

int main() {
  cin >> tc;

  while (tc--) {

    int n, q; // 토너먼트 참가자의 수, 질문의 수
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
      cin >> arr[i];

    dq.clear();
    vec.clear();

    for (int i = 1; i <= n; i++) {
      wincnt[i] = 0;
      dq.push_back(arr[i]);
    }

    for (int idx = 0; idx < q; idx++) {
      int i, k;
      cin >> i >> k;
      vec.push_back(node(idx, i, k));
    }

    sort(vec.begin(), vec.end(), compare);

    int bound = 0;

    for (int i = 0; i < vec.size(); i++) {
      int t = vec[i].k - bound;
      while (t && dq.front() != n) {
        int f = dq.front();
        dq.pop_front();
        int s = dq.front();
        dq.pop_front();
        if (f > s) {
          wincnt[f]++;
          dq.push_front(f);
          dq.push_back(s);
        } else {
          wincnt[s]++;
          dq.push_front(s);
          dq.push_back(f);
        }
        t--;
        bound++;
      }

      ans[vec[i].idx] = (arr[vec[i].i] == n) ? wincnt[arr[vec[i].i]] + t
                                             : wincnt[arr[vec[i].i]];
    }

    for (int i = 0; i < q; i++) {
      cout << ans[i] << "\n";
    }
  }
}
</code>

</pre>

<br><br>

<p>

</p>
