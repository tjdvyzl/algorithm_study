#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1000000001

typedef long long ll;

int N; // ∏ ¿« ≈©±‚
int _map[21][21];

int min_sub = MAX;

int choice[21] = {};

bool check[21];

int getSum(vector<int> vec) {
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++) {
			sum += _map[vec[i]][vec[j]];
		}
	}

	return sum;
}

void f(int idx, int before_num) {
	if (idx > N / 2) {
		int sum1 = 0;

		vector<int> vec1;
		vec1.clear();
		for (int i = 0; i < N / 2; i++) {
			vec1.push_back(choice[i]);
			check[i] = true;
		}
		sum1 = getSum(vec1);

		vector<int> vec;
		vec.clear();
		for (int i = 1; i <= N; i++) {
			bool isExist = false;
			for (auto e : vec1) {
				if (e == i)
				{
					isExist = true;
					break;
				}
			}
			if (isExist == true)
				continue;
			else
				vec.push_back(i);
		}

		int sum2 = getSum(vec);
		

		check[idx - 1] = false;

		min_sub = min(abs(sum1 - sum2), min_sub);

		return;
	}	

	if (before_num > N + 1)
		return;

	choice[idx] = before_num;

	f(idx + 1, before_num + 1);
	f(idx, before_num + 1);
}

int main() {
	FIO;

	cin >> N;

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> _map[y][x];

	f(0, 1);

	cout << min_sub << "\n";
}