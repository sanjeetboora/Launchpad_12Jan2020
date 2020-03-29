#include <iostream>
using namespace std;

class node {
public:
	int data;
	node *next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

bool detectLoop(node* head) {
	node* slow = head;
	node* fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next ->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
}

node* detectCycle(node* head) {
	node* slow = head;
	node* fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next ->next;
		if (slow == fast) {
			return slow;
		}
	}
	return NULL;
}



void removeCycle(node* head, node* meetPoint){

	node* A = head;
	node* prev = NULL; // to remove the cycle

	while(A != meetPoint){
		A = A->next;
		prev = meetPoint;
		meetPoint = meetPoint->next;
	}
	prev->next = NULL; //cycle break

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

int main(int argc, char const *argv[])
{	
	node* head = NULL;
	cin>>head;
	cout<<head;
	// if(detectLoop(head)){
	// 	cout<<"loop detected"<<endl;
	// }
	// else{
	// 	cout<<"loop not  detected"<<endl;
	// }

	// head->next->next->next->next = head->next;
	
	// if(detectLoop(head)){
	// 	cout<<"loop detected"<<endl;
	// }
	// else{
	// 	cout<<"loop not  detected"<<endl;
	// }

	head->next->next->next->next = head->next;
	removeCycle(head, detectCycle(head));
	cout<<head<<endl;


	return 0;
}

