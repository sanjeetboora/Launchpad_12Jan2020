#include <iostream>
using namespace std;


// node

class node {

public:
	int data;
	node* next;

	//constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertAtHead(node* &head, int data) {

	//if linked list is empty
	if (head == NULL) {
		head = new node(data);
		return;
	}
	//if linked list is not empty

	node* temp = new node(data);
	temp -> next = head;
	head = temp; // new head is temp node now
	return;
}

void insertAtTail(node *&head, int data) {
	//if linked list is empty
	if (head == NULL) {
		head = new node(data);
		return;
	}
	//if linked list is not empty
	node* temp = head;
	while (temp ->next != NULL) {
		temp = temp->next;
	}

	temp -> next = new node(data);
	return;
}

int length(node* head) {
	int len = 0;

	while (head != NULL) {
		len++;
		head = head -> next;
	}
	return len;
}
void insertAtPositionK(node *&head, int d, int K) {

	if (K == 1) {
		insertAtHead(head, d);
		return;
	}
	else if (K > length(head)) {
		insertAtTail(head, d);
		return;
	}
	else {
		int pos = 1;
		node* temp = head;
		while (pos < K - 1) {
			pos++;
			temp = temp->next;
		}
		node* newnode = new node(d);
		newnode -> next = temp->next;
		temp->next = newnode;
		return;
	}

}

void deleteAtHead(node* &head) {
	if (head == NULL) { //linked list is empty
		return;
	}

	node* oldHead = head;
	head = head->next;
	delete oldHead;
	return;
}

void deleteAtTail(node* &head) {
	if (head == NULL || head->next == NULL) { //either list is empty or of size 1
		deleteAtHead(head);
		return;
	}

	node* temp = head;

	while (temp->next->next != NULL) { // till 2nd Last node
		temp = temp->next;
	}

	delete temp->next; //delete last node;
	temp->next = NULL;
	return;

}

void deleteKthNode(node*&head, int K) {
	if (K == 1 || head == NULL || head->next == NULL) {
		deleteAtHead(head);
		return;
	}
	else if (K >= length(head)) {
		deleteAtTail(head);
		return;
	}

	else {
		int pos = 1;
		node* temp = head;
		while (pos < K - 1) {
			pos++;
			temp = temp->next;
		}

		node* toBeDeleted = temp -> next;
		temp->next = temp->next->next;
		delete toBeDeleted;
		return;
	}

}

void buildLinkedList(node* &head) {
	int d;
	cin >> d;

	while (d != -1) {
		insertAtTail(head, d);
		cin >> d;
	}
}

void printList(node* head) {
	while (head != NULL) {
		//cout<<(*head).data<<endl;
		cout << head->data << ",";
		head = head -> next;
	} cout << endl;
}


istream& operator >>(istream &is, node* &head) {
	buildLinkedList(head);
	return is;
}

ostream& operator <<(ostream &os, node* &head) {
	printList(head);
	return os;
}
bool searchItertive(node* head, int key) {

	while (head != NULL) {
		if (head->data == key) {
			return true;
		}
		head = head->next;
	}
	return false;
}

bool searchRecursive(node* head, int key) {
	if (head == NULL) { //base case
		return false;
	}
	//self work
	if (head->data == key) {
		return true;
	}
	else {
		return searchRecursive(head->next, key);
	}
}


node* mid(node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	node* slow = head;
	node* fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}


void reverseIterative(node* &head) {
	node* prev = NULL;
	node* curr = head;
	node* nextNode;

	while (curr != NULL) {
		nextNode = curr -> next;
		curr -> next = prev; // current->next pointer reversed

		prev = curr;
		curr = nextNode;
	}
	head = prev; //bcz prev is last node
}


int main(int argc, char const *argv[])
{
	node* head = NULL;
	//node head1(5);
	//cout<<head1.data;

	// insertAtHead(head, 5);
	// insertAtTail(head, 10);
	// insertAtTail(head, 15);
	// insertAtHead(head, 2);

	// cout << length(head) << endl;
	// printList(head);
	// insertAtPositionK(head, 7, 3);
	// printList(head);

	// deleteAtHead(head);
	// printList(head);
	// deleteAtTail(head);
	// printList(head);
	// deleteKthNode(head, 2);
	// printList(head);

	// buildLinkedList(head);
	// printList(head);
	node* head2 = NULL;

	cin >> head >> head2;
	cout << head << head2 << endl;

	// cout << searchItertive(head, 2) << endl;
	// cout << searchRecursive(head, 2) << endl;
	// cout << mid(head)->data << endl;
	// cout << mid(head2)->data << endl;
	reverseIterative(head);
	reverseIterative(head2);
	cout << head << head2 << endl;


	return 0;
}



//reverse recursive
//print kth node from last -> 1,2,3,4,5 => k=2, output = 4
//linked list  -> merge sort
