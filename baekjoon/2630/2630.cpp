#include <iostream>
using namespace std;

int n; 
int _map[129][129];
int w = 0; // 0
int b = 0; // 1

void f(int y1, int x1, int y2, int x2) { //
	if (y1 >= y2 || x1 >= x2) {
		if (_map[y1][x1] == 0)
			w++;
		else
			b++;
		return;
	}

	bool allColor = true;

	int bound = _map[y1][x1];

	for (int y = y1; y <= y2; y++) {
		for (int x = x1; x <= x2; x++) {
			if (_map[y][x] != bound) {
				allColor = false;
				break;
			}
		}
		if (allColor == false)
			break;
	}

	if (allColor == false) { // 1 1 2 2
		int hor = x2 - x1 + 1; // 1 
		int ver = y2 - y1 + 1; // 1
		
		f(y1, x1, y1 + ver / 2 - 1, x1 + hor / 2 - 1); // 1사분면 5 1 4
		f(y1, x1 + hor/2, y1 + ver/2 -1, x2); // 2사분면  
		f(y1 + ver / 2, x1, y2, x1 + hor / 2 - 1); // 3사분면  5 1 8 4
		f(y1 + ver/2, x1 + hor/2, y2, x2);// 4사분면 
	}
	else {
		if (bound == 0)
			w++;
		else
			b++;
		return;
	}
}

int main() {
	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			int input; cin >> input;
			_map[y][x] = input;
		}
	}
	f(1, 1, n, n);

	cout << w << "\n";
	cout << b << "\n";
}