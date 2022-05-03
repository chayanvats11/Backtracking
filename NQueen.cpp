#include<bits/stdc++.h>
using namespace std;

bool canPlace(int board[][20], int n, int x, int y)
{
	//Column - This searches for Queen in the column where current Queen is placed but only till that row only therefore k is less than x
	for (int k = 0; k < x; k++)
	{
		if (board[k][y] == 1)
			return false;
	}

	//Left Diagnol - This searches for any Queen in left diagnol whose lower bound coordinate is (0,0) and upper bound coordinate is (i,j)
	int i = x;
	int j = y;

	while (i >= 0 and j >= 0)
	{
		if (board[i][j] == 1)
			return false;

		i--;
		j--;
	}

	//Right Diagnol - This searches for any Queen in right diagnol whose lower bound coordinate is (i,j) and upper bound coordinate is (0,n)
	i = x;
	j = y;

	while (i >= 0 and j < n)
	{
		if (board[i][j] == 1)
			return false;

		i--;
		j++;
	}

	return true;
}

void printBoard(int n, int board[][20])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}
bool solveNQueen(int n, int board[][20], int i)
{
	//base case
	if (i == n)
	{
		//Print the board
		printBoard(n, board);
		return true;
	}

	//rec case
	//trying to place a queen in every way
	for (int j = 0; j < n; j++)
	{
		//whether j is safe position or not to place the queen
		if (canPlace(board, n, i, j))
		{
			board[i][j] = 1; // Queen is successfully placed
			bool success = solveNQueen(n, board, i + 1);
			if (success)
			{
				return true;
			}

			//backtrack
			board[i][j] = 0; // Queen cannot be placed at current block therefore move one column forward in same row
		}
	}

	return false; // tells the parent row that No Queen can be placed in current row so go back and check parent row config of Queen placement
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int board[20][20] = {0};
	int n;
	cin >> n;

	solveNQueen(n, board, 0);


	return 0;
}