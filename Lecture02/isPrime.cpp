#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	 int isPrime = 1;
	for (int i = 2; i*i <= N; ++i)
	{
		if(N%i == 0){
			// N is composite
			isPrime =0;
			break;
		}


	}

	// N is prime
	if(isPrime == 1){
		cout<<N<<" is prime number"<<endl;
	}
	else{
		cout<<N<<" is composite number"<<endl;
	}


	return 0;
}