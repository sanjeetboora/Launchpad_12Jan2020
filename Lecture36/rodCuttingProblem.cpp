#include <bits/stdc++.h>
using namespace std;


int rodCuttingRec(int n, int* prices) {
	if (n == 0) {
		return 0;
	}

	int totalProfit = 0;

	for (int i = 1; i <= n; ++i)
	{
		int currProfit = prices[i] + rodCuttingRec(n - i, prices);
		totalProfit = max(totalProfit, currProfit);
	}
	return totalProfit;
}

int rodCuttingTopDownDP(int n, int* prices, int* dp) {
	if (n == 0) {
		return 0;
	}

	if (dp[n] != 0) {
		return dp[n];
	}

	int totalProfit = 0;

	for (int i = 1; i <= n; ++i)
	{
		int currProfit = prices[i] + rodCuttingTopDownDP(n - i, prices, dp);
		totalProfit = max(totalProfit, currProfit);
	}
	dp[n] = totalProfit;
	return dp[n];
}

int rodCuttingBottomUp(int n, int* prices) {

	int dp[100] = {0};

	for (int len = 1; len <= n ; ++len)
	{
		int currProfit = 0;
		for (int cut = 1; cut <= len; cut++)
		{
			currProfit = max(currProfit, prices[cut] + dp[len - cut]);
		}
		dp[len] = currProfit;
	}
	return dp[n];
}





int main(int argc, char const *argv[])
{
	int n = 8;
	int prices[9] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
	cout << rodCuttingRec(n, prices) << endl;
	int dp[100] = {0};
	cout << rodCuttingTopDownDP(n, prices, dp) << endl;
	cout << rodCuttingBottomUp(n, prices) << endl;

	return 0;
}







