#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	
	int leftMax = INT_MIN;
	int arr[10]= {1,5,4,7,6,9,12,10};

	for (int i = 0; i < 8; i++)
	{
		if(arr[i] > leftMax){
			leftMax = arr[i];
			cout<< arr[i]<<", ";
		}
	}
	

	return 0;
}