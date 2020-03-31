#include <iostream>
using namespace std;


class node
{
public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}

};

node* buildTree() {
	int d;
	cin >> d;

	if (d == -1) {
		return NULL;
	}

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;

}

void print(node* root) { // pre order traversal
	if (root == NULL) {
		return;
	}

	cout << root->data << ", ";
	print(root->left);
	print(root->right);

}

void printInOrder(node* root) { // in order traversal
	if (root == NULL) {
		return;
	}

	printInOrder(root->left);
	cout << root->data << ", ";
	printInOrder(root->right);

}
void printPostOrder(node* root) { // post order traversal
	if (root == NULL) {
		return;
	}

	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->data << ", ";

}

int countNodes(node* root) {
	if (root == NULL) {
		return 0;
	}

	int nodes = 1 + countNodes(root->left) + countNodes(root->right);
	return nodes;
}

int sumNodes(node* root) {
	if (root == NULL) {
		return 0;
	}

	int sum = root->data + sumNodes(root->left) + sumNodes(root->right);
	return sum;
}

int main(int argc, char const *argv[])
{
	node* root = buildTree();
	print(root);
	cout << endl;
	printInOrder(root);
	cout << endl;
	printPostOrder(root);
	cout << endl;

	cout << countNodes(root) << endl;
	cout << sumNodes(root) << endl;
	return 0;
}

//1 2 3 -1 -1 -1 4 5 -1 -1 6 -1 -1





