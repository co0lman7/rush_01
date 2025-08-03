/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_row_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlind.hajdari <arlind.hajdari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:15:22 by arlind.hajd       #+#    #+#             */
/*   Updated: 2025/08/02 17:22:39 by arlind.hajd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_row_unique(int **board)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j < 4)
		{
			k = j + 1;
			while (k < 4)
			{
				if (board[j][i] == board[k][i] && board[j][i] != 0)
				{
					return (1);
				}
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_col_unique(int **board)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = j + 1;
			while (k < 4)
			{
				if (board[j][i] == board[k][i] && board[j][i] != 0)
				{
					return (1);
				}
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_both_unique(int **board)
{
	return (check_col_unique(board) || check_row_unique(board));
}
