#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int n;
vector<int> vec; // <key, value>
vector<pair<int, int>> c; // 개수 저장

int find(int input) {
	int left = 0;
	int right = c.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (c[mid].first == input)
			return c[mid].second;
		else  if (c[mid].first > input)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

 	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input; cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	int bound = *vec.begin(); // -10
	int j = 0;
	c.push_back(make_pair(bound, 0));

	for (auto e : vec) {
		if (bound != e) {
			bound = e;
			++j;
			c.push_back(make_pair(bound, 1));
		}
		else
			c[j].second++;
	}

	int m; cin >> m;
	while (m--)
	{
		int input; cin >> input;
		cout << find(input) << " ";
	}
}