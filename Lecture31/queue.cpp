#include <iostream>
using namespace  std;

class queue {
	int *arr;
	int rear;
	int front;
	int currSize;
	int totalSize;

public:
	queue(int defaultSize = 5) {
		totalSize = defaultSize;
		arr = new int[totalSize];
		front = 0;
		rear = -1;
		//rear = totalSize - 1; //last index of array
	}

	bool isEmpty() {
		return currSize == 0;
	}

	bool isFull() {
		return currSize == totalSize;
	}

	void push(int num) {
		if (isFull()) {
			cout << "queue is full" << endl;
			return;
		}

		rear = (rear + 1) % totalSize;
		arr[rear] = num;
		currSize++;

	}
	void pop() {
		if (isEmpty()) {
			cout << "queue is empty" << endl;
			return;
		}
		front = (front + 1) % totalSize;
		currSize--;
	}

	int getFront() {
		if (isEmpty()) {
			cout << "queue is empty" << endl;
			return -1;
		}
		return arr[front];
	}


};

int main(int argc, char const *argv[])
{
	queue q(7);

	for (int i = 10; i > 3; i--)
	{
		q.push(i);
	}

	while (!q.isEmpty()) {
		cout << q.getFront() << ", ";
		q.pop();
	}
	cout << q.getFront() << ", ";
	q.pop();


	return 0;
}







