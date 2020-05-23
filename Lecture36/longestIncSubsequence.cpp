#include <bits/stdc++.h>
using namespace std;

int lis(int* arr, int n) {
	int dp[1000];
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
	}

	int maxLength = 0;
	for (int i = 1; i < n ; ++i)
	{
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxLength = max(maxLength, dp[i]);
	}


	for (int i = 0; i < n; ++i)
	{
		cout << dp[i] << ",";
	}
	cout << endl;

	return maxLength;
}


int lisOptimized(int* arr, int n) {
	vector<int> v;

	v.push_back(arr[0]);

	for (int i = 1; i < n ; ++i)
	{
		int currEle = arr[i];

		auto idx = lower_bound(v.begin(), v.end(), currEle);

		if (idx == v.end()) {
			v.push_back(currEle);
		}
		else {
			*idx = currEle;
		}
	}

	return v.size();

}



int main(int argc, char const *argv[])
{
	int arr[10] = {30, 3, 10, 4, 15, 30, 8};
	int n = 7;
	cout << lis(arr, n) << endl;
	cout << lisOptimized(arr, n) << endl;
	return 0;
}











