#include<bits/stdc++.h>
using namespace std;
void subsequence(string input, string output) {
	//base case
	//if(input.length()==0){
	if (input == "") {
		cout << output << endl;
		return;
	}
	char ch = input[0];
	string ros = input.substr(1);
	subsequence( ros, output);
	subsequence( ros, output + ch);
}
void subsequenceAscii(string input, string output) {
	//base case
	//if(input.length()==0){
	if (input == "") {
		cout << output << endl;
		return;
	}
	char ch = input[0];
	int chInt = (int) ch;
	string chStr = to_string(chInt);
	string ros = input.substr(1);
	subsequenceAscii( ros, output);
	subsequenceAscii( ros, output + ch + chStr);
}
void subsequenceAscii2(string input, string output) {
	//base case
	//if(input.length()==0){
	if (input == "") {
		cout << output << endl;
		for (int i = 0; i < output.length(); ++i)
		{	int chInt = (int) output[i];
			string chStr = to_string(chInt);
			
			cout<<output[i]<<chStr;
		}
		cout<<endl;
		return;
	}
	char ch = input[0];
	string ros = input.substr(1);
	subsequenceAscii2( ros, output);
	subsequenceAscii2( ros, output + ch);
	
}




int main(int argc, char const *argv[])
{
	string str = "abc";

	//subsequence(str, "");
	//subsequenceAscii(str, "");
	subsequenceAscii2(str, "");
	return 0;
}











