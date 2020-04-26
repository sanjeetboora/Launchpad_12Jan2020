#include <bits/stdc++.h>
using namespace std;
bool balancedbracket(string exp) {
	stack<char> st;


	for (int i = 0; i < exp.length(); ++i)
	{
		if (exp[i] == '{' or exp[i] == '[' or exp[i] == '(') {
			st.push(exp[i]);
		}

		else if (exp[i] == '}') {
			if (!st.empty() and st.top() == '{') {
				st.pop();
			}
			else {
				return false;
			}
		}
		else if (exp[i] == ']') {
			if (!st.empty() and st.top() == '[') {
				st.pop();
			}
			else {
				return false;
			}
		}
		else if (exp[i] == ')') {
			if (!st.empty() and st.top() == '(') {
				st.pop();
			}
			else {
				return false;
			}
		}
	}

	return st.empty();
}


int main(int argc, char const *argv[])
{
	// string exp = "{(a+b)* ((c+d)+l)- [h+j]}"; // balanced
	string exp = "}()}"; // balanced

	if (balancedbracket(exp)) {
		cout << exp << "is balanced" << endl;
	}
	else {
		cout << exp << "is not balanced" << endl;
	}



	return 0;
}