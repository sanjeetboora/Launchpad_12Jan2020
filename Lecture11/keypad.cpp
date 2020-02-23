#include<bits/stdc++.h>
using namespace std;

string arr[10] = {"_", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wx", "yz"};

void keypadsequence(string input, string output){
	//base case
	if(input == ""){
		cout<<output<<endl;
		return;
	}

	//self work
	char ch = input[0];
	string str = arr[ch - '0'];
	string ros = input.substr(1);
	for (int i = 0; i < str.length(); ++i)
	{
		keypadsequence(ros, output + str[i]);
	}
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	keypadsequence(str, "");
	return 0;
}









