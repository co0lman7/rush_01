/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlindhajdari <arlindhajdari@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:42:59 by kostin.floq       #+#    #+#             */
/*   Updated: 2025/08/03 13:53:38 by arlindhajda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_input(int *arr, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4')
		{
			arr = NULL;
			free(arr);
			break ;
		}
		arr[j++] = str[i++] - '0';
		if (str[i] != ' ' && str[i] != '\0')
		{
			arr = NULL;
			free(arr);
			break ;
		}
		if (str[i] != '\0')
			i++;
	}
}

void	populate(int **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		board[i] = malloc(sizeof(int) * 4);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	show_board(int **board)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
			{
				write(1, " ", 1);
			}
			else
			{
				write(1, "\n", 1);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[]) // argc = 2, len(argv) - [program_name = 0, args > 0]
{
	int	*sights;
	int	**board;

	sights = malloc(sizeof(int) * 16);
	board = malloc(sizeof(int *) * 4);
	if (argc != 2)
	{
		write(2, "Error\n", 6); // either no args passed, or too many passed
		return (0);
	}
	check_input(sights, argv[1]);
	if (sights == NULL)
		write(2, "Error\n", 6);
	else
	{
		populate(board);
		if (place_fours(board, sights) || place_ones(board, sights))
			write(2, "Error\n", 6);
		else if (solve_board(board, sights, 0, 0))
			show_board(board);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}

/*
0-3 - Up, 4-7 - Down, 8-11 - Left, 12-15 - Right
cc -Wall -Wextra -Werror -o rush-01 *.c, takes all files that end with .c
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
*/
