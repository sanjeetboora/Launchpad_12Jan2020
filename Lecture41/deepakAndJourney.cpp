#include <bits/stdc++.h>
using namespace std;

int minCost(int*cost, int* petrol, int n) {
	int minPrice = cost[0];
	int totalCost = minPrice * petrol[0];

	for (int i = 1; i < n; ++i)
	{
		if (cost[i] < minPrice) {
			minPrice = cost[i];
		}
		totalCost += minPrice * petrol[i];
	}
	return totalCost;
}


int main(int argc, char const *argv[])
{
	int cost[10] = {7, 3, 2, 5, 9, 1};
	int petrol[10] = {5, 7, 5, 9, 3, 4};
	int n = 6;
	cout << minCost(cost, petrol, n);
	return 0;
}

// 1000000007
// (a+b)%c = (a%c + b%c)%c