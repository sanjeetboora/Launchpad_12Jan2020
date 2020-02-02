#include<bits/stdc++.h>
using namespace std;
void spiralPrint(int arr[10][10], int r, int c ) {

	int startRow = 0, endRow = r - 1, startCol = 0, endCol = c - 1;

	while ( startRow <= endRow && startCol <= endCol) {

		//print startRow
		for (int i = startCol; i <= endCol; ++i)
		{
			cout << arr[startRow][i] << ", ";
		}
		startRow++;

		//print End Column
		for (int i = startRow; i <= endRow; ++i)
		{
			cout << arr[i][endCol] << ", ";
		}
		endCol--;

		//print end Row
		if (startRow <= endRow) {
			for (int i = endCol; i >= startCol; i--)
			{
				cout << arr[endRow][i] << ", ";
			}
			endRow--;
		}

		//print start Column
		if (startCol <= endCol) {
			for (int i = endRow; i >= startRow; i--)
			{
				cout << arr[i][startCol] << ", ";
			}
			startCol++;

		}
	}

}

int main(int argc, char const *argv[])
{
	int r, c;
	cin >> r >> c;
	int arr[10][10];
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			arr[i][j] = (10 * i) + j + 1;
		}
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << arr[i][j] << ", ";
		}
		cout << endl;
	}

	spiralPrint(arr, r, c);



	return 0;
}











