#include<bits/stdc++.h>
using namespace std;
int sumAllsubmatrix2(int** arr, int r, int c) {
	int tli = 0, tlj = 0, sum = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 1; j < c; j++)
		{
			arr[i][j] += arr[i][j - 1];
		}
	}
	for (int i = 0; i < c; i++)
	{
		for (int j = 1; j < r; j++)
		{
			arr[j][i] += arr[j - 1][i];
		}
	}


	for (int tli = 0; tli <= r - 1; tli++)
	{
		for (int tlj = 0; tlj <= c - 1; tlj++)
		{
			for (int bRi = tli; bRi <= r - 1 ; bRi++)
			{
				for (int bRj = tlj; bRj <= c - 1 ; bRj++)
				{
					cout << "( " << tli << ", " << tlj << "), " << "( " << bRi << ", " << bRj << ")" << endl;

					int currSubmatrixSum = arr[bRi][bRj];

					if (tli > 0) {

						currSubmatrixSum -= arr[tli - 1][bRj];
					}
					if (tlj > 0) {
						currSubmatrixSum -= arr[bRi][tlj - 1] ;
					}

					if (tli > 0 && tlj > 0) {
						currSubmatrixSum += arr[tli - 1][tlj - 1];
					}
					sum += currSubmatrixSum;
				}
			}
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
	cout << sumAllsubmatrix2(arr2, r, c) << endl;


	return 0;
}



//H.W. -> submatrix sum query





