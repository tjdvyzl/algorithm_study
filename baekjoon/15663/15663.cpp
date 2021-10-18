#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;
#define MAX 99999999

int N, M;
int s[10];
bool v[10];
vector<int> vec;

void dfs(int x, int cnt) {
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << s[i] << " ";
		cout << "\n";
		return;
	}
	int before = -1;
	for (int i = x; i < vec.size(); i++) {
		if (before != vec[i]) {
			s[cnt] = vec[i];
			v[i] = true;
			before = vec[i];
			dfs(i, cnt + 1);
			v[i] = false;
		}
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	dfs(0,0);
}
