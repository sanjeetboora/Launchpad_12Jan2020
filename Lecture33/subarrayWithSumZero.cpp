#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool isSubarraySumZero(int* arr, int n) {
	unordered_map<int, int> mp;
	int prefixSum = 0;
	for (int i = 0; i < n; ++i)
	{
		prefixSum += arr[i];

		if (prefixSum == 0 || mp.count(prefixSum)) {
			return true;
		}
		else {
			mp[prefixSum] = i;
		}
	}
	return false;

}


int main(int argc, char const *argv[])
{
	int n;
	//n = 6;

	//int arr[10] = {3, 2, 4, -2, -2, -5};
	n = 2;
	int arr[10] = { -2, -3};

	if (isSubarraySumZero(arr, n)) {
		cout << "subarray with sum zero exist" << endl;
	}
	else {
		cout << "subarray with sum zero doesn't exist" << endl;
	}

	return 0;
}