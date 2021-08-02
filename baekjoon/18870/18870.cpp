#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> vec; // 원본
	vector<int> idx; // 정렬
	while (n--) {
		int input; cin >> input;
		vec.push_back(input);
		idx.push_back(input);
	}
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	for (auto e : vec) {
		cout << lower_bound(idx.begin(), idx.end(), e) - idx.begin() << " ";
	}
}