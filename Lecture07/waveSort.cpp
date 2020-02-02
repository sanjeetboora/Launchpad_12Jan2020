#include<bits/stdc++.h>
using namespace std;
void waveSort(int* arr, int n) {

	for (int i = 0; i < n; i = i + 2)
	{
		if (arr[i] < arr[i - 1] && i > 0 ) {
			swap(arr[i], arr[i - 1]);
		}
		if (arr[i] < arr[i + 1] && i < n - 1 ) {
			swap(arr[i], arr[i + 1]);
		}
	}

}


int main(int argc, char const *argv[])
{
	int n = 8;
	int arr[10] = {1, 5, 2, 10, 9, 8, 7, 12};
	waveSort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;

	return 0;
}