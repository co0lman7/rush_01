/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_fours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostin.floqi <kostin.floqi@learner.42.tec  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:46:19 by kostin.floqi      #+#    #+#             */
/*   Updated: 2025/08/03 10:46:20 by kostin.floqi     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	place_fours_up(int **board, int *sights)
{
	int	col;
	int	row;

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
				if ((board[row][col - 4] != 4 - row && board[row][col - 4] != 0)
				|| check_both_unique(board))
					return (1);
				else
				{
					board[row][col - 4] = 4 - row;
				}
				row++;
			}
		}
		col++;
	}
	return (0);
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
				if ((board[row - 8][col] != col + 1 && board[row - 8][col] != 0)
				|| check_both_unique(board))
					return (1);
				else
				{
					board[row - 8][col] = col + 1;
				}
				col++;
			}
		}
		row++;
	}
	return (0);
}

int	place_fours_right(int **brd, int *sights)
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
				if ((brd[row - 12][col] != 4 - col && brd[row - 12][col] != 0)
				|| check_both_unique(brd))
					return (1);
				else
				{
					brd[row - 12][col] = 4 - col;
				}
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
