#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	char arr[10] = {'a','g','f','l'};
	int arri[10] = {1,2,3,4};

	cout<<arr<<endl;
	cout<<arri<<endl;

	char* arr1 = new char[10];
	arr1[0]  = 'a';
	arr1[1]  = 'b';
	cout<<arr1<<endl;

	string str = "abcdefghij";
	cout<<str<<endl;
	for (int i = 0; i < str.length(); ++i)
	{
		cout<<str[i]<<",";
	}
	cout<<endl;

	string ab = str.substr(2, 4);
	cout<<ab<<endl;
	string ab1 = str.substr(2);
	cout<<ab1<<endl;
	string str1 = "abc";
	string str2 = "def";
	string str3 = str1 + str2;
	cout<<str3<<endl;
	string sarr[10] = {"abc", "def", "dhi"};
	cout<<sarr<<endl;


	return 0;
}













