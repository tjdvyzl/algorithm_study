#include <iostream>
using namespace std;
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <limits.h>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0)
#define MAX 2000000005

typedef long long int ll;

int N, M;

int indegree[32222];  // 진입차수
int outdegree[32222]; // 진출차수

vector<int> graph[32222];

void dfs() {}

int main() {
  FIO;

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b;
    // b는 a번 문제를 풀어야 풀 수 있음
    cin >> a >> b;
    indegree[b]++;
    outdegree[a]++;
    graph[a].push_back(b);
  }
}