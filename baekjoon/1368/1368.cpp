#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

class node {
public:
  int src;
  int dst;
  int cost;
  node(int src, int dst, int cost) : src(src), dst(dst), cost(cost) {}
};

bool compare(node a, node b) { return a.cost < b.cost; }

int N;

int arr[333];

int ans = 0;

vector<node> edge;

int parent[333];

int find(int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

void merge(int a, int b, int cost) {
  a = find(a);
  b = find(b);

  if (a == b)
    return;

  if (arr[a] < arr[b]) {
    parent[b] = a;
    if (arr[b] > cost)
      ans += cost;
    else
      ans += arr[b];
  } else {
    parent[a] = b;
    if (arr[a] > cost)
      ans += cost;
    else
      ans += arr[a];
  }
}

int main() {
  FIO;

  cin >> N;

  for (int i = 0; i < N; i++)
    parent[i] = i;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int input;
      cin >> input;
      if (input == 0)
        continue;
      edge.push_back(node(i, j, input));
    }
  }

  sort(edge.begin(), edge.end(), compare);

  for (int i = 0; i < edge.size(); i++) {
    int a = edge[i].src;
    int b = edge[i].dst;
    merge(a, b, edge[i].cost);
  }
  ans += arr[find(0)];

  cout << ans << "\n";
}