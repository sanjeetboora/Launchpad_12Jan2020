#include <iostream>
#include <vector>
using namespace std;


class stack {
	vector<int> v;
public:
	bool isEmpty() {
		return v.empty();
	}

	void push(int n) {
		v.push_back(n);
	}
	void pop() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return;
		}
		v.pop_back();
	}

	int top() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return 0;
		}
		return v[v.size() - 1];
	}

};


int main(int argc, char const *argv[])
{
	stack st;
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();

	return 0;
}






