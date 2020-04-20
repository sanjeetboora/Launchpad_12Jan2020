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



void print(node* root) { // pre order traversal
	if (root == NULL) {
		return;
	}

	cout << root->data << ", ";
	print(root->left);
	print(root->right);

}



void levelOrderWithNextLine(node* root) {
	queue<node*> q;

	q.push(root);
	q.push(NULL);
	while (q.size() > 1) {
		node* front = q.front();
		if (front == NULL) {
			cout << endl;
			q.push(NULL);
		}
		else {
			cout << front->data << ", ";

			if (front->left) {
				q.push(front->left);
			}
			if (front->right) {
				q.push(front->right);
			}
		}
		q.pop();
	}

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

class LinkedList {
public:
	node* head;
	node* tail;
};


LinkedList flatBST(node* root) {
	LinkedList ans;
	if (root == NULL) {
		ans.head = ans.tail = NULL;
		return ans;
	}

	else if (root->left == NULL and root->right == NULL) { //leaf node
		ans.head = ans.tail = root;
		return ans;
	}

	else if (root->left != NULL and root->right == NULL) {
		LinkedList leftLL = flatBST(root->left);

		leftLL.tail->right = root;
		ans.head = leftLL.head;
		ans.tail =  root;
		return ans;
	}

	else if (root->left == NULL and root->right != NULL) {
		LinkedList rightLL = flatBST(root->right);

		root->right = rightLL.head;
		ans.head = root;
		ans.tail = rightLL.tail;
		return ans;
	}

	else if (root->left != NULL and root->right != NULL) {
		LinkedList leftLL = flatBST(root->left);
		LinkedList rightLL = flatBST(root->right);

		leftLL.tail->right = root;
		root->right = rightLL.head;

		ans.head = leftLL.head;
		ans.tail = rightLL.tail;
		return ans;
	}

}

void swap(node* a, node* b) {
	node* temp = new node(a->data);
	a->data = b->data;
	b->data = temp->data;
}

node* pred = NULL;
node* A = NULL;
node* B = NULL;

void swappedTree(node* root) {
	if (root == NULL) {
		return;
	}

	//inorder traversal

	swappedTree(root->left);
	if (pred != NULL and root->data < pred->data) {
		B = root;
		if (A == NULL) {
			A = pred;
		}
		else {
			return;
		}
	}

	pred = root;
	swappedTree(root->right);
}

void recoverActualBST(node* root) {
	if (root == NULL) {
		return;
	}
	swappedTree(root);
	swap(A, B);

}


node* inorderSuccessor(node* root, int d) {
	node* target = search(root, d);
	if (target == NULL) {
		return NULL;
	}
	else { //target node found
		//right child of target node exits
		if (target->right != NULL) {
			node* rightSubTree = target->right;
			while (rightSubTree->left) {
				rightSubTree = rightSubTree->left;
			}
			return rightSubTree;
		}
		else {
			//right child of target node doesn't exits
			node* ancestor = NULL;
			node* successor = root;
			while (successor != target) {

				if (successor->data > target->data) {
					ancestor = successor;
					successor = successor->left;
				}
				else{
					successor = successor->right;
				}

			}
			return ancestor;
		}

	}

}


int numberOfBST(int N){
	if(N==0){
		return 1;
	}

	int totalBSTs = 0;
	for (int i = 1; i <= N ; ++i)
	{
		totalBSTs += numberOfBST(i-1)* numberOfBST(N-i);
	}
	return totalBSTs;
}




int main(int argc, char const *argv[])
{
	node* root = buildBST();
//	node* root = buildTree();
	levelOrderWithNextLine(root);
	cout << endl;
	// LinkedList ll = flatBST(root);
	// node* l = ll.head;
	// while (l) {
	// 	cout << l->data << ", ";
	// 	l = l->right;
	// }
	// cout << endl;

	// recoverActualBST(root);
	node* is = inorderSuccessor(root, 6);
	cout<<"inorderSuccessor - "<<is->data<<endl;
	levelOrderWithNextLine(root);
	cout << endl;
	cout<<(numberOfBST(3))<<endl;

	return 0;
}

//HW
//Find K closest nodes to a given target node
//Find inorder predecessor for a given target node
//Given two binary search trees root1 and root2. Return a list containing all the integers from both trees sorted in ascending order.



