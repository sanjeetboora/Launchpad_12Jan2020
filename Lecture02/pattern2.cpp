#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	//first half
	for (int row = 1; row <= N; row=row+1)
	{
		
		for (int stars = 1; stars <= row; stars = stars+1)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
	//second half
	for (int row = N-1; row >= 1; row=row-1)
	{
		for (int stars = 1; stars <= row; stars = stars+1)
		{
			cout<<"* ";
		}
	
		cout<<endl;
	}



	return 0;
}







