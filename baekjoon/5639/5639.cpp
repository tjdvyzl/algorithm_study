#include <iostream>
using namespace std;

class Node {
public:
	Node* parent;
	Node* left;
	Node* right;
	int data;

	Node(int data):data(data),parent(nullptr),left(nullptr),right(nullptr){}

	void setLeft(Node* node) {
		if (node == nullptr)
			this->left = nullptr;
		else
		{
			this->left = node;
			node->parent = this;
		}
	}

	void setRight(Node* node) {
		if (node == nullptr)
			this->right = nullptr;
		else
		{
			this->right = node;
			node->parent = this;
		}
	}
	
};

class BST {
public:
	Node* root;

	BST():root(nullptr){}
	
	void insert(int data) {
		Node* node = new Node(data);
		if (root == nullptr)
			root = node;
		else {
			Node* par = root;
			Node* cur = root;
			while (cur != nullptr) {
				par = cur;
				if (cur->data > data)
					cur = cur->left;
				else
					cur = cur->right;
			}
			
			if (par->data > data)
				par->setLeft(node);
			else
				par->setRight(node);
		}
	}

	void inorder(Node* node) {
		if (node == nullptr)
			return;
		inorder(node->left);
		inorder(node->right);
		cout << node->data << "\n";
	}
};

int main() {
	int input; 
	BST bst;
	while (cin >> input) {
		bst.insert(input);
	}
	bst.inorder(bst.root);
}