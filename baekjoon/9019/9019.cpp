#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int a, b;
string temp;
bool check[10001];
int d;
int s;
int l;
int r;

class node {
public:
	int value;
	string command;

	node(int value,string command):value(value),command(command){}
};


void bfs() {
	queue<node> q;
	q.push(node(a, ""));

	while (!q.empty()) {
		node t = q.front(); q.pop();

		d = t.value * 2 % 10000;
		s = (t.value == 0) ? 9999 : t.value - 1;
		l = (t.value / 1000) + (t.value % 1000 * 10);
		r = (1000 * (t.value % 10)) + (t.value / 10);

		if (check[t.value] == true)
			continue;

		check[t.value] = true;

		if (check[d] != true) {
			if (d == b) {
				temp = t.command + "D";
				break;
			}
			q.push(node(d, t.command + "D"));
		}
		if (check[s] != true) {
			if (s == b) {
				temp = t.command + "S";
				break;
			}
			q.push(node(s, t.command + "S"));
		}
		if (check[l] != true) {
			if (l == b) {
				temp = t.command + "L";
				break;
			}
			q.push(node(l, t.command + "L"));
		}
		if (check[r] != true) {
			if (r == b) {
				temp = t.command + "R";
				break;
			}
			q.push(node(r, t.command + "R"));
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		memset(check, 0, 10001 * sizeof(bool));

		cin >> a >> b;

		bfs();

		cout << temp << "\n";
	}
}