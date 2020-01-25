#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	
	int arr[10]= {1,5,2,0,9,11,22,25,12};
	int leftMax[10];
	int rightMin[10];
	leftMax[0] = INT_MIN;
	rightMin[8] = INT_MAX;
	//leftmax array
	for (int i = 1; i < 9; i++)
	{
		leftMax[i] = max( arr[i-1], leftMax[i-1]);
	}
	//leftmax array print
	for (int i = 0; i < 9; ++i)
	{
		cout<<leftMax[i]<<", ";
	}	
		cout<<endl;
	//rightMin array
	for (int i = 7; i >= 0; i--)
	{
		rightMin[i] = min(rightMin[i+1], arr[i+1]);
	}
	//rightMin array print
	for (int i = 0; i < 9; ++i)
	{
		cout<<rightMin[i]<<", ";
	}cout<<endl;
	//original array
	for (int i = 0; i < 9; ++i)
	{
		if(arr[i] > leftMax[i] && arr[i] < rightMin[i]){
			cout<<arr[i]<<", ";
		}
	}
	cout<<endl;

	return 0;
}










