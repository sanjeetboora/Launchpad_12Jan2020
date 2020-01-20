#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{	
	int N;
	cin>>N;
	for (int row = 1; row <= N; row = row+1)
	{	int value;
		if(row % 2 == 0){
			value =0;
		}
		else{
			value =1;
		}

		for (int i = 1; i <= row; i = i+1)
		{
			cout<<value<<" ";
			value = !value;
		}
		cout<<endl;
	}
}







