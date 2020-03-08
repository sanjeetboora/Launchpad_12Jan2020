#include <iostream>
using namespace std;
int uniqueElement(int* arr, int n) {
	int start = 0,  end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1] ) {
			return mid;
		}
		// when mid is even

		if ( mid % 2 == 0) {
			if (arr[mid] == arr[mid + 1]) {
				start = mid + 1; //search in right
			}
			else {
				end = mid - 1;//search in left
			}
		}
		// when mid is odd
		else {
			if (arr[mid] == arr[mid - 1]) {
				start = mid + 1; //search in right
			}
			else {
				end = mid - 1;//search in left
			}
		}

	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int arr[20] = {1, 1, 2, 2, 4, 4, 5, 5, 6, 7, 7};
	int n = 11;
	int idx = uniqueElement(arr, n);
	cout << arr[idx] << endl;

	return 0;
}