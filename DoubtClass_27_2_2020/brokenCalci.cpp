#include <iostream>
using namespace std;
int multiply(int num, int* result, int resSize) {
	int carry = 0;
	for (int i = 0; i < resSize; ++i)
	{
		int product = num * result[i] + carry;
		result[i] = product % 10;
		carry = product/10;
	}
	while(carry > 0){
		result[resSize] = carry%10;
		carry /= 10;
		resSize++;
	}
	return resSize;
}
void factorial(int n) {
	int result[1000000];
	result[0] = 1;
	int resSize = 1;
	for (int num = 2; num <= n; num++)
	{
		resSize = multiply(num, result, resSize);
	}

	for (int i = resSize - 1; i >= 0; i--)
	{
		cout << result[i];
	}
	cout << endl;

}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	factorial(n);

	return 0;
}