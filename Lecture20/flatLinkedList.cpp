#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* right;
	node* down;

	node(int d) {
		data = d;
		right = NULL;
		down = NULL;
	}
};


void insertDown(node* &head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}

	node* temp = head;
	while (temp-> down != NULL) {
		temp = temp->down;
	}
	temp -> down =  new node(data);
	return;

}

node* merge(node* a, node* b) {
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}

	node* c;
	if (a-> data <= b->data) {
		c = a;
		c->down = merge(a->down, b);
	}
	else {
		c = b;
		c->down = merge(a, b->down);
	}
	return c; 
}

node* flatLinkedList(node* head){
	if(head == NULL || head->right == NULL){
		return head;
	}

	node* c = merge(head, flatLinkedList(head->right));

	return c;

}
void printList(node* head) {
	while (head != NULL) {
		//cout<<(*head).data<<endl;
		cout << head->data << ",";
		head = head -> down;
	} cout << endl;
}


int main(int argc, char const *argv[])
{	

	node* head = NULL;

	insertDown(head, 3);
	insertDown(head, 9);
	insertDown(head, 10);
	insertDown(head, 15);
	insertDown(head->right, 4);
	insertDown(head->right, 14);
	insertDown(head->right, 20);
	insertDown(head->right, 25);
	insertDown(head->right, 35);
	insertDown(head->right->right, 1);
	insertDown(head->right->right, 10);
	insertDown(head->right->right, 12);

	head = flatLinkedList(head);
	printList(head);



	return 0;
}





