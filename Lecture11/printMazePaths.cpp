#include<bits/stdc++.h>
using namespace std;

void printMazePaths(int i, int j, int r, int c, string output){

	if(i == r-1 && j==c-1){//possible path
		cout<<output<<endl;
		return;
	}
	if( i > r-1 || j> c-1){
		return;
	}

	//horizontal
	printMazePaths(i, j+1, r, c, output+"H");
	//vertical
	printMazePaths(i+1, j, r, c, output+"V");

}
int main(int argc, char const *argv[])
{
	int r,c;
	cin>>r>>c;
	printMazePaths(0,0,r,c,"");

	return 0;
}
//H.W -> count maze paths

