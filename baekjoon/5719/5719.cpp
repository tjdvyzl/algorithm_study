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
#define MAX 987654321

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pllll;

vector<pii> graph[505];
bool block[505][505];
int djk_dis[505];
int djk_dis2[505];
vector<int> _prev[505];

void init()
{
  memset(block, false, sizeof(block));
  fill(&djk_dis[0], &djk_dis[0] + 505, MAX);
  fill(&djk_dis2[0], &djk_dis2[0] + 505, MAX);
  for (int i = 0; i < 505; i++)
    graph[i].clear(), _prev[i].clear();
}
void djk(int src, int dst)
{
  queue<pii> q;
  q.push({src, 0});
  djk_dis[src] = 0;
  while (!q.empty())
  {
    int t = q.front().first;
    int cur_cost = q.front().second;
    q.pop();
    for (int i = 0; i < graph[t].size(); i++)
    {
      int e = graph[t][i].first;
      int e_cost = graph[t][i].second;

      if (djk_dis[e] < cur_cost + e_cost)
        continue;
      if (djk_dis[e] > cur_cost + e_cost)
      {
        _prev[e].clear();
        _prev[e].push_back(t);
        djk_dis[e] = cur_cost + e_cost;
        q.push({e, djk_dis[e]});
      }
      else if (djk_dis[e] == cur_cost + e_cost)
        _prev[e].push_back(t);
    }
  }
}

void djk2(int src)
{
  queue<pii> q;
  q.push({src, 0});
  djk_dis2[src] = 0;
  while (!q.empty())
  {
    int t = q.front().first;
    int cur_cost = q.front().second;
    q.pop();
    for (int i = 0; i < graph[t].size(); i++)
    {
      int e = graph[t][i].first;
      int e_cost = graph[t][i].second;
      if (block[t][e])
        continue;
      if (djk_dis2[e] <= cur_cost + e_cost)
        continue;
      djk_dis2[e] = cur_cost + e_cost;
      q.push({e, djk_dis2[e]});
    }
  }
}

void f(int cur)
{
  for (auto e : _prev[cur])
  {
    if (!block[e][cur])
    {
      block[e][cur] = true;
      f(e);
    }
  }
}

int main()
{
  FIO;

  int N, M;
  while (cin >> N >> M && N != 0 && M != 0)
  {
    init();
    int s, d;
    cin >> s >> d;
    for (int i = 0; i < M; i++)
    {
      int a, b, cost; // a --> b;
      cin >> a >> b >> cost;
      graph[a].push_back({b, cost});
    }
    djk(s, d);

    f(d);

    djk2(s);

    int ans = (djk_dis2[d] == MAX) ? -1 : djk_dis2[d];
    cout << ans << "\n";
  }
}
