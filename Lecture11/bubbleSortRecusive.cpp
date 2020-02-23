#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[10], int n){
	if(n==0){
		return;
	}
		for (int i = 0; i < n; ++i)
		{
			if(arr[i] > arr[i+1]){
				swap(arr[i], arr[i+1]);
			}
		}

		bubbleSort(arr, n-1);
	

}

void bubbleSort1(int arr[10], int n, int i) {
	if (n == 0) {
		return;
	}
	if(i == n){
		bubbleSort1(arr, n-1, 0);
		return;
	}
	
	if (arr[i] > arr[i + 1]) {
		swap(arr[i], arr[i + 1]);
	}
	bubbleSort1(arr, n , i+1);

}

int main(int argc, char const *argv[])
{
	int arr[10] = {8,10,2,5,6,1,4,3};
	int n=8;
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;
	//bubbleSort(arr, n-1);
	bubbleSort1(arr, n-1,0);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;
	return 0;
}