/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_ones.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlind.hajdari <arlind.hajdari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:38:40 by arlind.hajd       #+#    #+#             */
/*   Updated: 2025/08/02 23:03:14 by arlind.hajd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	place_ones_up(int **board, int *sights)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (sights[col] == 1)
		{
			if (board[0][col] != 0 && board[0][col] != 4)
				return (1);
			board[0][col] = 4;
		}
		col++;
	}
	return (0);
}

int	place_ones_down(int **board, int *sights)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (sights[col + 4] == 1)
		{
			if (board[3][col] != 0 && board[3][col] != 4)
				return (1);
			board[3][col] = 4;
		}
		col++;
	}
	return (0);
}

int	place_ones_left(int **board, int *sights)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (sights[row + 8] == 1)
		{
			if (board[row][0] != 0 && board[row][0] != 4)
				return (1);
			board[row][0] = 4;
		}
		row++;
	}
	return (0);
}

int	place_ones_right(int **board, int *sights)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (sights[row + 12] == 1)
		{
			if (board[row][3] != 0 && board[row][3] != 4)
				return (1);
			board[row][3] = 4;
		}
		row++;
	}
	return (0);
}

int	place_ones(int **board, int *sights)
{
	return (place_ones_up(board, sights)
		|| place_ones_down(board, sights)
		|| place_ones_left(board, sights)
		|| place_ones_right(board, sights));
}
