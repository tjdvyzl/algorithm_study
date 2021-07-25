#include <iostream>
#include <vector>
using namespace std;

int n, m; // 4 3

vector<int> vec;
int visit[9];


void dfs(int cnt) {
	if (cnt == m) {
		for (auto e : vec)
			cout << e << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == true) 
			continue;
		if (!vec.empty() && vec[vec.size()-1] > i)
			continue;
		visit[i] = true;
		vec.push_back(i);
		dfs(cnt + 1);
		visit[i] = false;
		vec.pop_back();
	}

}

int main() {
	cin >> n >> m; // 4 3
	
	dfs(0);
}