#include <iostream>
using namespace std;
int binarySearch(int* arr, int n, int key) {
	int start = 0, end = n - 1;
	while(start <= end){
		//int mid =(start + end)/2;
		int mid =start + (end - start)/2;

		if(key == arr[mid]){
			return mid;
		}
		else if(key > arr[mid]){
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int arr[10] = {1, 2, 13, 24, 25, 26, 37};
	int n = 7;
	int key = 26;
	int result = binarySearch(arr, n, key);
	if(result >= 0){
		cout<<key<<" found at "<<result<<endl;
	}
	else{
			cout<<key<<" not found"<<endl;
	}




	return 0;
}