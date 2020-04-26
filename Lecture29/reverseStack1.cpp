#include <bits/stdc++.h>
using namespace std;

void reverse(stack<string> &stA) {

	stack<string> stB;
	stack<string> stC;

	// transfer stack A to stack B
	while (! stA.empty()) {
		stB.push(stA.top());
		stA.pop();
	}


	// transfer stack B to stack C
	while (! stB.empty()) {
		stC.push(stB.top());
		stB.pop();
	}


	// transfer stack C to stack A
	while (! stC.empty()) {
		stA.push(stC.top());
		stC.pop();
	}
}


int main(int argc, char const *argv[])
{
	stack<string> st;
	st.push("abc");
	st.push("def");
	st.push("ghi");
	st.push("jkl");

	reverse(st);

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

