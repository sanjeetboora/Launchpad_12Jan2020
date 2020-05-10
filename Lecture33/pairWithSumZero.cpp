#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool isPairSumZero(int* arr, int n) {
	unordered_map<int, int> mp;

	for (int i = 0; i < n; ++i)
	{
		int toGet = -1 * arr[i];
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

	int arr[10] = {3, 2, 4, -1, -5, 9};

	if (isPairSumZero(arr, n)) {
		cout << "pair with sum zero exist" << endl;
	}
	else {
		cout << "pair with sum zero doesn't exist" << endl;
	}

	return 0;
}