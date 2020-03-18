#include <iostream>
using namespace std;


int merge(int* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, k = 0;
	int* temp = new int [end - start + 1];
	int invcount = 0;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		}
		else {
			temp[k] = arr[j];
			j++;
			k++;
			invcount += (mid-i+1);
		}
	}
	while (i <= mid) {
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= end) {
		temp[k] = arr[j];
		j++;
		k++;
	}
	i = 0;
	for (int l = start; l <= end; l++)
	{
		arr[l]  =  temp[i];
		i++;
	}
	return invcount; 
}

int mergeSort(int* arr, int start, int end) {
	if ( start >= end) {
		return 0;
	}
	int mid = start + (end - start) / 2;
	int inversionCount =0;
	inversionCount += mergeSort(arr, start, mid); // left half
	inversionCount += mergeSort(arr, mid + 1, end); //right half
	inversionCount += merge(arr, start, mid, end);

	return inversionCount;
}

int main(int argc, char const *argv[])
{
	int arr[9] = {5, 4, 3, 2, 1};
	//merge(arr, 0, 4, 8);
	cout<<mergeSort(arr, 0, 4)<<endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
	return 0;
}










