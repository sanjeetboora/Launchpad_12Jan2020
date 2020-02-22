#include<bits/stdc++.h>
using namespace std;
void addStar(string input, string output){
	if(input == ""){ // base case
		cout<<output<<endl;
		return;
	}

	//self work
	if(input.length()>1 && input[0] == 'x' and input[1] == 'x'){
		output = output+ input[0] + "#";
		string ros = input.substr(1);
		addStar(ros, output);
	}
	else{
		output += input[0]; 
		string ros = input.substr(1);
		addStar(ros, output);
	}
}


int main(int argc, char const *argv[])
{
	string str = "xpiabxxnmxyzxxxxzbx";
	addStar(str,"");

	return 0;
}