#include <iostream>
#include <vector>
using namespace std;

int N, M; // 사람의 수 N과 파티의 수 M
int true_number; // 진실을 아는 사람의 수
vector<int> party[51];
vector<int> graph[51];
bool check[51];
bool visit[51];

bool exist(int bound, int input) { // 바운드 번째의 그래프에 input이 존재하는지 여부체크
	for (int i = 0; i < graph[bound].size(); i++) 
		if (graph[bound][i] == input)
			return true;
		
	return false;
}

void dfs(int input) {
	visit[input] = true;
	check[input] = true;
	for (int i = 0; i < graph[input].size(); i++) {
		int t = graph[input][i];
		if (!visit[t]) {
			dfs(t);
		}
	}
}
  
int main() {
	cin >> N >> M;
	cin >> true_number;
	
	while (true_number--)
	{
		int input; cin >> input;
		check[input] = true;
	}

	for (int i = 0; i < M; i++) {
		int n; cin >> n;
		while (n--) { // 파티 사람들 번호 입력
			int input; cin >> input;
			party[i].push_back(input);
		}
		for (int e = 0; e < party[i].size(); e++) { // 그 파티의 사람들 그래프로 설정
			int select = party[i][e];
			for (int r = 0; r < party[i].size(); r++) {
				int t = party[i][r];
				if (t != select && exist(select, t) == false) {
					graph[select].push_back(t);
					graph[t].push_back(select);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) 
		if (!visit[i] && check[i]) 
			dfs(i);
		
	int cnt = M;

	for (int i = 0; i < M; i++) {
		for (int e = 0; e < party[i].size(); e++) {
			int t = party[i][e];
			if (check[t] == true) {
				cnt--;
				break;
			}
		}
	}

	cout << cnt << "\n";
}