#include <iostream>
using namespace std;
#include <vector>

int n;

int inorder[100001];
int postorder[100001];

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		inorder[i] = input;
	}

	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		postorder[i] = input;
	}
}

int find_inorder_root_index(int data) {
	for (int i = 0; i < n; i++) {
		if (inorder[i] == data)
			return i;
	}
}

void f(int inorder_start_index, int inorder_end_index, int post_start_index, int post_end_index) {
	if (inorder_start_index > inorder_end_index || post_start_index > post_end_index)
		return;

	int root_index = find_inorder_root_index(postorder[post_end_index]);

	cout << inorder[root_index] << " ";

	int leftsize = root_index - inorder_start_index;
	int rightsize = inorder_end_index - root_index;

	f(inorder_start_index, root_index - 1,    post_start_index, post_start_index + leftsize - 1);
	f(root_index + 1, inorder_end_index,      post_start_index + leftsize, post_end_index - 1);
}

int main() {
	input();
	f(0, n - 1, 0, n - 1);
	cout << "\n";
	return 0;
}