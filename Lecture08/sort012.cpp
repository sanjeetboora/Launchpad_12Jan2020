#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[10] = {1, 2, 0, 1, 0, 2, 0, 1, 1, 2};
	int n = 10;
	int left = 0, mid = 0, right = n - 1;
	while (mid <= right) {

		if (arr[mid] == 0) {
			swap(arr[mid], arr[left]);
			left++;
			mid++;
		}
		else if (arr[mid] == 2) {
			swap(arr[mid], arr[right]);
			right--;
		}
		else {
			mid++;
		}

	}



	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;


	return 0;
}







