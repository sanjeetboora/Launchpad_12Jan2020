#include <iostream>
using namespace std;


// node

class node{

public:
	int data;
	node* next;

	//constructor
	node(int d){
		data = d;
		next = NULL;
	}
};

void insertAtHead(node* &head, int data){

	//if linked list is empty
	if(head == NULL){
		head = new node(data);
		return;
	}
	//if linked list is not empty

	node* temp = new node(data);
	temp -> next = head;
	head = temp; // new head is temp node now
	return;
}

void insertAtTail(node *&head, int data){
	//if linked list is empty
	if(head == NULL){
		head = new node(data);
		return;
	}
	//if linked list is not empty
	node* temp = head;
	while(temp ->next != NULL){
		temp = temp->next;
	}

	temp -> next = new node(data);
	return;
}

int length(node* head){
	int len =0;

	while(head != NULL){
		len++;
		head = head -> next;
	}
	return len;
}
void printList(node* head){
	while(head != NULL){
		//cout<<(*head).data<<endl;
		cout<<head->data<<endl;
		head = head -> next;
	}
}

int main(int argc, char const *argv[])
{
	node* head = NULL;
	//node head1(5);
	//cout<<head1.data;

	insertAtHead(head,5);
	insertAtTail(head,10);
	insertAtTail(head,15);
	insertAtHead(head,2);

	cout<<length(head)<<endl;
	printList(head);

	return 0;
}


//H.W -> insert at position K
//H.W. -> reverse a linkedlist