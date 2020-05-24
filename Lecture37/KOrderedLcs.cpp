#include <bits/stdc++.h>
using namespace std;

int dp[100][100][100];
int KOrderedLcs(string str1, string str2, int i, int j, int k ) {

	if (i == str1.length() or j == str2.length()) {
		return 0;
	}

	if (dp[i][j][k] != -1) { //already calculated
		return dp[i][j][k];
	}


	int ans = 0;
	if (str1[i]  == str2[j]) {
		ans = 1 + KOrderedLcs(str1, str2, i + 1, j + 1, k);
	}
	else {

		int case1 = KOrderedLcs(str1, str2, i, j + 1, k);
		int case2 = KOrderedLcs(str1, str2, i + 1, j, k);

		int case3  = -1;
		if (k > 0) {
			case3 = 1 + KOrderedLcs(str1, str2, i + 1, j + 1, k - 1);
		}

		ans = max(case1 , max(case2, case3));
	}

	dp[i][j][k] = ans;
	return ans;

}


int main(int argc, char const *argv[])
{
	string str1 = "abchgk";
	string str2 = "cgbkh";
	int k = 2;
	for (int i = 0; i <= str1.length() ; ++i)
	{
		for (int j = 0; j <= str2.length(); ++j)
		{
			for (int l = 0; l <= k; ++l)
			{
				dp[i][j][l] = -1;
			}
		}

	}

	cout << KOrderedLcs(str1, str2, 0, 0, k) << endl;
	return 0;
}



