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
		//swap(arr[i], arr[minidx]);
		int temp = arr[minidx];
		for (int k = minidx-1; k >= i; k--)
		{
			arr[k+1] = arr[k];
		}
		arr[i] = temp;
	}

}

int main(int argc, char const *argv[])
{
	int arr[10] = {100, 200, 200, 10, 10};
	int n = 5;
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