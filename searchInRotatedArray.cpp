#include <iostream>
using namespace std;
int searchInRotatedArray(int* arr, int N, int key) {
	int left = 0, right = N - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		//case 1 -> key found
		if(arr[mid] == key){
			return mid;
		}
		//case 2 -> left half sorted
		if(arr[left] <= arr[mid]){
			if(arr[left] <= key && key < arr[mid]){ // key exist in left half
				right =mid-1; // search in left half
			}
			else{ // key exist in right half
				left = mid+1;
			}
		}
		//case 3 -> right half sorted
		else{

			if( key > arr[mid] && key <= arr[right]){ // key exist in right half
				left = mid+1; // search in right half
			}
			else{// key exist in left half
				right =mid-1; // search in left half
			}
		}

	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int arr[5] = {4, 5, 1, 2, 3};
	int idx = searchInRotatedArray(arr, 5, 2);
	cout << idx << endl;

	return 0;
}