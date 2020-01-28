#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[10], int n){

	for (int j = 0; j < n-1; ++j)
	{	
		bool isSorted = true;
		for (int i = 0; i < n-j-1; ++i)
		{
			if(arr[i] > arr[i+1]){
				swap(arr[i], arr[i+1]);
				isSorted = false;
			}
		}
		if(isSorted == true){
			break;
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<arr[i]<<", ";
		}
		cout<<"--------------------------------"<<endl;
	}

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
	bubbleSort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;
	return 0;
}