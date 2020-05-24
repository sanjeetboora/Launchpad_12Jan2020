#include <bits/stdc++.h>
using namespace std;


int Knapsack01Rec(int* wt, int* price, int totalWeight, int n) {
	if (n == 0) {
		return 0;
	}

	int inc = 0, exc = 0;

	int currItemWeight = wt[n - 1];
	int currItemPrice = price[n - 1];
	if ((totalWeight - currItemWeight) >= 0) {
		inc = currItemPrice + Knapsack01Rec(wt, price, totalWeight - currItemWeight, n - 1);
	}
	exc =  Knapsack01Rec(wt, price, totalWeight, n - 1);

	return max(inc, exc);

}

int dp[100][100];
int Knapsack01TopDownDp(int* wt, int* price, int totalWeight, int n) {
	if (n == 0) {
		return 0;
	}
	if (dp[n][totalWeight] != -1) {
		return dp[n][totalWeight];
	}

	int inc = 0, exc = 0;

	int currItemWeight = wt[n - 1];
	int currItemPrice = price[n - 1];
	if ((totalWeight - currItemWeight) >= 0) {
		inc = currItemPrice + Knapsack01TopDownDp(wt, price, totalWeight - currItemWeight, n - 1);
	}
	exc =  Knapsack01TopDownDp(wt, price, totalWeight, n - 1);

	int ans = max(inc, exc);
	dp[n][totalWeight] = ans;

	return ans;

}


int Knapsack01BottomUpDp(int* wt, int* price, int totalWeight, int n) {

	int dp[100][100] = {0};

	if (n == 0) {
		return 0;
	}

	for (int item = 1; item <= n ; ++item)
	{
		for (int w = 1; w <= totalWeight; w++) {
			int inc = 0, exc = 0;

			exc = dp[item - 1][w];

			int currItemWeight = wt[item - 1];
			if (w - currItemWeight >= 0) {
				inc = price[item - 1] + dp[item - 1][w - currItemWeight];
			}

			dp[item][w] = max(inc, exc);

		}
	}

	for (int item = 0; item <= n ; ++item)
	{
		for (int w = 0; w <= totalWeight; w++) {
			cout << dp[item][w] << ", ";
		}
		cout << endl;
	}
	return dp[n][totalWeight];

}


int main(int argc, char const *argv[])
{
	int n = 3;
	int totalWeight = 5;
	int wt[3] = {2, 1, 3};
	int price[3] = {10, 6, 12};

	cout << Knapsack01Rec(wt, price, totalWeight, n) << endl;

	for (int i = 0; i < 100 ; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			dp[i][j] = -1;
		}
	}

	cout << Knapsack01TopDownDp(wt, price, totalWeight, n) << endl;
	cout << Knapsack01BottomUpDp(wt, price, totalWeight, n) << endl;

	return 0;
}