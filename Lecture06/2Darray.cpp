#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	
	// dataType variableName [rows][cols];
	int arr[3][4] = {{1,2,3,4},
					{11,12,13,14},
					{21,22,23,24}};
	int r=3, c =4;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j <c; j++)
		{
			cout<<arr[i][j]<<",";
		}
		cout<<endl;
	}

	return 0;
}