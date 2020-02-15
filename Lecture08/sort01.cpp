#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	
	int arr[11] ={0,1,1,0,1,0,1,0,0,1,1};
	int n=11;
	int left = 0, right = n-1;

	while(left<= right){
		if(arr[left] == 0){
			left++;
		}
		else{
			swap(arr[left], arr[right]);
			right--;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;


	return 0;
}