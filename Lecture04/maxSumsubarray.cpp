#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	

	int arr[10] = {-2,-4,-7,-6,-8};
	int n=5;
	int maxSum =INT_MIN;
	for (int i = 0; i <= n-1; ++i)//n*n*n
	{
		for (int j = i; j <= n-1; j++)
		{	int subarrySum =0;
			for (int k = i; k <= j; k++)
			{
				cout<<arr[k]<<", ";
				subarrySum += arr[k];
			}
			cout<<"----->"<<subarrySum<<endl;
			if(subarrySum > maxSum){
				maxSum = subarrySum;
			}
		}
	}
	cout<<"max sum is "<<maxSum<<endl;

}






















