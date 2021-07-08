#include <bits/stdc++.h>
using namespace std;

int tri[501][501];

int main() {
	int T; cin >> T;

	tri[0][0] = 0;
	tri[0][1] = 0;

	int cost[501][501];

	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < i; j++) { // 2 1
			cin >> cost[i][j];
			if (j == 0 || j == i - 1)
			{
				if(i==1)
					tri[i][j] = cost[i][j] + tri[i - 1][j];
				if (i > 1)
				{
					if(j == 0)
						tri[i][j] = cost[i][j] + tri[i - 1][j];
					if (j == i - 1)
						tri[i][j] = cost[i][j] + tri[i - 1][j - 1];
				}
			}
			else
				tri[i][j] = cost[i][j] + max(tri[i - 1][j - 1], tri[i - 1][j]);
		}
	}

	int max = -1;

	for (int i = 0; i < T; i++) {
		if (max < tri[T][i]) max = tri[T][i];
	}
	cout << max << "\n";
}