#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	//int arr[10];

	// int n;
	// cin>>n;
	// int arr[n];

	//new operator
	// int *n = new int(5);
	// int *n1 = new int();
	// cout << n << endl;
	// cout << *n << endl;
	// cout << n1 << endl;
	// cout << *n1 << endl;

	// int s;
	// cin >> s;

	// int* arr = new int[s];
	// for (int i = 0; i < s; ++i)
	// {
	// 	cin>>arr[i];
	// }
	// for (int i = 0; i < s; ++i)
	// {
	// 	cout<<arr[i]<<", ";
	// }
	// cout<<endl;
	int r, c;
	cin>>r>>c;
	//2d dynmaic array
	int** arr2 = new int*[r];
	for (int i = 0; i < r; ++i)
	{
		arr2[i] = new int[c];
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			arr2[i][j] = (10 * i) + j + 1;
		}
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << arr2[i][j] << ", ";
		}
		cout << endl;
	}







	return 0;
}














