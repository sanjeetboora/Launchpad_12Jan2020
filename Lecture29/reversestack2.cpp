#include <bits/stdc++.h>
using namespace std;

void transferElements(stack<string> &temp1, stack<string> &temp2, int num) {

	for (int i = 0; i < num; ++i)
	{
		temp2.push(temp1.top());
		temp1.pop();
	}
}

void reverse(stack<string> &stA) {

	stack<string> stB;
	int sz = stA.size();

	for (int correctPosition = 0; correctPosition < sz; ++correctPosition)
	{
		string currElement = stA.top();
		stA.pop();

		transferElements(stA, stB, sz - correctPosition - 1);

		stA.push(currElement);

		transferElements(stB, stA, sz - correctPosition - 1);
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

