#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > minHeapRight;
priority_queue<int> maxHeapLeft;

void addElement(int num) {

	if ( !minHeapRight.empty() and num > minHeapRight.top()) {
		minHeapRight.push(num);
	}
	else {
		maxHeapLeft.push(num);
	}

	// to balance size
	//heap size -> unsigned long long int
	//float absolute -> fabs

	if (llabs(minHeapRight.size() - maxHeapLeft.size()) > 1) {
		if (maxHeapLeft.size() > minHeapRight.size()) {
			minHeapRight.push(maxHeapLeft.top());
			maxHeapLeft.pop();
		}
		else {
			maxHeapLeft.push(minHeapRight.top());
			minHeapRight.pop();
		}
	}
}

float getMedian() {
	if (maxHeapLeft.size() > minHeapRight.size()) {
		return maxHeapLeft.top();
	}
	else if (maxHeapLeft.size() < minHeapRight.size()) {
		return minHeapRight.top();
	}
	else {
		return (maxHeapLeft.top() + minHeapRight.top()) / 2.0;
	}
}



int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	while (n != 0) {
		if ( n != -1) {
			addElement(n);
		}
		else {
			float median = getMedian();
			cout << median << endl;
		}
		cin >> n;
	}

	// int a = 6;
	// cout<<typeid(a).name()<<endl;


	return 0;
}