#include <iostream>
using namespace  std;

int fibRec(int n) {
	if (n == 0 || n == 1) {
		return n;
	}

	int nthFibonacci = fibRec(n - 1) + fibRec(n - 2);
	return nthFibonacci;

}

int fibTopDownDp(int n, int* dp) {
	if (n == 0 || n == 1) {
		dp[n] = n;
		return n;
	}

	//if nth fibonacci is already calc
	if (dp[n] != 0) {
		return dp[n];
	}

	int nthFibonacci = fibTopDownDp(n - 1, dp) + fibTopDownDp(n - 2, dp);
	dp[n] = nthFibonacci;

	return dp[n];
}

int fibBottomUpDp(int n) {
	int dp[100] = {0};

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int fibBottomUpDpSpaceOptimized(int n) {
	if (n == 0 || n == 1) {
		return n;
	}

	int a = 0, b = 1, c;
	for (int i = 2; i <= n ; ++i)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}



int main(int argc, char const *argv[])
{
	int n = 5;
	cout << fibRec(n) << endl;

	int dp[100] = {0};
	cout << fibTopDownDp(n, dp) << endl;
	for (int i = 0; i <= n; ++i)
	{
		cout << dp[i] << ", ";
	}
	cout << endl;

	cout << fibBottomUpDp(n) << endl;
	cout << fibBottomUpDpSpaceOptimized(n) << endl;




	return 0;
}