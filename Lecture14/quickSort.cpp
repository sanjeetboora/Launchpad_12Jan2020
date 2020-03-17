#include <iostream>
using namespace std;

int placePivot(int* arr, int start, int end) {
	int pivot = arr[end];
	int i = start - 1; //i -> elements till i are smaller than pivot

	for (int j = start; j < end; j++)
	{
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	i++;
	swap(arr[i], arr[end]); // place pivot at it's correct position
	return i;
}

void quickSort(int* arr, int start, int end) {
	if (start >= end) {
		return;
	}

	int pivotCorrectIdx = placePivot(arr, start, end);
	quickSort(arr, start, pivotCorrectIdx - 1); //left half
	quickSort(arr, pivotCorrectIdx + 1, end); //right half
}

int main(int argc, char const *argv[])
{
	int arr[10] = {2, 5, 1, 6, 3};
	quickSort(arr, 0, 4);

	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << ",";
	}
	cout<<endl;
	return 0;
}






