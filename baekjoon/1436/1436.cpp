#include <iostream>
#include <string>
using namespace std;


int main()
{
	int n, cnt = 0;
	cin >> n;
	int i = 665;
	int temp;
	while (cnt != n) {
		i++;
		temp = i;

		while (temp != 0 && temp % 1000 != 666) {// i 에 666이 속해있는지 검사.
			temp /= 10;
		}
			
		if (temp % 1000 == 666)
			cnt++;
		
	}	
	cout << i << "\n";
}