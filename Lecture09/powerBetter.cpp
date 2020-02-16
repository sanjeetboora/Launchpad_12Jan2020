#include<bits/stdc++.h>
using namespace std;
int power(int a, int b){
	// base case
	if(b==0){
		return 1;
	}

	int smallResult = power(a,b/2);
	int result = smallResult*smallResult;
	if(b&1){
		result *= a;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int a, b;
	cin>>a>>b;

	int result = power(a,b);
	cout<<result<<endl;


	return 0;
}