#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//priority_queue<int> pq; //by default makes a max heap

	priority_queue<int, vector<int>, greater<int> > pq; // min heap

	pq.push(10);
	pq.push(20);
	pq.push(100);
	pq.push(110);
	pq.push(2310);
	cout<<"size "<<pq.size()<<endl;
	cout<<pq.top()<<endl;
	pq.pop();
	cout<<pq.top()<<endl;
	pq.pop();
	cout<<pq.top()<<endl;
	pq.pop();
	cout<<pq.top()<<endl;
	pq.pop();
	cout<<pq.top()<<endl;
	pq.pop();
	cout<<pq.empty()<<endl;


	return 0;
}