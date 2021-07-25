#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <queue>
#include <algorithm>


int n, m;

class Entry {
public:
	string value;
	int table_num;

	Entry() :value(""), table_num(-1) {}

	Entry(int key, string value) :value(value), table_num(key) {}

	bool operator<(const Entry& b) const {
		return this->value < b.value;
	}
};

vector<Entry> vec;
vector<Entry>vvec; // Á¤·Ä x

int find(string value) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (vec[mid].value == value)
			return vec[mid].table_num;

		else if (vec[mid].value > value)
			right = mid - 1;

		else
			left = mid + 1;
	}

	return -1;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string input; cin >> input;
		vec.push_back(Entry(i, input));
		vvec.push_back(Entry(i, input));
	}

	sort(vec.begin(), vec.end());

	while (m--) {
		string input; cin >> input;

		if ((int)input[0] < 65) {
			int temp = stoi(input);
			cout << vvec[temp-1].value << "\n";
		}
		else {
			int temp = find(input);
			cout << temp + 1<< "\n";
		}
	}
}