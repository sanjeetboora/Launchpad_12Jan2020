#include <iostream>
using namespace std;

bool isSafe(int board[10][10], int i, int j, int n) {
	int r = i, c = j;

	//column
	r = i - 1; c = j;
	while (r >= 0) {
		if (board[r][c] == 1) {
			return false;
		}
		r--;
	}

	// right diagonal
	r = i, c = j;
	while ( r >= 0 && c < n) {
		if (board[r][c] == 1) {
			return false;
		}
		r--;
		c++;
	}
	//left diagonal
	r = i, c = j;
	while ( r >= 0 && c >= 0) {
		if (board[r][c] == 1) {
			return false;
		}
		r--;
		c--;
	}
	return true;
}

void print(int board[10][10], int n) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j]) {
				cout << "Q";
			}
			else {
				cout << "_";
			}
		}
		cout << endl;
	}
}
bool nQueen(int board[10][10], int n, int row) {
	if (row == n) {
		print(board, n);
		return true;
	}

	for (int col = 0; col < n; col++)
	{
		if (isSafe(board, row, col, n)) {
			board[row][col] = 1;
			bool queenRakhPaye = nQueen(board, n, row + 1);
			if (queenRakhPaye) {
				return true;
			}
			board[row][col] = 0;
		}
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int board[10][10] = {0};
	int n = 4;

	nQueen(board,  n, 0);
	return 0;
}
























