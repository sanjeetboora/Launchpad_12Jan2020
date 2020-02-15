#include<bits/stdc++.h>
using namespace std;
void rotateMatrix(int** arr, int r, int c) {

	for (int i = 0; i < r; ++i)
	{
		int left =0, right = c-1;
		while(left < right){
			swap(arr[i][left], arr[i][right]);
			left++;
			right--;
		}
	}
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < i; j++)
		{
			swap(arr[i][j], arr[j][i]);
		}
	}

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
			arr2[i][j] = (10 * i) + j + 1;
			
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
	rotateMatrix(arr2, r, c);
	cout<<"------------------------------"<<endl;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << arr2[i][j] << ", ";
		}
		cout << endl;
	}
	return 0;
}




