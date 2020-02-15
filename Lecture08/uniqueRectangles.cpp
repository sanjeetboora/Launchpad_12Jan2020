#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	int count = 0;
	for (int length = 1; length * length <= N; length++)
	{
		for (int height = length; height * length <= N; height++)
		{
			count++;
		}
	}

	cout << count << endl;

	return 0;
}














