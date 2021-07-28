#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Entry {
public:
	int idx;
	int key;
	string value;

	Entry(int idx, int key, string value):idx(idx), key(key),value(value){}

	bool operator<(const Entry& b) const {
		if(this->key != b.key)
			return this->key < b.key;
		else {
			return this->idx < b.idx;
		}
	}
};

int main() {
	vector<Entry> vec;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int key; cin >> key;
		string value; cin >> value;
		vec.push_back(Entry(i, key, value));
	}

	sort(vec.begin(), vec.end());

	for (auto e : vec)
		cout << e.key << " " << e.value << "\n";
}