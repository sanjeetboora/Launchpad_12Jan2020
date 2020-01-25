#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	

	int arr[10] = {3,4,7,6,8};
	int n=5;

	for (int i = 0; i <= n-1; ++i)
	{
		for (int j = i; j <= n-1; j++)
		{
			for (int k = i; k <= j; k++)
			{
				cout<<arr[k]<<", ";
			}
			cout<<endl;
			
		}
	}

}






















