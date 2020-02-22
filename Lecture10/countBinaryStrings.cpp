#include<bits/stdc++.h>
using namespace std;
int countBinary(int n, string output){
	if(n==0){
		return 1;
	}
	int count =0;
	if(output[ output.length()-1 ] == '0'){
		count = countBinary(n-1, output+"0") +
					countBinary(n-1, output+"1");
	}
	else{
		count = countBinary(n-1, output+"0");
	}
	return count;
}


int main(int argc, char const *argv[])
{
	int n=2;
	int count0 = countBinary(n-1, "0");
	int count1 = countBinary(n-1, "1");
	int totalCount = count0+count1;
	cout<<totalCount<<endl;

	return 0;
}











