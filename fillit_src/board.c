/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:26:04 by dnichol           #+#    #+#             */
/*   Updated: 2019/10/10 16:44:36 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board		*new_board(int side, char symbol)
{
	int		j;
	int		k;
	t_board	*board;

	board = (t_board*)malloc(sizeof(t_board));
	board->side = side;
	board->state = malloc(side * sizeof(char *));
	board->symbol = symbol;
	j = 0;
	while (j < side)
	{
		board->state[j] = malloc(side * sizeof(char));
		k = 0;
		while (k < side)
		{
			board->state[j][k] = '.';
			k = k + 1;
		}
		j = j + 1;
	}
	return (board);
}

void		reset_board(t_board **board)
{
	int	j;
	int	k;

	j = 0;
	while (j < (*board)->side)
	{
		k = 0;
		while (k < (*board)->side)
		{
			(*board)->state[j][k] = '.';
			k = k + 1;
		}
		j = j + 1;
	}
}

t_board		*copy_board(t_board *old_board)
{
	int		j;
	int		k;
	t_board	*board;

	board = new_board(old_board->side, old_board->symbol);
	j = 0;
	while (j < board->side)
	{
		k = 0;
		while (k < board->side)
		{
			board->state[j][k] = old_board->state[j][k];
			k = k + 1;
		}
		j = j + 1;
	}
	return (board);
}

int			print_board(t_board *board)
{
	int	j;
	int	k;

	if (!board)
		return (0);
	j = 0;
	while (j < board->side)
	{
		k = 0;
		while (k < board->side)
		{
			write(1, &(board->state[j][k]), 1);
			k = k + 1;
		}
		j = j + 1;
		write(1, "\n", 1);
	}
	return (1);
}

t_board		*string_to_board(int side, const char *string, char symbol)
{
	int		j;
	int		k;
	int		m;
	t_board	*board;

	board = new_board(side, symbol);
	j = 0;
	m = 0;
	while (j < side)
	{
		k = 0;
		while (k < side)
		{
			if (string[m] != '.')
				board->state[j][k] = symbol;
			k = k + 1;
			m = m + 1;
		}
		j = j + 1;
	}
	return (board);
}
