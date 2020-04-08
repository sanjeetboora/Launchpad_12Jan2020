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


bool areTreesIdentical(node* A, node* B) {
	if (A == NULL && B == NULL) {
		return true;
	}

	if (A != NULL && B != NULL) {
		bool leftSubTree = areTreesIdentical(A->left, B->left);
		bool rightSubTree = areTreesIdentical(A->right, B->right);
		if (A->data == B->data && leftSubTree && rightSubTree) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool areTreesStructurallyIdentical(node* A, node* B) {
	if (A == NULL && B == NULL) {
		return true;
	}

	if (A != NULL && B != NULL) {
		bool leftSubTree = areTreesStructurallyIdentical(A->left, B->left);
		bool rightSubTree = areTreesStructurallyIdentical(A->right, B->right);
		return leftSubTree and rightSubTree;
	}
	return false;
}

void printNodesAtDistanceKInSubtree(node* root, int K) {
	if (root == NULL || K < 0) {
		return;
	}

	if (K == 0) {
		cout << root->data << ", ";
		return;
	}

	printNodesAtDistanceKInSubtree(root->left, K - 1);
	printNodesAtDistanceKInSubtree(root->right, K - 1);
}


int printNodesAtDistanceK(node* root, int target, int K) {
	if (root == NULL) {
		return -1;
	}

	if (root->data == target) { // to print the nodes in subtrees of target node
		printNodesAtDistanceKInSubtree(root, K);
		return 0;
	}

	int dLeft = printNodesAtDistanceK(root->left, target, K);
	if (dLeft != -1) {
		if (dLeft + 1 == K) {
			cout << root->data << ", ";
		}
		else {
			printNodesAtDistanceKInSubtree(root->right, K - dLeft - 2);
		}
		return dLeft + 1; //distance of current node from target node
	}
	int dRight = printNodesAtDistanceK(root->right, target, K);
	if (dRight != -1) {
		if (dRight + 1 == K) {
			cout << root->data << ", ";
		}
		else {
			printNodesAtDistanceKInSubtree(root->left, K - dRight - 2);
		}
		return dRight + 1; //distance of current node from target node
	}

	return -1;
}

int minDepth(node* root) {

	if (root == NULL) {
		return 0;
	}

	if (root->left == NULL && root->right == NULL) {
		return 0;
	}

	int leftMin=0, rightMin=0;
	if (root->left) {
		leftMin =  minDepth(root->left);
	}
	if (root->right) {
		rightMin =  minDepth(root->right);
	}

	return min(leftMin, rightMin) + 1;

}

//H.W -> min depth by level order


node* lca(node* root, int A, int B){
	if(root == NULL){
		return NULL;
	}
	if(root->data == A or root->data == B){
		return root;
	}

	node* LeftLCA = lca(root->left, A, B);
	node* RightLCA = lca(root->right, A, B);

	if(LeftLCA != NULL && RightLCA!= NULL){
		return root;
	}

	else if(LeftLCA != NULL){
		return LeftLCA;
	}

	else{
		return RightLCA;
	}

}



int main(int argc, char const *argv[])
{
	node* root1 = buildTree();
	//node* root2 = buildTree();
	levelOrderWithNextLine(root1);
	// cout<<endl;
	// levelOrderWithNextLine(root2);
	// cout << endl;
	// if(areTreesIdentical(root1, root2)){
	// 	cout<<"trees are Identical"<<endl;
	// }
	// else{
	// 	cout<<"trees are not Identical"<<endl;
	// }

	// if(areTreesStructurallyIdentical(root1, root2)){
	// 	cout<<"trees are Identical"<<endl;
	// }
	// else{
	// 	cout<<"trees are not Identical"<<endl;
	// }
	//printNodesAtDistanceK(root1, 4, 2);
	//cout<<minDepth(root1)<<endl;
	node* ancestor = lca(root1, 4,6);
	cout<<ancestor->data<<endl;

	return 0;
}

//1 2 3 -1 -1 -1 4 5 -1 -1 6 -1 -1





