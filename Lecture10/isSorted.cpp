#include<bits/stdc++.h>
using namespace std;

bool isSorted(int* arr, int n) {
	if (n == 1) {
		return true;
	}
	if ( arr[0] <= arr[1] && isSorted(arr + 1, n - 1)) {
		return true;
	}
	return false;
}
bool isSorted1(int* arr, int n) {
	if (n == 0) {
		return true;
	}
	if ( arr[n] >= arr[n-1] && isSorted1(arr, n - 1)) {
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
//int arr[10] = {5, 10, 2, 3, 6, 4, 1};
int arr[10] = {1,2,3,4,5,6,7};
	int n = 7;

//if (isSorted(arr, n)) {
	if (isSorted1(arr, n-1)) {
		cout << "sorted" << endl;
	}
	else {
		cout << "unsorted" << endl;
	}

	return 0;
}







