#include<bits/stdc++.h>
using namespace std;
void decInc(int n) {
	//base case
	if (n < 1) {
		return;
	}
	//self work
	cout << n << endl;
	// recursive call
	decInc(n - 1);
	cout << n << endl;

}

void dec(int n) {
	//base case
	if (n < 1) {
		return;
	}
	//self work
	cout << n << endl;
	// recursive call
	dec(n - 1);

}

void increase(int n, int i){
	//base case
	if(i>n){
		return;
	}
	//self work
	cout<<i<<endl;
	//recursive call
	increase(n, i+1);

}

int main(int argc, char const *argv[])
{
	int n =5;
	//dec(5);
	//increase(n, 1);
	decInc(n);
	return 0;
}












