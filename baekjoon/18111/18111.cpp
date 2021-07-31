#include <iostream>
using namespace std;

typedef long long ll;

int N, M, B; // 세로, 가로, 보유 블럭 개수

ll arr[501][501];
ll arr2[501][501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> B;
	ll temp_clock = 0;
	ll extra_cnt = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
			temp_clock += arr[y][x] * 2;
			extra_cnt += arr[y][x];
		}
	}

	ll before_clock = temp_clock;
	ll before_height = arr[0][0];
	bool isEmpty = false;

	while (!isEmpty && before_clock >= temp_clock && (extra_cnt >= 0 || B > 0)) {
		before_clock = temp_clock;
		before_height = arr2[0][0];
		for (int y = 0; (y < N && !isEmpty); y++) {
			for (int x = 0; x < M; x++) {
				if (arr[y][x] > arr2[y][x]) { 
					arr2[y][x]++;
					extra_cnt--;
					temp_clock -= 2;
				}
				else { // 차이 만큼 상자에서 빼오던가 여분의 블럭에서 빼오던가 해야됨.
					if (B > 0) {
						B--;
						arr[y][x]++;
						arr2[y][x]++;
						temp_clock++;
					}
					else if (extra_cnt > 0) {
						arr[y][x]++;
						arr2[y][x]++;
						temp_clock++;
						extra_cnt--;
					}
					else {
						isEmpty = true;
						break;
					}
				}
			}
		}
	}
	cout << before_clock << " " << before_height << "\n";
}