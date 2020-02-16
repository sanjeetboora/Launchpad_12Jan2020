#include<bits/stdc++.h>
using namespace std;

int sum(int n) {
	if (n == 0) {
		return 0;
	}

	int result = n + sum(n - 1);
	return result;
}

int main(int argc, char const *argv[])
{
	int n = 10;
	cout << sum(n) << endl;
	return 0;
}