#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	

	int arr[10] = {2,4,-7,6,8};
	int k=3;
	int n=5;
	for (int i = 1; i <= k; ++i) //n*k
	{
		int temp = arr[n-1];
		for (int i = n-2; i >=0; i--)
		{
			arr[i+1]=arr[i];	
		}
		arr[0] = temp;
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<",";
	}

}







