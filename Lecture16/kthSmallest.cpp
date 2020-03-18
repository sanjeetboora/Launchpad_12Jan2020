#include <bits/stdc++.h>
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

int kthSmallest(int* arr, int start, int end, int k) {
	if (start >= end) {
		return arr[start];
	}

	if (k > 0 and k <= end - start + 1 ) {
		int pivotCorrectIdx = placePivot(arr, start, end);
		if (pivotCorrectIdx == k - 1) {
			return arr[pivotCorrectIdx];
		}
		if (pivotCorrectIdx > k - 1) { //search in left
			return kthSmallest(arr, start, pivotCorrectIdx - 1, k); //left half
		}
		if (pivotCorrectIdx < k - 1) { //search in right
			return kthSmallest(arr, pivotCorrectIdx + 1, end, k - 1 - pivotCorrectIdx ); //right half
		}
	}
	return -1;

}

int main(int argc, char const *argv[])
{
	int arr[10] = {2, 5, 1, 6, 3};
	int result = kthSmallest(arr, 0, 4,4);
	if(result != -1){
		cout<<result<<endl;
	}
	else{
		cout<<"kth smallest element doesn't exist"<<endl;
	}
	

	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << ",";
	}
	cout << endl;
	return 0;
}






