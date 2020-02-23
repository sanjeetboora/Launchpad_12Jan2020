#include<bits/stdc++.h>
using namespace std;

int countPaths(int start, int end){
	if(start == end){//possible path
		return 1;
	}
	if(start >  end){// wrong path
		return 0;
	}
	int count =0;
	for (int dice = 1; dice <= 6; dice++)
	{
		count += countPaths(start + dice, end);
	}
	return count;

}

int main(int argc, char const *argv[])
{
	int start = 0;
	int end;
	cin>>end;
	cout<<countPaths(start, end)<<endl;
	return 0;
}
//H.W -> print all board paths