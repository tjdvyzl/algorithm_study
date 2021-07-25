#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

int n, m;

vector<string> d;
vector<string> b;
vector<string> vec;

int find(string input) {
	int left, right, mid;
	left = 0;
	right = n - 1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (d[mid] == input)
			return 1;

		else if (d[mid] > input)
			right = mid - 1;

		else
			left = mid + 1;
	}
	return -1;
}

int main() {
	cin >> n >> m;

	int t1 = n;
	int t2 = m;

	while (t1--) {
		string input; cin >> input;
		d.push_back(input);
	}

	sort(d.begin(), d.end());


	while (t2--) {
		string input; cin >> input;
		if (find(input) == 1)
			vec.push_back(input);
	}

	cout << vec.size() << "\n";

	sort(vec.begin(), vec.end());

	for (auto e : vec)
		cout << e << "\n";

}