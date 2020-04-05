#include <iostream>
#include <queue>
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
int height(node* root) {
	if (root == NULL) {
		return -1;
	}

	int h = 1 + max(height(root->left), height(root->right));
	return h;

}

void printKthLevel(node* root, int k) {
	if (k == 0) {
		cout << root->data << ", ";
		return;
	}

	if (root->left) {
		printKthLevel(root->left, k - 1);
	}
	if (root->right) {
		printKthLevel(root->right, k - 1);
	}
}

void PrintAllLevels(node* root) {
	int levels = height(root);
	for (int i = 0; i <= levels; ++i)
	{
		printKthLevel(root, i);
		cout << endl;
	}
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


void mirror(node* root) {
	if (root == NULL) {
		return;
	}

	swap(root->left, root->right);
	mirror(root->left);
	mirror(root->right);
}

void LeftViewPrint(node* root) {
	queue<node*> q;

	q.push(root);
	q.push(NULL);
	cout << root->data << ", "; //bcz root will always appear in the left view
	while (q.size() > 1) {
		node* front = q.front();
		if (front == NULL) {
			cout << endl;
			q.pop();
			cout << q.front()->data << ", ";
			q.push(NULL);
		}
		else {
			if (front->left) {
				q.push(front->left);
			}
			if (front->right) {
				q.push(front->right);
			}
			q.pop();
		}

	}

}


void leftView(node* root, int level, int &maxLevel) {
	if (root == NULL) {
		return;
	}

	if (level > maxLevel) {
		maxLevel = level;
		cout << root->data << ", ";
	}

	leftView(root->left, level + 1, maxLevel);
	leftView(root->right, level + 1, maxLevel);
}


class Pair {
public:
	int height;
	bool isBalanced;
};


Pair isHeightBAlanced(node* root) {
	Pair P;
	if (root == NULL) {
		P.height = -1;
		P.isBalanced = true;
		return P;
	}
	Pair left = isHeightBAlanced(root->left);
	Pair right = isHeightBAlanced(root->right);

	P.height = max(left.height, right.height) + 1;

	if (abs(left.height - right.height) <= 1 && left.isBalanced && right.isBalanced) {
		P.isBalanced = true;
	}
	else {
		P.isBalanced = false;
	}
	return P;
}



node* buildHeightBalancedTree(int *arr, int start, int end) {

	if (start > end) {
		return NULL;
	}

	int mid = start + (end - start) / 2;
	node* root = new node(arr[mid]);
	root->left = buildHeightBalancedTree(arr, start, mid - 1);
	root->right = buildHeightBalancedTree(arr, mid + 1, end);

	return root;
}

int i = 0;
node* buildTreeusingPreorderInorder(int* pre, int* inorder, int start, int end) {
	if (start > end) {
		return NULL;
	}

	node* root = new node(pre[i]);

	int idx = -1;
	for (int k = start; k <= end ; k++)
	{
		if (inorder[k] == pre[i]) {
			idx = k;
			break;
		}
	}
	i++;
	root->left = buildTreeusingPreorderInorder(pre, inorder, start, idx - 1);
	root->right = buildTreeusingPreorderInorder(pre, inorder, idx + 1, end);
	return root;

}


int main(int argc, char const *argv[])
{
	//node* root = buildTree();
	//levelOrderWithNextLine(root);
	//cout << endl;
	//mirror(root);
	//levelOrderWithNextLine(root);
	// LeftViewPrint(root);
	// int maxLevel = -1;
	// leftView(root, 0, maxLevel);

	// Pair p = isHeightBAlanced(root);
	// if(p.isBalanced){
	// 	cout<<"tree is height balance"<<endl;
	// }
	// else{
	// 	cout<<"tree is not height balance"<<endl;
	// }
	// cout << endl;
	// int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// node* root1 = buildHeightBalancedTree(arr, 0, 9);
	// levelOrderWithNextLine(root1);
	// cout << endl;

	int pre[9] = {1,2,3,4,5,6,7,8,9};
	int inorder[9] = {3,2,5,4,6,1,7,8,9};
	node* root2 = buildTreeusingPreorderInorder(pre, inorder, 0, 8);
	levelOrderWithNextLine(root2);
	cout << endl;


	return 0;
}

//1 2 3 -1 -1 -1 4 5 -1 -1 6 -1 -1





