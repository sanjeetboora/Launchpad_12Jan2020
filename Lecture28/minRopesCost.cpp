#include <bits/stdc++.h>
using namespace std;

int minCostToConnectRopes(int* ropes, int n) {
	int totalCost = 0;
	priority_queue<int, vector<int>, greater<int> > pq(ropes, ropes+n);

	while(pq.size()>1){
		int firstRope = pq.top();
		pq.pop();
		int secondRope = pq.top();
		pq.pop();

		int connectionCost = firstRope+secondRope;
		totalCost+=connectionCost;
		pq.push(connectionCost);

		cout<<firstRope<<", "<<secondRope<<" --> "<<connectionCost<<endl;

	}
	return totalCost;
}

int main(int argc, char const *argv[])
{
	int n = 5;

	int ropes[5] = {6, 7, 3, 2, 4};

	int cost = minCostToConnectRopes(ropes, n);

	cout << cost << endl;

	return 0;
}