/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see_and_solve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlindhajdari <arlindhajdari@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 00:03:10 by arlind.hajd       #+#    #+#             */
/*   Updated: 2025/08/03 13:41:26 by arlindhajda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	visible_count(int *line) // counts the number of buildings seen from a specific POV, returns count
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_col_sight(int **board, int *sights, int *temp) //temp - array 1x4
{
	int	col;
	int	i;

	col = 0;
	while (col < 4)
	{
		i = 0;
		while (i < 4)
		{
			temp[i] = board[i][col]; //saves the column values in an array
			i++;
		}
		if (sights[col] && visible_count(temp) != sights[col]) //if sights from up is not equal to the parameter/hint/clue, returns 1 (invalid) and stops
			return (1);
		i = 0;
		while (i < 4)
		{
			temp[i] = board[3 - i][col];
			i++;
		}
		if (sights[4 + col] && visible_count(temp) != sights[4 + col]) //if sights from down is not equal to the parameter/hint/clue, returns 1 (invalid) and stops
			return (1);
		col++;
	}
	return (0); // every column has the correct values
}

int	check_row_sight(int **board, int *sights, int *temp)
{
	int	row;
	int	i;

	row = 0;
	while (row < 4)
	{
		i = 0;
		while (i < 4)
		{
			temp[i] = board[row][i];
			i++;
		}
		if (sights[8 + row] && visible_count(temp) != sights[8 + row])
			return (1);
		i = 0;
		while (i < 4)
		{
			temp[i] = board[row][3 - i];
			i++;
		}
		if (sights[12 + row] && visible_count(temp) != sights[12 + row])
			return (1);
		row++;
	}
	return (0);
}

int	check_sight(int **board, int *sights)
{
	int	temp[4];

	if (check_col_sight(board, sights, temp))
		return (1);
	if (check_row_sight(board, sights, temp)) // combined via an OR operator
		return (1);
	return (0);
}

int	solve_board(int **board, int *sights, int row, int col)
{
	int	num;

	if (row == 4)
	{
		if (check_sight(board, sights) == 0)
			return (1); // if sights are correct, return 1 (True)
		return (0);
	}
	if (col == 4)
		return (solve_board(board, sights, row + 1, 0));
	if (board[row][col] != 0)
		return (solve_board(board, sights, row, col + 1));
	num = 1;
	while (num <= 4)
	{
		board[row][col] = num;
		if (check_both_unique(board) == 0)
		{
			if (solve_board(board, sights, row, col + 1))
				return (1);
		}
		board[row][col] = 0;
		num++;
	}
	return (0);
}
