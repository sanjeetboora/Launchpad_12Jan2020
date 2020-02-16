#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
	// base case
	if(n==0){
		return 1;
	}
		
	//self work
	int result = n*factorial(n-1);// recursive call 
	return result;
}
int main(int argc, char const *argv[])
{	
	int n =5;
	int res = factorial(n);
	cout<<res<<endl;
	
	return 0;
}


















