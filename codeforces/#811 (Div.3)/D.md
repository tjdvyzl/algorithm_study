# 문제주소

https://codeforces.com/contest/1714/problem/D

<br><br>

# 문제 해석

<pre>
test case인 q(1 <= q <= 100)와 문자열 t(1 <= length <= 100) 그리고
n(1 <= n <= 10) 마지막으로 n개의 문자열 s(1 <= length <= 10)이 주어진다.

t == bababa, n == 2, s1 == ba, s2 == aba라고 하자.
ba는 t의 0번째, 2번째, 4번째 idx에 존재하고
aba는 t의 1번째, 3번째에 존재한다.
여기서 존재하는 s들을 적절하게 써서 겹쳐도 좋으니 bababa를 빨간색으로 색칠을 하면된다.
(예를 들어 t의 0번째 ba와 1번째 aba를 색칠한다고 하면 
 {ba}baba --> {baba}ba 이런식으로 색칠이 된다.)
색칠을 할 때 최소한의 색칠 횟수와 색칠 횟수를 최소한으로 했을 때의 (Si의 i, 문자열 t의 시작하는 idx) 를 출력하면 된다.
</pre>

<br><br>

# 문제 접근 방법

<pre>
브루트포스 + 정렬을 이용해서 해결했다.
일단 각 s들이 처음에 입력받을때 몇번째로 입력받는지 나중에 이용하기 위해서 idx와 string을 vec 배열에 담는다.
주어진 t를 0번째 idx부터 탐색을 한다.
탐색하는 과정에서 알파벳 x를 기준으로 vec를 전부 탐색한다.
	ㄴ vec의 i번째 idx string의 접두문자가 같은 문자가 존재한다면 t의 i번째 idx에서 그 문자열 길이만큼 잘라서 새로운 subString에 담는다.
	ㄴ 잘라온 subString을 vec의 i번째 idx의 string과 비교하여 같다면 area 배열에 담는다.
위 과정을 다 했다면 주어진 Si들을 이용해서 (몇번째로 받아온 Si인지)와 (몇번째 idx부터 몇번째 idx까지 Si를 칠할 수 있는 범위)를 모두 저장됐을 것이다.  
이 다음 정렬을 해주어야한다.
	ㄴ first를 오름차순 기준으로 정렬읋 하는데, 같은 first값이 있다면 second를 내림차순 기준으로 정렬한다.
	ㄴ 이 이유는 해당 t를 첫번째 idx부터 색칠을 할 수 있는지 여부를 판단해야하고
	ㄴ 최소한의 색칠 횟수를 구해야하기 때문이다. 
마지막으로 정렬한 area를 탐색한다.
탐색하기 전에 정렬했던 area의 첫번째 원소를 기준으로 bound_src와 bound_dst를 설정한다.
탐색하는 과정에서 src가 bound_src <= src <= bound_dst +1를 만족하고 bound_dst보다 큰 dst가 존재한다면
bound_dst를 새롭게 갱신해주고 update가 되었다는 표시를 해주어야한다.
	ㄴ 여기서 src의 범위가 bound_dst + 1까지인 이유는 t를 색칠할 때 꼭 s1과 s2가 겹칠 필요는 없기 때문이다.
	ㄴ update 표시를 해주는 이유
		ㄴ j for문을 탐색하는 과정에서 bound_dst보다 큰 dst가 존재한다면 bound 영역을 새로운 j 영역으로 수정해주어야하고
		ㄴ 해당 문자열이 처음에 입력받았을 때 몇번째로 받았는지를 알 수 있어야한다.
	ㄴ 그래서 만약에 update가 되었다면 new_dst는 src 조건을 만족하는 원소중 가장 큰 값일 것이고, 이 updateIdx와 영역을 ans에 저장해주어야한다.
</pre>

<br><br>

# 착각했던 점

<p>
마지막에 src가 0보다 큰지, dst가 t의 문자열 길이보다 작은지 여부를 판단해서 -1을 출력해주어야하는데 이 과정을 생략해버렸다. 
</p>

<pre>
<code>

#include <exception>
#include <iostream>
using namespace std;
#include <algorithm>
#include <cstring>
#include <queue>
#include <string.h>
#include <string>
#include <vector>

class node {
public:
  int idx;
  int src;
  int dst;
  node(int idx, int src, int dst) : idx(idx), src(src), dst(dst) {}
  node() {}
};

vector<pair<int, string>> vec; // 몇번째로 받은 string인지
vector<node> area;
vector<node> ans;

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first < b.first;
  } else {
    return a.second > b.second;
  }
}

bool compare2(node a, node b) {
  if (a.src != b.src) {
    return a.src < b.src;
  } else {
    return a.dst > b.dst;
  }
}

int main() {

  int tc;
  cin >> tc;
  while (tc--) {

    vec.clear();
    area.clear();
    ans.clear();

    string input;
    cin >> input;

    int n;
    cin >> n;

    // 머리 문자만 따서 vec[a~z]에 저장하자.
    for (int i = 0; i < n; i++) {
      string temp;
      cin >> temp;
      vec.push_back(make_pair(i, temp));
    }

    for (int i = 0; i < input.length(); i++) {
      for (int j = 0; j < vec.size(); j++) {
        if (input[i] == vec[j].second[0]) {

          string sub = input.substr(i, vec[j].second.length());

          if (sub == vec[j].second)
            area.push_back(
                node(vec[j].first, i, i + vec[j].second.length() - 1));
        }
      }
    }

    // cout << input << " --> ";
    // for (auto e : area)
    //   cout << e.idx << ", " << e.src << ", " << e.dst << "\n";

    // cout << "\n\n";

    if (area.empty()) {
      cout << -1 << "\n";
      continue;
    }

    sort(area.begin(), area.end(), compare2);

    int src = area[0].src, dst = area[0].dst;

    ans.push_back(node(area[0].idx, src, dst));

    for (int i = 0; i < area.size() - 1; i++) {
      int temp_src = src, temp_dst = dst;
      bool isUpdate = false;
      int updateIdx = -1;
      for (int j = i + 1; j < area.size(); j++) {
        int s = area[j].src;
        int d = area[j].dst;
        if (d <= dst)
          continue;
        if (s >= src && s <= dst + 1) {
          if (d > temp_dst) {
            isUpdate = true;
            updateIdx = area[j].idx;
            temp_src = s;
            temp_dst = d;
          }
        }
      }
      if (isUpdate) {
        ans.push_back(node(updateIdx, temp_src, temp_dst));
        dst = temp_dst;
      }
    }

    if (src > 0 || dst < input.length() - 1) {
      cout << -1 << "\n";
      continue;
    }

    cout << ans.size() << "\n";
    for (auto e : ans)
      cout << e.idx + 1 << " " << e.src + 1 << "\n";
  }
}

</code>

</pre>

<br><br>

<p>

</p>
