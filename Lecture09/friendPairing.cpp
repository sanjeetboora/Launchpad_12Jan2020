#include<bits/stdc++.h>
using namespace std;

int ways(int n){
	if(n <= 2){
		return n;
	}
	//single + (n-1)* pair
	int result = ways(n-1) + (n-1)*ways(n-2);

}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<ways(n)<<endl;

	return 0;
}