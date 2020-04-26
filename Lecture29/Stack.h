#include <iostream>
#include <vector>
using namespace std;

template<typename P>

class stack {
	vector<P> v;
public:
	bool isEmpty() {
		return v.empty();
	}

	void push(P n) {
		v.push_back(n);
	}
	void pop() {
		if (isEmpty()) { //stack underflow
			cout << "stack is empty" << endl;
			return;
		}
		v.pop_back();
	}

	P top() {
		if (isEmpty()) {
			P temp;
			cout << "stack is empty" << endl;
			return temp;
		}
		return v[v.size() - 1];
	}

};
