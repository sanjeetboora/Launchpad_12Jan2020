#include <iostream>
using namespace std;
double squareRoot(int n, int p){

	int start = 1, end = n;
	double ans =0;
	while(start <= end){
		int mid = start + (end - start) / 2;
		int num = mid*mid;
		if(num <= n){
			ans =mid;
			start = mid+1;
		}
		if(num < n){
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}

	double add = 0.1;
	while(p>0){
		ans += add;
		while(ans*ans <= n){
			ans += add;
		}
		ans -= add;
		add /= 10;
		p--;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<squareRoot(n,4)<<endl;

	return 0;
}





