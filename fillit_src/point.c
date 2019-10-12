/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:55:59 by lcaesar           #+#    #+#             */
/*   Updated: 2019/10/09 18:00:51 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*new_point(int x, int y)
{
	t_point	*point;

	point = malloc(sizeof(point));
	point->x = x;
	point->y = y;
	return (point);
}

t_point		*closest_unchecked_dumb(t_board *board)
{
	int	j;
	int	k;

	j = 0;
	while (j < board->side)
	{
		k = 0;
		while (k < board->side)
		{
			if (board->state[j][k] == '.')
				return (new_point(j, k));
			k = k + 1;
		}
		j = j + 1;
	}
	return (NULL);
}
