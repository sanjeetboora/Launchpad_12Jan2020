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
		if (isEmpty()) {
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


int main(int argc, char const *argv[])
{
	stack<string> st;
	st.push("abc");
	st.push("def");
	st.push("ghi");
	st.push("jkl");
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






