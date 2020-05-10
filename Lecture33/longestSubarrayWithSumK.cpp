#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int maxLengthSubarraySumK(int* arr, int n, int k) {
	unordered_map<int, int> mp;
	int prefixSum = 0, maxLength = 0;
	for (int i = 0; i < n; ++i)
	{
		prefixSum += arr[i];

		if (prefixSum == k ) {
			maxLength = max(maxLength, i + 1);
		}
		if (mp.count(prefixSum - k)) {
			int currLength = i - mp[prefixSum - k];
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
	n = 6;
	int k = 2;
	int arr[10] = {3, 2, 4, -2, -2, -5};
	//n = 2;
	//int arr[10] = { -2, -3};
	//int arr[10] = {0};

	cout << maxLengthSubarraySumK(arr, n, k) << endl;


	return 0;
}