#include <iostream>
using namespace std;
bool isSafe(int board[10][10], int row, int col, int i, int j) {

	if ( i >= 0 && i < row && j >= 0 && j < col && board[i][j] == 0) {
		return true;
	}
	return false;
}
// print the existing path
bool ratInMaze(int board[10][10], int row, int col, int i, int j, string output) {
	if (i == row - 1 && j == col - 1) {
		cout<<output<<endl;
		return true;
	}
	if (isSafe(board, row, col, i, j)) {
		// move horizontal
		bool Hresult = ratInMaze(board, row, col, i, j + 1, output + "H");
		if (Hresult) {
			return true;
		}
		// move vertical;
		bool Vresult = ratInMaze(board, row, col, i + 1, j, output+"V");
		if (Vresult) {
			return true;
		}
		return false;
	}
	return false;

}
void print(int board[10][10], int row, int col) {
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (board[i][j]) {
				cout << "1";
			}
			else {
				cout << "_";
			}
		}
		cout << endl;
	}
	cout<<"-----------------"<<endl;
}

bool ratInMazeMatrix(int board[10][10], int row, int col, int i, int j, int solution[10][10]) {
	if (i == row - 1 && j == col - 1) {
		solution[i][j] = 1;
		print(solution, row, col);
		return true;
	}
	if (isSafe(board, row, col, i, j)) {
		solution[i][j] = 1;
		// move horizontal
		bool Hresult = ratInMazeMatrix(board, row, col, i, j + 1, solution);
		if (Hresult) {
			return true;
		}
		// move vertical;
		bool Vresult = ratInMazeMatrix(board, row, col, i + 1, j, solution);
		if (Vresult) {
			return true;
		}

		solution[i][j] = 0;
		return false;
	}
	return false;

}

int main(int argc, char const *argv[])
{

	int board[10][10] = {{0, 0, 0, 1},
		{0, 0, 1, 0},
		{0, 0, 0, 1},
		{1, 0, 0, 0},
		{0, 0, 1, 0}
	};
	int sol[10][10]= {0};

	//bool result = ratInMaze(board, 5, 4, 0, 0,"");
	bool result = ratInMazeMatrix(board, 5, 4, 0, 0,sol);
	if (result) {
		cout << "path exist" << endl;
	}
	else {
		cout << "path doesn't exist" << endl;
	}
	return 0;
}

//H.W -> Print all possible paths for rat






