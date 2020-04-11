#include <bits/stdc++.h>
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


node* insert(node* root, int d) {
	if (root == NULL) {
		root = new node(d);
		return root;
	}
	if (d <= root->data) {
		root->left = insert(root->left, d);
	}
	else {
		root->right = insert(root->right, d);
	}
	return root;
}

node* buildBST() {
	node* root = NULL;
	int d;
	cin >> d;

	while (d != -1) {
		root = insert(root, d);
		cin >> d;
	}
	return root;
}

node* search(node* root, int key) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == key) {
		return root;
	}

	else if (root->data > key) {
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}

}

node* deleteInBST(node* root, int key) {
	if (root == NULL) {
		return NULL;
	}
	if (key > root->data) {
		root->right = deleteInBST(root->right, key);
	}
	else if (key < root->data) {
		root->left = deleteInBST(root->left, key);
	}
	else { //node found
		//node is leaf node
		if (root->left == NULL and root->right == NULL) {
			delete root;
			return NULL;
		}
		//node has only left child
		else if (root->left != NULL and root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}
		//node has only right child
		else if (root->left == NULL and root->right != NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		//node has both child
		else {
			//replacing node with left subtree's max

			node* temp = root->left;
			while (temp->right) {
				temp = temp->right;
			}
			root->data = temp->data; //temp = max of left subtree
			root->left = deleteInBST(root->left, root->data);
			return root;
		}
	}
	return root;
}

node* min(node* root) {
	if (root == NULL) {
		return NULL;
	}

	if (root->left == NULL) { //leftmost node found
		return root;
	}

	return min(root->left);

}

node* max(node* root) {
	if (root == NULL) {
		return NULL;
	}

	if (root->right == NULL) { //rightmost node found
		return root;
	}

	return max(root->right);
}

void print(node* root) { // pre order traversal
	if (root == NULL) {
		return;
	}

	cout << root->data << ", ";
	print(root->left);
	print(root->right);

}

bool isBST(node* root, int minimum, int maximum) {
	if (root == NULL) {
		return true;
	}

	if(root->data >= minimum and root->data < maximum and 
		isBST(root->left, minimum, root->data) and isBST(root->right, root->data, maximum)){
		return true;
	}
	return false;

}
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


class nodeHelper
{
public:
	bool isBST;
	int maximum;
	int minimum;
	int size;

	nodeHelper(){
		isBST = true;
		maximum = INT_MIN;
		minimum = INT_MAX;
		size = 0;
	}
	
};



nodeHelper largestBSTinBT(node* root){
	if(root == NULL){
		return nodeHelper();
	}

	nodeHelper leftTree = largestBSTinBT(root->left);
	nodeHelper rightTree = largestBSTinBT(root->right);
	nodeHelper curr;
	if(leftTree.maximum <= root->data and rightTree.minimum > root->data
		and leftTree.isBST and rightTree.isBST){
		curr.isBST = true;
		curr.maximum = max(rightTree.maximum, root->data);
		curr.minimum = min(leftTree.minimum, root->data);
		curr.size = leftTree.size + rightTree.size + 1;
	}
	else{ //when curr tree is not a bst
		curr.isBST = false;
		curr.size = max(leftTree.size, rightTree.size);
	}
	return curr;
}


int main(int argc, char const *argv[])
{
	//node* root = buildBST();
	//print(root);
	//cout << endl;
	// int key;
	// cin >> key;
	// node* temp = search(root, key);
	// if (temp) {
	// 	cout << key << " found" << endl;
	// }
	// else {
	// 	cout << key << " not found" << endl;
	// }
	// root = deleteInBST(root, key);
	// print(root);
	// node* minimum = min(root);
	// if (minimum) {
	// 	cout << "minimum " << minimum->data << endl;
	// }
	// node * maximum = max(root);
	// if (maximum) {
	// 	cout << "maximum " << maximum->data << endl;
	// }
	node* root2 = buildTree();
	// bool bst = isBST(root2, INT_MIN, INT_MAX);
	// if(bst){
	// 	cout<<"tree is a bst"<<endl;
	// }
	// else{
	// 	cout<<"tree is not a bst"<<endl;
	// }
	// cout << endl;
	nodeHelper nh = largestBSTinBT(root2);
	cout<<nh.size<<endl;

	return 0;
}