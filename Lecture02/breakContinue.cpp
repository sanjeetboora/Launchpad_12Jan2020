#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; i=i+1)
	{
		for (int j = 0; j < 5; j=j+1)
		{
			if( j == 3){
				break;
			}
			cout<< i << "----------"<<j<<endl;
			if(i == 2){
				continue;
			}

			cout<< i << ", "<<j<<endl;
		}
	}



	return 0;
}