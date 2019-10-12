/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slate_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:13:39 by dnichol           #+#    #+#             */
/*   Updated: 2019/10/10 16:27:19 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board		**copy_set(t_board **set, int size)
{
	int		j;
	t_board	**new_set;

	j = 0;
	new_set = (t_board**)malloc(sizeof(t_board *) * size);
	while (j < size)
	{
		new_set[j] = copy_board(set[j]);
		j = j + 1;
	}
	return (new_set);
}

t_state		*new_state(t_board *current_board,
		t_board *checked_tiles, t_board *current_item)
{
	t_state *new;

	new = (t_state*)malloc(sizeof(t_state));
	if (current_board)
		new->current_board = copy_board(current_board);
	else
	{
		new->current_board = new_board(current_board->side, 'X');
	}
	if (checked_tiles)
		new->checked_tiles = copy_board(checked_tiles);
	else
	{
		new->checked_tiles = new_board(current_board->side, 'x');
	}
	new->current_item = copy_board(current_item);
	return (new);
}

t_state		*generate_next_state(t_state *s, t_board *item)
{
	t_state *new;
	t_point *point;

	new = new_state(s->current_board, NULL, item);
	point = closest_unchecked_dumb(s->checked_tiles);
	while (point)
	{
		if (place_on_the_board(&(new)->current_board,
					item, point, item->symbol))
		{
			s->checked_tiles->state[point->x][point->y] = 'x';
			free(point);
			return (new);
		}
		else
		{
			s->checked_tiles->state[point->x][point->y] = 'x';
			free(point);
			point = closest_unchecked_dumb(s->checked_tiles);
		}
	}
	free(point);
	wipe_state(&new);
	return (NULL);
}
