#include<bits/stdc++.h>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int num, int n)
{
	//check for row and column
	for (int k = 0; k < n; k++)
	{
		if (mat[k][j] == num || mat[i][k] == num)
			return false;
	}

	//check for subgrid
	int sx = (i / 3) * 3;
	int sy = (j / 3) * 3;

	for (int x = sx; x < sx + 3; x++)
	{
		for (int y = sy; y < sy + 3; y++)
		{
			if (mat[x][y] == num)
				return false;
		}
	}
	return true;
}

bool solveSudoku(int mat[][9], int i, int j , int n)
{
	//base case
	if (i == n)
	{
		//print solution
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << mat[i][j] << " ";
			}

			cout << endl;
		}

		return true;
	}

	//rec case
	if (j == n)
	{
		return solveSudoku(mat, i + 1, 0, n);
	}

	//skip the prefilled cell
	if (mat[i][j] != 0)
	{
		return solveSudoku(mat, i, j + 1, n);
	}

	//cell to be filled
	for (int num = 1; num <= 9; num++)
	{
		//check whether it is safe to place the number in cell or not
		if (isSafe(mat, i, j, num, n))
		{
			mat[i][j] = num;
			bool solveSubproblem = solveSudoku(mat, i, j + 1, n);
			if (solveSubproblem == true)
			{
				return true;
			}
		}
	}

	//if no option works - Backtracking
	mat[i][j] = 0;
	return false;

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 9;
	int mat[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	if (!solveSudoku(mat, 0, 0, n))
	{
		cout << "NO Solution exists !";
	}
	return 0;
}