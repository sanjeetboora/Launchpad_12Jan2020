#include<bits/stdc++.h>
using namespace std;
int sumAllsubmatrix3(int** arr, int r, int c) {
	int sum =0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			int topLeft = (i+1)*(j+1);
			int bottomRight = (r-i)*(c-j);
			int cellContribution = arr[i][j]* topLeft* bottomRight;
			sum += cellContribution;
		}
	}
	return sum;
}

int main()
{
	int r, c;
	cin >> r >> c;
	//2d dynmaic array
	int** arr2 = new int*[r];
	for (int i = 0; i < r; ++i)
	{
		arr2[i] = new int[c];
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			//arr2[i][j] = (10 * i) + j + 1;
			arr2[i][j] = 1;
		}
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << arr2[i][j] << ", ";
		}
		cout << endl;
	}
	cout << sumAllsubmatrix3(arr2, r, c) << endl;


	return 0;
}