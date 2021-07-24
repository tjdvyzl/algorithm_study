#include <iostream>
using namespace std;
#include <vector>

int n; 

int arr[1001];
int lis[1001]; // 가장 긴 증가하는 수열 저장

vector<int> _min(1001, 247000000); //그 인덱스 번째의 값에 대해 뒤에 나온 값중에서 가장 작은 값 저장
int lds[1001]; // 가장 긴 감소하는 수열 저장

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		arr[i] = input;
		lis[i]++;
		int _max = 0;
		for (int j = 0; j < i; j++) { // lis 맥스값 저장
			if (arr[i] > arr[j]) { 
				if(lis[j] > _max)
					_max = lis[j];
			}
		}
		lis[i] += _max;
	}

	for (int i = n - 1; i >= 0; i--) {
		lds[i]++;
		int _max = 0;
		for (int j = n-1; j >= i; j--) {
			if (arr[j] < arr[i]) {
				if (lds[j] > _max)
					_max = lds[j];
			}
		}
		lds[i] += _max;
	}
	
	int mmax = -1;
	for (int i = 0; i < n; i++) {
		if (mmax < lis[i] + lds[i])
			mmax = lis[i] + lds[i];
	}
	cout << mmax - 1<< "\n";
}