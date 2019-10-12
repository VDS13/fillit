/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god_bless_norminette.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:21:00 by lcaesar           #+#    #+#             */
/*   Updated: 2019/10/09 17:25:29 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			minimum_square_side(int number_of_items)
{
	int	n;
	int	number_of_cells;

	n = 1;
	if (number_of_items == 0)
		return (0);
	number_of_cells = number_of_items * 4;
	while (1)
	{
		n = n + 1;
		if (n * n >= number_of_cells)
			return (n);
	}
	return (-1);
}

static int	useless_function(t_board *board)
{
	wipe_board(&board);
	return (0);
}

static int	useless_function2(t_board **board, t_board *save)
{
	wipe_board(board);
	*board = save;
	return (1);
}

int			place_on_the_board(t_board **b,
		t_board *item, t_point *p, char c)
{
	int		j;
	int		k;
	t_board	*save;

	save = copy_board(*b);
	j = -1;
	while (++j < item->side)
	{
		k = -1;
		while (++k < item->side)
		{
			if (item->state[j][k] != '.')
			{
				if (((*b)->side < p->y + k + 1) || ((*b)->side < p->x + j + 1))
					return (useless_function(save));
				if ((*b)->state[j + p->x][k + p->y] != '.')
					return (useless_function(save));
				if ((*b)->state[j + p->x][k + p->y] == '.')
					save->state[j + p->x][k + p->y] = c;
				else
					return (useless_function(save));
			}
		}
	}
	return (useless_function2(b, save));
}
