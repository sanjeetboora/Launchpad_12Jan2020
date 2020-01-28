#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	

	int arr[10] = {-2,-4,-7,-6,-8};
	int n = 5;
	int maxSum =INT_MIN;
	int currSum = 0;
	
	int maxNum = INT_MIN;
	for (int i = 0; i <= n-1; ++i)
	{
		currSum += arr[i];
		if(currSum > maxSum){
			maxSum = currSum;
		}
		if(currSum < 0 ){
			currSum = 0;
		}

		//maxNum = max(maxNum, arr[i]);
		if(arr[i] > maxNum){
			maxNum = arr[i];
		}
	}
	if(maxNum < 0){
		maxSum = maxNum;
	}
	cout<<"max sum is "<<maxSum<<endl;

}






















