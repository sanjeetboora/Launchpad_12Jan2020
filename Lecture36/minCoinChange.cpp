#include <bits/stdc++.h>
using namespace std;

int minCoinsRec(int money, int* coins, int n) {
	if (money == 0) {
		return 0;
	}

	int ans = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		if (money - coins[i] >= 0) {
			int count = 1 + minCoinsRec(money - coins[i], coins, n);
			ans = min(ans, count);
		}
	}
	return ans;
}

int minCoinsTopDown(int money, int* coins, int n, int* dp) {
	if (money == 0) {
		return 0;
	}

	if (dp[money] != 0) {
		return dp[money];
	}

	int ans = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		if (money - coins[i] >= 0) {
			int count = 1 + minCoinsRec(money - coins[i], coins, n);
			ans = min(ans, count);
		}
	}
	dp[money] = ans;
	return ans;
}


int minCoinsBottomUp(int money, int* coins, int n) {
	int dp[1000] = {0};

	for (int i = 1; i <= money; ++i)
	{
		dp[i] = INT_MAX;

		for (int coin = 0; coin < n ; ++coin)
		{
			if (i - coins[coin] >= 0) {
				int reqCoins = 1 + dp[i - coins[coin]];
				dp[i] = min(dp[i], reqCoins);
			}
		}
	}

	for (int i = 0; i <= money; ++i)
	{
		cout << dp[i] << ", ";
	}
	cout << endl;
	return dp[money];
}




int main(int argc, char const *argv[])
{
	int coins[10] = {10, 1, 6};
	int n = 3;
	int money = 199;
	//cout << minCoinsRec(money, coins, n) << endl;
	int dp[1000] = {0};
	//cout << minCoinsTopDown(money, coins, n, dp) << endl;
	cout << minCoinsBottomUp(money, coins, n) << endl;

	return 0;
}