#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[10], int n) {

	for (int i = 0; i < n-1; ++i)
	{
		int minidx = i;
		for (int j = i+1; j < n; j++)
		{
			if( arr[j] < arr[minidx]){
				minidx = j;
			}
		}
		swap(arr[i], arr[minidx]);
	}

}

int main(int argc, char const *argv[])
{
	int arr[10] = {8, 10, 2, 5, 6, 1, 4, 3};
	int n = 8;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
	selectionSort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
	return 0;
}