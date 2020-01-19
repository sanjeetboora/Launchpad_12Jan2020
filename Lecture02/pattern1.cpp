#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	cin>>N;

	for (int row = 1; row <= N; row=row+1)
	{
		
		for (int stars = 1; stars <= row; stars = stars+1)
		{
			cout<<"* ";
		}
		cout<<endl;
		//cout<<row<<endl;
	}

	return 0;
}