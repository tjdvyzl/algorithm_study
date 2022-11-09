#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;

int N, M;

vector<pair<int, int>> p; // number, money

vector<int> temp;
int maxSize = -1;
int dp[50];

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second)
    return a.first > b.first;
  return a.second < b.second;
}

void f(int idx, int sum) {
  for (int i = idx; i < p.size(); i++) {
    if (sum + p[i].second <= M) {
      temp.push_back(p[i].first);
      f(i, sum + p[i].second);
      temp.pop_back();
    } else {
      if (!temp.empty() && temp[temp.size() - 1] == 0)
        continue;
      if ((int)temp.size() < maxSize)
        return;

      maxSize = temp.size();

      for (int i = (int)temp.size() - 1; i >= 0; i--) {
        if (dp[i] > temp[i])
          break;
        else
          dp[i] = temp[i];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    p.push_back({i, input});
  }

  cin >> M;

  sort(p.begin(), p.end(), compare);

  vector<pair<int, int>>::iterator iter = p.begin();
  int bound = -1;
  while (iter != p.end()) {
    int curNumber = (*iter).first;
    int curMoney = (*iter).second;
    if (bound >= curNumber)
      p.erase(iter);
    else {
      bound = curNumber;
      iter++;
    }
  }

  f(0, 0);

  if (maxSize == -1 || dp[maxSize - 1] == 0)
    cout << 0 << "\n";
  else {
    for (int i = maxSize - 1; i >= 0; i--)
      cout << dp[i];
    cout << "\n";
  }
}