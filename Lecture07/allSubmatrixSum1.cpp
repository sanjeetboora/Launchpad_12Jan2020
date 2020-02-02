#include<bits/stdc++.h>
using namespace std;
int sumAllsubmatrix(int** arr, int r, int c) {
	int tli = 0, tlj = 0, sum = 0;

	for (int tli = 0; tli <= r - 1; tli++)
	{
		for (int tlj = 0; tlj <= c - 1; tlj++)
		{
			for (int bRi = tli; bRi <= r - 1 ; bRi++)
			{
				for (int bRj = tlj; bRj <= c - 1 ; bRj++)
				{
					cout << "( " << tli << ", " << tlj << "), " << "( " << bRi << ", " << bRj << ")" << endl;
					for (int i = tli; i <= bRi; ++i)
					{
						for (int j = tlj; j <= bRj; j++)
						{
							sum += arr[i][j];
						}
					}
				}
			}
		}
	}
	return sum;

}







int main(int argc, char const *argv[])
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
	cout << sumAllsubmatrix(arr2, r, c) << endl;


	return 0;
}