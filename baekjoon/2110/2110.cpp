#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1000000001

typedef long long ll;


/*
	파라메트릭 서치 알고리즘
	최적화 문제(문제의 상황을 만족하는 특정 변수의 최솟값, 최댓값을 구하는 문제)를 결정 문제로 바꾸어 푸는 것

	https://sarah950716.tistory.com/16
*/

vector <int> vec; // 공유기 좌표값 저장

int N, C;

int _max = -1;

int main() {
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	int left = 1;
	int right = vec[vec.size() - 1] - vec[0];

	while (left <= right) {
		int mid = (left + right) / 2;

		int c = 1;
		int b = 0;
		for (int i = 1; i < vec.size(); i++) {
			if (vec[i] - vec[b] >= mid) {
				c++;
				b = i;
			}
		}

		if (c >= C) {
			_max = max(_max, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << _max << "\n";
}