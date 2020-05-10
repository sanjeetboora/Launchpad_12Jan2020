#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool isPairSumK(int* arr, int n, int k) {
	unordered_map<int, int> mp;

	for (int i = 0; i < n; ++i)
	{
		int toGet = k - arr[i];
		if (mp.count(toGet)) {
			cout << arr[i] << ", " << toGet << endl;
			return true;
		}
		else {
			mp[arr[i]] = i;
		}
	}
	return false;

}


int main(int argc, char const *argv[])
{
	int n;
	n = 6;
	int k = -3;
	int arr[10] = {3, 2, -4, -1, -2, 5};

	if (isPairSumK(arr, n, k)) {
		cout << "pair with sum " << k << " exist" << endl;
	}
	else {
		cout << "pair with sum  " << k << "  doesn't exist" << endl;
	}

	return 0;
}