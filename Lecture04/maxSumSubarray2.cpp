#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	

	int arr[10] = {2,4,-7,6,8};
	int n=5;
	int maxSum =INT_MIN;
	int cumSum[5] = {0};
	cumSum[0] = arr[0];
	for (int i = 1; i < n; ++i) //n*n
	{
		cumSum[i] = cumSum[i-1] + arr[i];
	}
	for (int i = 0; i <= n-1; ++i)
	{
		for (int j = i; j <= n-1; j++)
		{	
			int subarrySum = cumSum[j] - cumSum[i-1];
			
			if(subarrySum > maxSum){
				maxSum = subarrySum;
			}
		}
	}
	cout<<"max sum is "<<maxSum<<endl;

}






















