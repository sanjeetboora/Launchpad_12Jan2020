#include<bits/stdc++.h>
using namespace std;


int linearSearch1(int* arr, int left,int right, int key){
	if(left > right){
		return -1;
	}

	if(arr[left] == key){
		return left;
	}
	if(arr[right] == key){
		return right;
	}
	int idx = linearSearch1(arr, left+1, right-1, key);
	return idx;
}

bool linearSearch(int* arr, int n, int key){
	if(n==0){//base case
		return false;
	}

	if(arr[0] == key or linearSearch(arr+1,n-1, key)){
	//if(linearSearch(arr+1,n-1, key) or arr[0] == key){
		return true;
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int arr[10] = {5,10,2,3,6,4,1};
	int key = 6;
	int n =7;
	// if(linearSearch(arr, n, key) == true){
	// 	cout<<key<<" found"<<endl;
	// }
	// else{
	// 	cout<<key<<" not found"<<endl;
	// }
	int idx = linearSearch1(arr, 0, n-1, key);
	if( idx != -1){
		cout<<key<<" found at "<<idx<<endl;
	}
	else{
		cout<<key<<" not found"<<endl;
	}

	return 0;
}







