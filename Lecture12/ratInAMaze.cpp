#include <iostream>
using namespace std;
bool isSafe(int board[10][10], int row, int col, int i, int j) {

	if ( i >= 0 && i < row && j >= 0 && j < col && board[i][j] == 0) {
		return true;
	}
	return false;
}
// if any path exist
bool ratInMaze(int board[10][10], int row, int col, int i, int j) {
	if(i == row-1 && j==col-1){
		return true;
	}
	if(isSafe(board, row, col, i, j)){
		// move horizontal
		bool Hresult = ratInMaze(board, row, col, i, j+1);
		if(Hresult){
			return true;
		}
		// move vertical;
		bool Vresult = ratInMaze(board, row, col, i+1, j);
		if(Vresult){
			return true;
		}
		return false;
	}
	return false;

}

int main(int argc, char const *argv[])
{

	int board[10][10] = {{0,0,0,1},
					   {0,0,1,0},
					   {0,0,0,1},
					   {1,0,1,0},
					   {0,0,1,0}};

	bool result = ratInMaze(board, 5, 4, 0,0);
	if(result){
		cout<<"path exist"<<endl;
	}
	else{
		cout<<"path doesn't exist"<<endl;
	}


	return 0;
}






