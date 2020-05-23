#include <bits/stdc++.h>
using namespace std;

int lcsRec(string str1, string str2) {
	if (str1.length() == 0 or str2.length() == 0) {
		return 0;
	}

	if (str1[0] == str2[0]) {
		return 1 + lcsRec(str1.substr(1), str2.substr(1));
	}
	else {
		return max(
		           lcsRec(str1,  str2.substr(1)),
		           lcsRec(str1.substr(1), str2)
		       );
	}

}

int dp[100][100];
// int lcsTopDown(string str1, string str2) {
// 	if (str1.length() == 0 or str2.length() == 0) {
// 		return 0;
// 	}

// 	if (dp[str1.size()][str2.size()] != -1 ) {
// 		return dp[str1.size()][str2.size()];
// 	}

// 	int ans = 0;

// 	if (str1[0] == str2[0]) {
// 		ans =  1 + lcsTopDown(str1.substr(1), str2.substr(1));
// 	}
// 	else {
// 		ans =  max(
// 		           lcsTopDown(str1,  str2.substr(1)),
// 		           lcsTopDown(str1.substr(1), str2)
// 		       );
// 	}

// 	dp[str1.size()][str2.size()] = ans;

// 	return ans;

// }


int lcsTopDown(string str1, string str2, int i, int j) {
	if (i == str1.length() or j == str2.length() ) {
		return 0;
	}

	if (dp[i][j] != -1 ) {
		return dp[i][j];
	}

	int ans = 0;

	if (str1[i] == str2[j]) {
		ans =  1 + lcsTopDown(str1, str2, i + 1, j + 1);
	}
	else {
		ans =  max(
		           lcsTopDown(str1,  str2, i + 1, j),
		           lcsTopDown(str1, str2, i, j + 1)
		       );
	}

	dp[i][j] = ans;

	return ans;

}







int main(int argc, char const *argv[])
{
	string str1 = "abchgk";
	string str2 = "cgbkh";

	cout << lcsRec(str1, str2) << endl;

	for (int i = 0; i <= str1.length(); ++i)
	{
		for (int j = 0; j <= str2.length(); ++j)
		{
			dp[i][j] = -1;
		}
	}
	//cout << lcsTopDown(str1, str2) << endl;
	cout << lcsTopDown(str1, str2, 0, 0) << endl;

	for (int i = 0; i <= str1.length(); ++i)
	{
		for (int j = 0; j <= str2.length(); ++j)
		{
			cout << dp[i][j] << ", ";
		}
		cout << endl;
	}

	return 0;
}



