#include <iostream>
#include <vector>
using namespace std;


class stack {
	vector<int> v;
	int minimum;
public:
	bool isEmpty() {
		return v.empty();
	}

	void push(int n) {

		if (isEmpty()) {
			v.push_back(n);
			minimum = n;
		}
		else if (n < minimum) {
			v.push_back(2 * n - minimum);
			minimum = n;
		}
		else {
			v.push_back(n);
		}
	}
	void pop() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return;
		}
		int topElement = v[v.size() - 1];
		int oldMin;
		if (topElement < minimum) {
			oldMin = 2 * minimum - topElement;
			minimum = oldMin;
		}
		v.pop_back();
	}


	int top() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return 0;
		}
		int t =  v[v.size() - 1];
		if (t < minimum) {
			t = minimum;
		}
		return t;
	}

	int getMin() {
		return minimum;
	}

};


int main(int argc, char const *argv[])
{
	stack st;
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(1);
	st.push(5);
	st.push(-1);
	st.push(6);
	while (!st.isEmpty()) {
		cout << "minimum -> " << st.getMin() << ", top -> " << st.top() << endl;
		st.pop();
	}



	return 0;
}






