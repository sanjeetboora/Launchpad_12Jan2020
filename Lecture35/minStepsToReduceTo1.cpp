#include <bits/stdc++.h>
using namespace std;

int minStepsToOneRecursive(int n) {
	if (n == 1) {
		return 0;
	}
	int div3 = INT_MAX, div2 = INT_MAX, sub1 = INT_MAX;
	if (n % 3 == 0) div3 = minStepsToOneRecursive(n / 3);
	if (n % 2 == 0) div2 = minStepsToOneRecursive(n / 2);
	sub1  = minStepsToOneRecursive(n - 1);

	int minSteps = 1 + min(div3, min(div2, sub1));
	return minSteps;
}


int minStepsToOneTopDownDP(int n, int* dp) {
	if (n == 1) {
		return 0;
	}

	if (dp[n] != 0) {
		return dp[n];
	}

	int div3 = INT_MAX, div2 = INT_MAX, sub1 = INT_MAX;
	if (n % 3 == 0) div3 = minStepsToOneTopDownDP(n / 3, dp);
	if (n % 2 == 0) div2 = minStepsToOneTopDownDP(n / 2, dp);
	sub1  = minStepsToOneTopDownDP(n - 1, dp);

	int minSteps = 1 + min(div3, min(div2, sub1));
	dp[n] = minSteps;

	return dp[n];
}

int minStepsToOneBottomUpDP(int n) {
	int dp[100] = {0};

	dp[1] = 0; dp[2] = 1; dp[3] = 1;


	for (int i = 4; i <= n; ++i)
	{
		int div3 = INT_MAX, div2 = INT_MAX, sub1 = INT_MAX;
		if (i % 3 == 0) div3 = dp[i / 3];
		if (i % 2 == 0) div2 = dp[i / 2];
		sub1  = dp[i - 1];

		dp[i] =  1 + min(div3, min(div2, sub1));
	}
	return dp[n];
}



int main(int argc, char const *argv[])
{
	int n = 10;
	cout << minStepsToOneRecursive(n) << endl;

	int dp[100] = {0};
	cout << minStepsToOneTopDownDP(n, dp) << endl;
	for (int i = 0; i <= n; ++i)
	{
		cout << dp[i] << ", ";
	}
	cout << endl;

	cout << minStepsToOneBottomUpDP(n) << endl;

	return 0;
}



