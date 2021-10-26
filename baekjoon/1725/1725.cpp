#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 2470000000

typedef long long ll;

int N;
int arr[100005];
stack<int> st; // idx 저장
int max_area = -1;

/*
	현재 막대 <= top 막대 push
	현재 막대 > top 막대 pop

*/

// 11
// 2 1 4 5 1 3 3 0 3 3 3 

int main() {
	FIO;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		if (i == 0)
			st.push(i);
		else {
			if (!st.empty() && arr[st.top()] <= arr[i]) {
				st.push(i);
			}
			else {
				while (!st.empty() && arr[st.top()] >= arr[i]) {
					int height = arr[st.top()]; st.pop();
					int width = st.empty() ? i : i - st.top() - 1;
					max_area = (max_area > width * height) ? max_area : width * height;
				}
				st.push(i);
			}
		}
	}

	while (!st.empty()) {
		int c = st.top(); st.pop();
		int width = st.empty() ? N : N - 1 - st.top();
		max_area = (max_area > width * arr[c]) ? max_area : width * arr[c];
	}

	cout << max_area << "\n";
}