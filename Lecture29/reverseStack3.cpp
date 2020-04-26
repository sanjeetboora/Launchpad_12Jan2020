#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<string> &st, string curr) {
	if (st.empty()) {
		st.push(curr);
		return;
	}

	string topEle = st.top();
	st.pop();

	insertAtBottom(st, curr);

	st.push(topEle);
}


void reverse(stack<string> &st) {

	if (st.empty()) {
		return;
	}

	string topEle = st.top();
	st.pop();
	reverse(st);
	insertAtBottom(st, topEle);
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