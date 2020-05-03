#include <bits/stdc++.h>
using namespace  std;


int main(int argc, char const *argv[])
{

	// queue<string> q;

	// q.push("abc1");
	// q.push("abc2");
	// q.push("abc3");
	// q.push("abc4");

	// cout << q.front() << ", ";
	// q.pop();
	// cout << q.front() << ", ";
	// q.pop();
	// cout << q.front() << ", ";
	// q.pop();
	// cout << q.front() << ", ";
	// q.pop();
	// cout << q.front() << ", ";
	// q.pop();


	//deque -> double ended queue
	deque<string> dq;
	dq.push_back("abc");
	dq.push_back("def");
	dq.push_front("ghi");
	dq.push_front("jkl");

	for (string str : dq) {
		cout << str << ", ";
	}
	cout << endl;

	dq.pop_back();
	dq.pop_front();

	for (string str : dq) {
		cout << str << ", ";
	}
	cout << endl;




	return 0;
}











