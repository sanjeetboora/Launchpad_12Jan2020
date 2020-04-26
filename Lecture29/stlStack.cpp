#include <bits/stdc++.h>
using namespace std;
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