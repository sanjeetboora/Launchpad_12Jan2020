#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{	
	int N;
	cin>>N;
	for (int row = 1; row <= N; row = row+1)
	{
		//cout<<row<<endl;
		// for increasing order
		for (int num = 1; num <= row; num = num+1)
		{
			cout<< num<<" ";
		}
		// for decreasing order
		for (int num = row-1; num >= 1; num = num-1)
		{
			cout<< num<<" ";
		}
		cout<<endl;
	}
	return 0;
}









