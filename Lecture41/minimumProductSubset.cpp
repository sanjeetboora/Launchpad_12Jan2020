#include <bits/stdc++.h>
using namespace std;

int minProd(int* arr, int n) {
	int countofZeroes = 0, countNegNumber = 0, maxNegNumber = INT_MIN, minPosNumber = INT_MAX, totalProduct = 1;

	if (n == 1) {
		return arr[0];
	}

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 0) {
			countofZeroes++;
		}
		else {
			totalProduct *= arr[i];
			if (arr[i] < 0) {
				countNegNumber++;
				maxNegNumber = max(maxNegNumber, arr[i]);
			}
			else {
				minPosNumber = min(minPosNumber, arr[i]);
			}
		}
	}

	if (countNegNumber == 0) { // all positive number
		if (countofZeroes > 0) {
			return 0;
		}
		else {
			return minPosNumber;
		}
	}
	else {
		if (countNegNumber & 1) {
			return totalProduct;
		}
		else {
			return totalProduct / maxNegNumber;
		}
	}

}


int main(int argc, char const *argv[])
{
	int arr[10] = { -1, -2, -3, 0, 1, 2, 3};
	int n = 7;

	cout << minProd(arr, n) << endl;
	return 0;
}