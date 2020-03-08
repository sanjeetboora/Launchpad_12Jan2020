#include <iostream>
using namespace std;
int lowerBound(int* arr, int n, int key) {
	int start = 0, end = n - 1, ans = -1;
	while (start <= end) {
		//int mid =(start + end)/2;
		int mid = start + (end - start) / 2;

		if (key == arr[mid]) {
			ans = mid;
			end = mid-1;
		}
		else if (key > arr[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}
int upperBound(int* arr, int n, int key) {
	int start = 0, end = n - 1, ans = -1;
	while (start <= end) {
		//int mid =(start + end)/2;
		int mid = start + (end - start) / 2;

		if (key == arr[mid]) {
			ans = mid;
			start = mid+1;
		}
		else if (key > arr[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int arr[10] = {1, 13, 13, 13, 13, 26, 37};
	int n = 7;
	int key = 13;
	// int result = lowerBound(arr, n, key);
	int result = upperBound(arr, n, key);
	if (result >= 0) {
		cout << key << " found at " << result << endl;
	}
	else {
		cout << key << " not found" << endl;
	}




	return 0;
}