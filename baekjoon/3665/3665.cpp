#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<char, pii> pii2;
#define MAX 987654321

vector<int> vec;
int tc;
int n, m;
int indegree[505];
bool edge[505][505]; // edge[a][b] --> a가 b보다 우선순위가 높음

int main() {
  FIO;

  cin >> tc;

  while (tc--) {
    vec.clear();
    memset(indegree, 0, sizeof(indegree));
    memset(edge, false, sizeof(edge));

    cin >> n;
    for (int i = 0; i < n; i++) {
      int input;
      cin >> input;
      vec.push_back(input);
    }

    for (int i = 0; i < vec.size(); i++) {
      for (int j = i + 1; j < vec.size(); j++) {
        edge[vec[i]][vec[j]] = true;
        indegree[vec[j]]++;
      }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      if (edge[a][b]) {
        edge[a][b] = false;
        edge[b][a] = true;
        indegree[b]--;
        indegree[a]++;
      } else {
        edge[b][a] = false;
        edge[a][b] = true;
        indegree[a]--;
        indegree[b]++;
      }
    }

    queue<int> q;

    for (int i = 0; i < vec.size(); i++)
      if (indegree[vec[i]] == 0)
        q.push(vec[i]);

    vector<int> ans;

    while (!q.empty()) {
      if (q.size() >= 2) {
        ans.clear();
        break;
      }
      int t = q.front();
      q.pop();
      ans.push_back(t);
      for (int i = 0; i < vec.size(); i++) {
        int e = vec[i];
        if (edge[t][e]) {
          edge[t][e] = false;
          indegree[e]--;
          if (indegree[e] == 0)
            q.push(e);
        }
      }
    }

    if (ans.empty()) {
      cout << "IMPOSSIBLE\n";
    } else {
      if (ans.size() < n)
        cout << "IMPOSSIBLE\n";
      else {
        for (auto e : ans)
          cout << e << " ";
        cout << "\n";
      }
    }
  }
}