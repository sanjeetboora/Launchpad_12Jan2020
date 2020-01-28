#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{

	int n, r, result;
	cin >> n >> r;
	int nfact = 1, rfact = 1, nrfact = 1;
	for (int i = 1; i <= n; ++i) // n factorial
	{
		nfact *= i;
	}

	for (int i = 1; i <= r; ++i)// r factorial
	{
		rfact *= i;
	}

	for (int i = 1; i <= n-r; ++i)// n - r factorial
	{
		nrfact *= i;
	}

	result = nfact/ (rfact* nrfact);
	cout<<result<<endl;

	return 0;
}













