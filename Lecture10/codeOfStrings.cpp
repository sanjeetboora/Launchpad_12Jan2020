#include<bits/stdc++.h>
using namespace std;

void codeOfstring(string input, string output){
	if(input == ""){
		cout<<output<<endl;
		return;
	}

	int one = input[0] - '0';
	int two =0;
	if(input.length() > 1){
		two = stoi(input.substr(0,2));
	}
	if(input.length() > 1 && two <= 26){
		char ch1 = one + 'a'-1;
		string roi = input.substr(1);
		codeOfstring(roi ,output + ch1);
		char ch2 = two + 'a'-1;
		roi = input.substr(2);
		codeOfstring(roi ,output + ch2);
	}
	else{
		char ch1 = one + 'a'-1;
		string roi = input.substr(1);
		codeOfstring(roi ,output + ch1);
	}
}


int main(int argc, char const *argv[])
{	
	string str = "1234";
	codeOfstring(str, "");
	
	return 0;
}











