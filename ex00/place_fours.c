#include "header.h"

int place_fours_up(int **board, int *sights)
{
	int col;
	int row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		if (sights[col] == 4)
		{
			while (row < 4)
			{
				if ((board[row][col] != row + 1 && board[row][col] != 0)
				|| check_both_unique(board))
					return (1);
				else
				{
					board[row][col] = row + 1;
				}
				row++;
			}
		}
		col++;
	}
	return (0);
}

int	place_fours_down(int **board, int *sights)
{
	int	col;
	int	row;

	col = 4;
	while (col < 8)
	{
		row = 0;
		if (sights[col] == 4)
		{
			while (row < 4)
			{
				if ((board[row][col - 4] != row + 1 && board[row][col - 4] != 0) 
				|| check_both_unique(board))
				{
					return (1);
				}
				else
				{
					board[row][col - 4] = row + 1;
				}
				row++;
			}
		}
		col++;
	}
	return 0;
}

int	place_fours_left(int **board, int *sights)
{
	int	row;
	int	col;

	row = 8;
	while (row < 12)
	{
		col = 0;
		if (sights[row] == 4)
		{
			while (col < 4)
			{
				if ((board[row - 8][col] != col + 1 && board[row-8][col] != 0)
				|| check_both_unique(board))
				{
					return (1);
				}
				else
				{
					board[row - 8][col] = col + 1;
				}
				board[row - 8][col] = col + 1;
				col++;
			}
		}
		row++;
	}
	return (0);
}

int	place_fours_right(int **board, int *sights)
{
	int	row;
	int	col;

	row = 12;
	while (row < 16)
	{
		col = 0;
		if (sights[row] == 4)
		{
			while (col < 4)
			{
				if ((board[row - 12][col] != col + 1
				&& board[row - 12][col] != 0)
				|| check_both_unique(board))
				{
					return (1);
				}
				else
				{
					board[row - 12][col] = col + 1;
				}
				board[row - 12][col] = col + 1;
				col++;
			}
		}
		row++;
	}
	return (0);
}

int	place_fours(int **board, int *sights)
{
	return (place_fours_up(board, sights)
		|| place_fours_down(board, sights)
		|| place_fours_left(board, sights)
		|| place_fours_right(board, sights));
}
