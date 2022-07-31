#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>

#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

vector<int> graph[1005];
int arr[1005]; // 각 정점 번호에 대해 걸리는 시간 저장

int dis[1005]; // 해당 정점까지 건설 할 조건을 충족시키는데에 걸리는 시간

bool visit[1005];

void init(int n) {
  for (int i = 0; i <= n; i++) {
    graph[i].clear();
    visit[i] = false;
  }
}

void dfs(int v, int before_v) {

  // 아직 탐색할 가지가 남은 경우

  for (int i = 0; i < graph[v].size(); i++) {
    int e = graph[v][i];

    // 다음 정점을 봤는데 이미 조건을 모두 충족시키는 거리가 저장되어있을때 즉,
    // 말단 정점까지 방문한 적이 있을 때
    if (visit[e]) {
      dis[v] = max(dis[v], dis[e] + arr[v]);
      continue;
    }

    dfs(e, v);
  }
  visit[v] = true;

  if (v == before_v)
    return;

  dis[before_v] = max(dis[before_v], dis[v] + arr[before_v]);
}

int main() {
  FIO;

  int tc;
  cin >> tc;
  while (tc--) {
    int N, K;
    cin >> N >> K;
    init(N);
    for (int i = 1; i <= N; i++) {
      cin >> arr[i];
      dis[i] = arr[i];
    }

    for (int i = 0; i < K; i++) {
      int src, dst;
      cin >> src >> dst;
      graph[dst].push_back(src);
    }

    int target;
    cin >> target;

    dfs(target, target);

    cout << dis[target] << "\n";
  }
}