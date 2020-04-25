#include <bits/stdc++.h>
using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int> > pq){
	while( !pq.empty()){
		cout<<pq.top()<<", ";
		pq.pop();
	}
	cout<<endl;
}

void topKelements(int K) {
	priority_queue<int, vector<int>, greater<int> > pq; // min heap

	int n;
	cin >> n;
	// while(scanf("%d", &n) != EOF){

	// }

	int currSize = 0;
	while (n != -1000) {
		if (n != -1) {

			if (currSize < K) {
				pq.push(n);
				currSize++;
			}
			else if (pq.top() < n) {
				pq.pop();
				pq.push(n);
			}

		}
		else {
			printHeap(pq);
		}

		cin>>n;
	}


}


int main(int argc, char const *argv[])
{
	int k;
	cin >> k;

	topKelements(k);

}
