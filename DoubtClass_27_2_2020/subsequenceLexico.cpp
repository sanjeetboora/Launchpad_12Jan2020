#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<string> v; 
void subsequence(string input, string output){
	if(input.length() == 0){
		v.push_back(output);
		return;
	}

	char ch = input[0];
	string ros = input.substr(1);
	subsequence(ros, output);
	subsequence(ros, output+ch);
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	//sort(str, str+str.length());
	subsequence(str,"");
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}
