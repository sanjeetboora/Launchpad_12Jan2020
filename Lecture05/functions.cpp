#include<bits/stdc++.h>
using namespace std;
int fun5(int &num, int m, int num2); 

int factorial(int n){

	int result = 1;

	for (int i = 1; i <= n; ++i)
	{
		result *= i; 
	}

	// cout<<result<<endl;
	 return result;
}

int fun(int m){
	m = m + 5; 
	cout<<m<<endl;
	return m;
}
int fun2(int n){
	n = n + 5; 
	cout<<n<<endl;
	return n;
}

int fun3(int &num){
	num = num + 5; 
	cout<< "fun3 n -> "<<&num <<endl;
	cout<<num<<endl;
	return num;
}
int fun4(int &num, int m){
	num = num + 5; 
	m = 25;
	cout<<num<<endl;
	cout<<m<<endl;
	return num;
}


int main(int argc, char const *argv[])
{	
	int n = 10;
	int m = 12;
	//int result = fun4(n, m);
	//int result = fun5(n, m);
	int result = fun5(n, m, 30);
	cout<<n<<", "<<m<<", "<<result<<endl;

	//int result = fun(n);
	//int result = fun2(n);
	// cout<< "main n -> "<<&n <<endl;
	// int result = fun3(n);
	// cout<< "main result -> "<<&result <<endl;
	// cout<<n<<endl;

	// int num = 5;
	// int r =2;
	// int nfact = factorial(num);
	// int rfact = factorial(r);
	//cout<<numfact<<endl;


	return 0;
}


int fun5(int &num, int m, int num2 = 10){
	num = num + 5; 
	m = 25;
	cout<<num<<endl;
	cout<<m<<endl;
	cout<<num2<<endl;
	return num;
}







