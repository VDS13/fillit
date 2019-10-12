/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:36:41 by lcaesar           #+#    #+#             */
/*   Updated: 2019/10/10 16:30:59 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		absolutely_useless(t_board **set, int n)
{
	int j;

	j = 0;
	while (j < n)
	{
		wipe_board(&set[j]);
		j = j + 1;
	}
	free(set);
}

void		wipe_board(t_board **board)
{
	int j;

	j = 0;
	while (j < (*board)->side)
	{
		ft_strdel(&(*board)->state[j]);
		j = j + 1;
	}
	free((*board)->state);
	free(*board);
	*board = NULL;
}

t_board		*wipe_and_resize(t_board **board, int new_size)
{
	t_board	*new_item;

	new_item = new_board(new_size, (*board)->symbol);
	wipe_board(board);
	return (new_item);
}

t_board		*wipe_resize_and_set(t_board **board, int new_size, char symbol)
{
	t_board *new_item;

	if (!*board)
	{
		return (new_board(new_size, symbol));
	}
	new_item = new_board(new_size, symbol);
	wipe_board(board);
	return (new_item);
}

void		wipe_state(t_state **state)
{
	wipe_board(&((*state)->current_board));
	wipe_board(&((*state)->checked_tiles));
	wipe_board(&((*state)->current_item));
	free(*state);
	*state = NULL;
}
