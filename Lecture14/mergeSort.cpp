#include <iostream>
using namespace std;


void merge(int* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, k = 0;
	int* temp = new int [end - start + 1];

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
}

void mergeSort(int* arr, int start, int end) {
	if ( start >= end) {
		return;
	}
	int mid = start + (end - start) / 2;
	mergeSort(arr, start, mid); // left half
	mergeSort(arr, mid + 1, end); //right half
	merge(arr, start, mid, end);
}

int main(int argc, char const *argv[])
{
	int arr[9] = {9,8,7,6,5,4,3,2,1};
	//merge(arr, 0, 4, 8);
	mergeSort(arr, 0, 8);
	for (int i = 0; i < 9; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
	return 0;
}










