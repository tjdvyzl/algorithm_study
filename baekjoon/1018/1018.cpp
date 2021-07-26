#include <iostream>
using namespace std;

#define MAX 247000000

int m, n;
char arr[52][52];

int min_cnt = MAX;

char b[8][8] = {
	{'B','W','B','W','B','W','B','W' },
	{'W','B','W','B','W','B','W','B' },
	{'B','W','B','W','B','W','B','W' },
	{'W','B','W','B','W','B','W','B' },
	{'B','W','B','W','B','W','B','W' },
	{'W','B','W','B','W','B','W','B' },
	{'B','W','B','W','B','W','B','W' },
	{'W','B','W','B','W','B','W','B' }
};

char w[8][8] = {
	{'W','B','W','B','W','B','W','B' },
	{'B','W','B','W','B','W','B','W' },
	{'W','B','W','B','W','B','W','B' },
	{'B','W','B','W','B','W','B','W' },
	{'W','B','W','B','W','B','W','B' },
	{'B','W','B','W','B','W','B','W' },
	{'W','B','W','B','W','B','W','B' },
	{'B','W','B','W','B','W','B','W' }
};

void f(int y, int x) {
	int cnt_w = 0;
	int cnt_b = 0;

	//맨 왼쪽 위가 W인 경우
		for (int yy = y; yy <= y + 8 - 1; yy++) 
			for (int xx = x; xx <= x + 8 -1; xx++) 
				if (w[yy - y][xx - x] != arr[yy][xx]) 
					cnt_w++;
				
			
	//맨 왼쪽 위가 B인 경우
		for (int yy = y; yy <= y + 8 - 1; yy++)
			for (int xx = x; xx <= x + 8 - 1; xx++)
				if (b[yy - y][xx - x] != arr[yy][xx]) 
					cnt_b++;
				

	if (cnt_w < min_cnt)
		min_cnt = cnt_w;

	if (cnt_b < min_cnt)
		min_cnt = cnt_b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	for (int y = 1; y <= m; y++) {
		for (int x = 1; x <= n; x++) {
			char input; cin >> input;
			arr[y][x] = input;
		}
	}

	for (int y = 1; y <= m - 8 + 1; y++) {
		for (int x = 1; x <= n - 8 + 1; x++) {
			f(y, x);
		}
	}

	cout << min_cnt << "\n";
}