#include <iostream>
using namespace std;
int findNumberOfRotations(int* arr, int N) {
	int left = 0, right = N - 1;

	while (left <= right) {
		//case 1
		if (arr[left] <= arr[right]) {
			return left;
		}
		int mid = left + (right - left) / 2;
		//case 2 - smallest element found at mid
		int prev = (mid - 1 + N) % N;
		int next = (mid + 1) % N;
		if (arr[prev] >= arr[mid] && arr[next] >= arr[mid]) {
			return mid;
		}

		//case 3  - search left half
		if (arr[right] >= arr[mid]) { //right half sorted
			right = mid - 1;
		}
		//case 4 - search right half
		if (arr[left] <= arr[mid]) { //left half sorted
			left = mid + 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[5] = {1, 2, 3, 4, 5};
	int count = findNumberOfRotations(arr, 5);
	cout << count << endl;

	return 0;
}