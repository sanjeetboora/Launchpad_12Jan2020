#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;

	cin>>n;
	int result = 0;
	while(n!=100){
		result = result ^ n;
		cout<<result<<endl;
		cin>>n;
	}
	cout<<result<<endl;

	return 0;
}