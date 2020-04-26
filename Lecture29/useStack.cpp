#include "Stack.h"
using namespace std;

int main(int argc, char const *argv[])
{

	// int arr[10] = {1, 2, 3, 4, 5, 6};
	// for (auto i : arr) { //for each loop
	// 	cout << i << endl;
	// }

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