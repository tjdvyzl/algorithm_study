#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

typedef long long ll;

ll N, M; // 나무의 수, 나무의 높이
ll _min;
ll min_bound;

vector<int> vec;

ll getTreeHeight(ll bound) {
	ll sum = 0;
	for (auto e : vec) 
		if(e - bound > 0) 
			sum += (e - bound);
	
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	while (N--) {
		ll input; cin >> input;
		vec.push_back(input);
		_min += input;
	}

	sort(vec.begin(), vec.end());
	
	ll left = 0;
	ll right = 1000000000;
	ll m;
	ll mid;
	
	while (left <= right) {
		mid = (left + right) / 2; //5000
		m = getTreeHeight(mid);
		if (m >= M) {
			if (m < _min) {
				_min = m;
				min_bound = mid;
			}
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << min_bound << "\n";
}