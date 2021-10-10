#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321

int tc;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second > b.second;
	else
		return a.first < b.first;
}

vector<pair<int,int>> vec;
vector<pair<int, int>> arr;

int main() {
	FIO;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int d,w; cin >> d >> w;
		vec.push_back(make_pair(d,w));
	}

	sort(vec.begin(), vec.end(), compare);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (vec[i].first > cnt && cnt + 1 <= n) {
			arr.push_back(vec[i]);
			cnt++;
		}
		else if(cnt + 1 <= n){
			int min_idx = -1, Min = MAX;
			for (int e = 0; e < arr.size(); e++) {
				if (Min > arr[e].second)
					Min = arr[e].second, min_idx = e;
			}
			if (Min < vec[i].second) {
				arr.erase(arr.begin() + min_idx);
				arr.push_back(vec[i]);
			}
		}
	}

	int sum = 0;

	for (auto e : arr)
		sum += e.second;
	cout << sum << "\n";
}