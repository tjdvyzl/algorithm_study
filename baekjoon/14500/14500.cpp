#include <bits/stdc++.h>
using namespace std;

int N, M; // y x
int arr[501][501];

int total_max = -1;

int getMaxTetromino(int y, int x) {
	int _max = -1;
	int sum = 0;

	// 도형 1번

	if (x + 3 <= M)
	{
		sum = 0;
		for (int xx = x; xx <= x + 3; xx++)
			sum += arr[y][xx];
		if (sum > _max)
			_max = sum;
	}

	// 도형 2번

	if (y - 1 >= 1 && x + 2 <= M) {
		sum = 0;
		sum += arr[y - 1][x];
		for (int xx = x; xx <= x + 2; xx++)
			sum += arr[y][xx];
		if (sum > _max)
			_max = sum;
	}

	if (y - 1 >= 1 && x - 2 >= 1) {
		sum = 0;
		sum += arr[y - 1][x];
		for (int xx = x - 2; xx <= x; xx++)
			sum += arr[y][xx];
		if (sum > _max)
			_max = sum;
	}

	if (y + 1 <= N && x + 2 <= M) {
		sum = 0;
		sum += arr[y + 1][x];
		for (int xx = x; xx <= x + 2; xx++)
			sum += arr[y][xx];
		if (sum > _max)
			_max = sum;
	}

	if (y + 1 <= N && x - 2 >= 1) {
		sum = 0;
		sum += arr[y + 1][x];
		for (int xx = x - 2; xx <= x; xx++)
			sum += arr[y][xx];
		if (sum > _max)
			_max = sum;
	}

	// 3
	if (x + 1 <= M && y + 1 <= N)
	{
		sum = 0;
		for (int yy = y; yy <= y + 1; yy++)
			for (int xx = x; xx <= x + 1; xx++)
				sum += arr[yy][xx];
		if (sum > _max)
			_max = sum;
	}

	// 4
	if (x + 2 <= M && y - 1 >= 1) {
		sum = 0;
		for (int xx = x; xx <= x + 1; xx++)
			sum += arr[y][xx];
		for (int xx = x + 1; xx <= x + 2; xx++)
			sum += arr[y - 1][xx];
		if (sum > _max)
			_max = sum;
	}

	if (x - 2 >= 1 && y - 1 >= 1) {
		sum = 0;
		for (int xx = x - 1; xx <= x; xx++)
			sum += arr[y][xx];
		for (int xx = x - 2; xx <= x - 1; xx++)
			sum += arr[y - 1][xx];
		if (sum > _max)
			_max = sum;
	}

	// 5
	if (x + 2 <= M && y - 1 >= 1) {
		sum = 0;
		sum += arr[y - 1][x + 1];
		for (int xx = x; xx <= x + 2; xx++)
			sum += arr[y][xx];
		if (sum > _max)
			_max = sum;
	}

	if (x + 2 <= M && y + 1 <= N) {
		sum = 0;
		sum += arr[y + 1][x + 1];
		for (int xx = x; xx <= x + 2; xx++)
			sum += arr[y][xx];
		if (sum > _max)
			_max = sum;
	}

	// 6
	if (x + 1 <= M && y + 2 <= N) {
		sum = 0;
		sum += arr[y][x];
		for (int yy = y; yy <= y + 2; yy++)
			sum += arr[yy][x + 1];
		if (sum > _max)
			_max = sum;
	}

	if (x - 1 >= 1 && y + 2 <= N) {
		sum = 0;
		sum += arr[y + 2][x - 1];
		for (int yy = y; yy <= y + 2; yy++)
			sum += arr[yy][x];
		if (sum > _max)
			_max = sum;
	}

	if (x - 1 >= 1 && y + 2 <= N) {
		sum = 0;
		sum += arr[y][x];
		for (int yy = y; yy <= y + 2; yy++)
			sum += arr[yy][x - 1];
		if (sum > _max)
			_max = sum;
	}

	if (x + 1 <= M && y + 2 <= N) {
		sum = 0;
		sum += arr[y + 2][x + 1];
		for (int yy = y; yy <= y + 2; yy++)
			sum += arr[yy][x];
		if (sum > _max)
			_max = sum;
	}

	// 7
	if (x + 1 <= M && y + 2 <= N) {
		sum = 0;
		sum += arr[y + 1][x + 1];
		for (int yy = y; yy <= y + 2; yy++)
			sum += arr[yy][x];
		if (sum > _max)
			_max = sum;
	}
	
	if (x - 1 >= 1 && y + 2 <= N) {
		sum = 0;
		sum += arr[y + 1][x - 1];
		for (int yy = y; yy <= y + 2; yy++)
			sum += arr[yy][x];
		if (sum > _max)
			_max = sum;
	}

	// 8
	if (x + 1 <= M && y + 2 <= N) {
		sum = 0;
		for (int yy = y; yy <= y + 1; yy++)
			sum += arr[yy][x];
		for (int yy = y + 1; yy <= y + 2; yy++)
			sum += arr[yy][x+1];
		if (sum > _max)
			_max = sum;
	}

	if (x - 1 >= 1 && y + 2 <= N) {
		sum = 0;
		for (int yy = y; yy <= y + 1; yy++)
			sum += arr[yy][x];
		for (int yy = y + 1; yy <= y + 2; yy++)
			sum += arr[yy][x - 1];
		if (sum > _max)
			_max = sum;
	}

	// 9
	if (y + 3 <= N) {
		sum = 0;
		for (int yy = y; yy <= y + 3; yy++)
			sum += arr[yy][x];
		if (sum > _max)
			_max = sum;
	}

	return _max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> arr[y][x];
		}
	}

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= M; x++)
			if (total_max < getMaxTetromino(y, x))
				total_max = getMaxTetromino(y, x);

	cout << total_max << "\n";
	
}