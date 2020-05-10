#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int maxLengthSubarraySumZero(int* arr, int n) {
	unordered_map<int, int> mp;
	int prefixSum = 0, maxLength = 0;
	for (int i = 0; i < n; ++i)
	{
		prefixSum += arr[i];


		// if (arr[i] == 0 and maxLength == 0) {
		// 	maxLength = 1;
		// }

		if (prefixSum == 0 ) {
			maxLength = max(maxLength, i + 1);
		}
		if (mp.count(prefixSum)) {
			int currLength = i - mp[prefixSum];
			maxLength = max(maxLength, currLength);
		}
		else {
			mp[prefixSum] = i;
		}

	}
	return maxLength;
}


int main(int argc, char const *argv[])
{
	int n;
	n = 1;

	//int arr[10] = {3, 2, 4, -2, -2, -5};
	//n = 2;
	//int arr[10] = { -2, -3};
	int arr[10] = {0};

	cout << maxLengthSubarraySumZero(arr, n) << endl;


	return 0;
}