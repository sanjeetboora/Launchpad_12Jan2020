#include <bits/stdc++.h>
using namespace std;

int getPrecedence(char ch) {
	if (ch == '^') {
		return 3;
	}
	else if (ch == '*' or ch == '/') {
		return 2;
	}
	else if (ch == '+' or ch == '-') {
		return 1;
	}
	else if (ch == '(' or ch == ')') {
		return 0;
	}
	return -1;
}

string infixToPostfix(string infix) {
	string postfix;
	stack<char> st;
	for (int i = 0; i < infix.length(); ++i)
	{
		char ch = infix[i];
		int prec = getPrecedence(ch);

		if (prec == -1) { // ch is an operand
			postfix += ch;
		}
		else { // ch is an operator or bracket

			if (ch == '(') {
				st.push(ch);
			}
			else if (ch == ')') {
				while (!st.empty() and st.top() != '(') {
					postfix += st.top();
					st.pop();
				}
				st.pop(); // to pop '('
			}
			else { //ch is an operator
				while (!st.empty() and getPrecedence(st.top()) >= getPrecedence(ch) and st.top() != '(') {
					postfix += st.top();
					st.pop();
				}
				st.push(ch);

			}

		}

	}
	while (!st.empty()) {
		postfix += st.top();
		st.pop();
	}
	return postfix;

}



int main(int argc, char const *argv[])
{
	string infix = "((A+B)*(C-D))/E";
	cout << infixToPostfix(infix) << endl;

	return 0;
}