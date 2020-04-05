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

void levelOrder(node* root) {
	queue<node*> q;

	q.push(root);
	while (q.size() >= 1) {
		node* front = q.front();
		cout << front->data << ", ";

		if (front->left) {
			q.push(front->left);
		}
		if (front->right) {
			q.push(front->right);
		}

		q.pop();
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


int diameter(node* root) {

	if (root == NULL) {
		return 0;
	}

	int ownDiameter = height(root->left) + height(root->right) + 2;
	int leftDiameter = diameter(root->left);
	int rightDiameter =  diameter(root->right);

	return max(ownDiameter, max(leftDiameter, rightDiameter));

}


class Pair {
public:
	int height;
	int diameter;

};

Pair diameterOpt(node* root) {
	Pair P;

	if (root == NULL) {
		P.height = -1;
		P.diameter = 0;
		return P;
	}
	if (root->right == NULL && root->left == NULL) {
		P.height = 0;
		P.diameter = 0;
		return P;
	}


	Pair left = diameterOpt(root->left);
	Pair right = diameterOpt(root->right);

	P.height = max(left.height, right.height) + 1;
	int ownDiameter = left.height + right.height + 2;
	P.diameter = max(ownDiameter, max(left.diameter, right.diameter));

	return P;
}


int replaceWithDescSum(node* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->right == NULL && root->left == NULL) {
		return root->data;
	}

	int leftSum = replaceWithDescSum(root->left);
	int rightSum = replaceWithDescSum(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;

	return temp + root->data;
}



int main(int argc, char const *argv[])
{
	node* root = buildTree();
	print(root);
	cout << endl;
	//printKthLevel(root, 2);
	//cout << endl;
	//cout << height(root) << endl;
	//PrintAllLevels(root);
	//levelOrder(root);
	levelOrderWithNextLine(root);
	cout << endl;
	// cout << diameter(root) << endl;
	// Pair ans = diameterOpt(root);
	// cout << ans.diameter << endl;
	replaceWithDescSum(root);
	levelOrderWithNextLine(root);
	cout << endl;

	return 0;
}

//1 2 3 -1 -1 -1 4 5 -1 -1 6 -1 -1





