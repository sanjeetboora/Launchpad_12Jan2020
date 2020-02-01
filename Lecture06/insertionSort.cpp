#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[10], int n) {

	int i = 1;
	while (i < n) {
		int j = i-1;
		int key = arr[i];
		while(j>=0 && key < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
		i++;
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
	insertionSort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
	return 0;
}