/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlind.hajdari <arlind.hajdari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:42:49 by kostin.floq       #+#    #+#             */
/*   Updated: 2025/08/03 00:40:25 by arlind.hajd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>

int	check_both_unique(int **board);
int	place_fours(int **board, int *sights);
int	place_ones(int **board, int *sights);
int	solve_board(int **board, int *sights, int row, int col);
int	check_sight(int **board, int *sights);

#endif
