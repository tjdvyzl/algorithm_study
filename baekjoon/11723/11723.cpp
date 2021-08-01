#include <iostream>
using namespace std;

int T;
int bit = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		string input; cin >> input;
		int value;
		if (input == "add") {
			cin >> value;
			bit |= (1 << (value - 1));
		}
		else if (input == "remove") {
			cin >> value;
			bit &= ~(1 << (value - 1));
		}
		else if (input == "check") {
			cin >> value;
			if (bit & (1 << (value - 1)))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (input == "toggle") {
			cin >> value;
			if (bit & (1 << (value - 1)))
				bit &= ~(1 << (value - 1));
			else
				bit |= (1 << (value - 1));
		}
		else if (input == "all") {
			for (int i = 0; i < 20; i++) {
				bit |= (1 << i);
			}
		}
		else if (input == "empty") {
			bit = 0;
		}
	}
}