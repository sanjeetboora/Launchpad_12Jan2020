#include <bits/stdc++.h>
using namespace  std;

void printMaxKSizeWindow(int*arr, int n, int k) {
	deque<int> dq; // dq is storing indexes

	int i;

//for first k elements
	for ( i = 0; i < k; ++i)
	{
		while (!dq.empty() and arr[dq.back()] <= arr[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}

// i >= k elements (check if deque elements are part of current window or not)

	for (int i = k; i < n; ++i)
	{
		cout << arr[dq.front()] << ", ";
		while (!dq.empty() and arr[dq.back()] <= arr[i]) {
			dq.pop_back();
		}
		while (!dq.empty() and dq.front() <= i - k) {
			dq.pop_front();
		}
		dq.push_back(i);
	}
	cout << arr[dq.front()] << endl;


}


int main(int argc, char const *argv[])
{
	int arr[10] = {10, 1, 8, 0, 6, 9, 15};
	int n = 7;
	int k = 3;
	printMaxKSizeWindow(arr, n, k);

	return 0;
}





