#include <bits/stdc++.h>
using namespace std;

int coins[5] = {20, 10, 5, 2, 1};

int minCoins(int n) {
	int numCoins = 0;
	int i = 0;
	while (n > 0) {
		if (n >= coins[i]) {
			numCoins += n / coins[i];

			n %= coins[i];
		}
		i++;
	}
	return numCoins;
}


int main(int argc, char const *argv[])
{
	int n = 77;
	cout << minCoins(n) << endl;
	return 0;
}