#include<bits/stdc++.h>
using namespace std;

int factorial(int n){

	int result = 1;

	for (int i = 1; i <= n; ++i)
	{
		result *= i; 
	}

	// cout<<result<<endl;
	 return result;
}
int ncr(int num, int ra){

	int result = factorial(num)/ (factorial(ra) * factorial(num-ra));
	return result;

}



int main(int argc, char const *argv[])
{	
	int n =5, r =2;

	cout<<ncr(n, r)<<endl;
	
	return 0;
}

















