#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int* arr, int n){

	for (int j = 0; j < n-1; ++j)
	{	
		bool isSorted = true; //optimization
		for (int i = 0; i < n-j-1; ++i)
		{
			if(arr[i] > arr[i+1]){
				swap(arr[i], arr[i+1]);
				isSorted = false;
			}
		}
		if(isSorted == true){//optimization
			break;
		}
	}

}

int main(int argc, char const *argv[])
{
	int arr[100000];
	int n =100000;
	for (int i = 0; i < n; ++i)
	{
		arr[i] = n-i;
	}
	clock_t startTime = clock();
	sort(arr, arr+n);
	clock_t endTime = clock();
	cout<<"timing for inbuilt sort function"<<endl;
	cout<<startTime<<endl;
	cout<<endTime<<endl;
	cout<< endTime - startTime<<endl;

	for (int i = 0; i < n; ++i)
	{
		arr[i] = n-i;
	}
	startTime = clock();
	bubbleSort(arr, n);
	endTime = clock();
	cout<<"timing for bubble sort function"<<endl;
	cout<<startTime<<endl;
	cout<<endTime<<endl;
	cout<< endTime - startTime<<endl;



	return 0;
}