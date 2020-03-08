#include <iostream>
using namespace std;
int squareRoot(int n){

	int start = 1, end = n;
	while(start <= end){
		int mid = start + (end - start) / 2;
		int num = mid*mid;
		if(num == n){
			return mid;
		}
		if(num < n){
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<squareRoot(n)<<endl;

	return 0;
}