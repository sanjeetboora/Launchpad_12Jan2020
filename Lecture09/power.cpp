#include<bits/stdc++.h>
using namespace std;
int power(int a, int b){
	// base case
	if(b==0){
		return 1;
	}

	int result = a*power(a, b-1);
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