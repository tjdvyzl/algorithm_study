#include <iostream>
using namespace std;

int n;
int arr[2200][2200];
bool check[2200][2200];

int one = 0;
int zero = 0;
int _minus = 0;

bool isAllEqual(int y1,int y2, int x1, int x2) {
	int bound = arr[y1][x1];
	for (int y = y1; y <= y2; y++) {
		for (int x = x1; x <= x2; x++) {
			if (arr[y][x] != bound)
				return false;
		}
	}
	return true;
}

void f(int y1, int y2, int x1, int x2) { // 7 9 1 3
	if (isAllEqual(y1, y2, x1, x2) || y1 == y2 || x1 == x2)
	{
		for (int a = y1; a <= y2; a++)
			for (int b = x1; b <= x2; b++)
				check[a][b] = true;
		if (arr[y1][x1] == 3)
			one++;
		if (arr[y1][x1] == 2)
			zero++;
		if (arr[y1][x1] == 1)
			_minus++;
		return;
	}
	int length = (x2 - x1 + 1) / 3; // 1 9 10 18   3
	f(y1, y1 + length - 1, x1, x1 + length - 1); // 1 3 10 12
	f(y1, y1 + length - 1, x1 + length, x1 + 2 * length - 1); // 1 3 13 15
	f(y1, y1 + length - 1, x1 + 2 * length, x2); // 
	f(y1 + length, y1 + 2 * length - 1, x1, x1 + length - 1);
	f(y1 + length, y1 + 2 * length - 1, x1 + length, x1 + 2 * length - 1);
	f(y1 + length, y1 + 2 * length - 1, x1 + 2 * length, x2);
	f(y1 + 2 * length, y2, x1, x1 + length - 1);
	f(y1 + 2 * length, y2, x1 + length, x1 + 2 * length - 1);
	f(y1 + 2 * length, y2, x1 + 2 * length, x2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			int input; cin >> input;
			arr[y][x] = input + 2;
		}
	}

	int bound = arr[1][1];

	f(1, n, 1, n);
	cout << _minus << "\n" << zero << "\n" << one << "\n";
}