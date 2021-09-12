#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;

// ( == -2
// [ == -3

stack<int> st;

int main() {
	FIO;

	string input; cin >> input;

	bool isFinish = true;

	for (int i = 0; i < input.size(); i++) {
		char e = input[i];
		if (e == '(' || e == '[')
		{
			if (e == '(')
				st.push(-2);
			else if (e == '[')
				st.push(-3);
		}
		else {
			if (e == ')') {
				int temp = 1;
				bool isPop = false;
				while (!st.empty()) {
					if (st.top() > 0) {
						temp += st.top(); st.pop();
					}
					else {
						if (st.top() == -2)
						{
							if (temp == 1)
								temp *= 2;
							else
								temp--, temp *= 2;
							
							st.pop(); 
							st.push(temp);
							isPop = true;
							break;
						}
						else
						{
							isFinish = false;
							break;
						}
					}
				}
				if (isPop == false) {
					isFinish = false;
					break;
				}
			}
			if (e == ']') {
				int temp = 1;
				bool isPop = false;
				while (!st.empty()) {
					if (st.top() > 0) {
						temp += st.top(); st.pop();
					}
					else {
						if (st.top() == -3)
						{
							if (temp == 1)
								temp *= 3;
							else
								temp--, temp *= 3;

							st.pop();
							st.push(temp);
							isPop = true;
							break;
						}
						else
						{
							isFinish = false;
							break;
						}
					}
				}
				if (isPop == false) {
					isFinish = false;
					break;
				}
			}
			
		}
		if (isFinish == false)
			break;
	}

	if (isFinish == false)
		cout << 0 << "\n";
	
	else {
		int sum = 0;
		while (!st.empty()) {
			if (st.top() == -2 || st.top() == -3)
			{
				cout << 0 << "\n";
				return 0;
			}
			sum += st.top(); 
			st.pop();
		}
		cout << sum << "\n";
	}
}