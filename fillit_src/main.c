/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:51:58 by dnichol           #+#    #+#             */
/*   Updated: 2019/10/10 18:06:00 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	useless(t_board ***o, int n)
{
	int j;

	j = 0;
	while (j < n)
	{
		wipe_board(&o[0][j]);
		wipe_board(&o[1][j]);
		j = j + 1;
	}
	free(o[0]);
	free(o[1]);
	free(o);
}

static void	fillit_end(t_board ***o, int b, int n)
{
	static t_board	*current_board;
	static t_board	*checked_tiles;
	t_state			*s;
	int				m;

	m = 0;
	while (b < THEORETICAL_MAX)
	{
		m = 0;
		current_board = wipe_resize_and_set(&current_board, b, 'X');
		checked_tiles = wipe_resize_and_set(&checked_tiles, b, 'x');
		s = new_state(current_board, checked_tiles, o[0][0]);
		permute_new(NULL, 0, NULL, 1);
		absolutely_useless(o[0], n);
		o[0] = copy_set(o[1], n);
		if (fillit_cmon(s, o[0], n, 0))
		{
			useless(o, n);
			wipe_state(&s);
			break ;
		}
		wipe_state(&s);
		b = b + 1;
	}
}

static void	fillit(char **l, int n)
{
	t_board	***o;
	t_board	**board;
	int		board_size;
	int		j;

	o = (t_board***)malloc(sizeof(t_board **) * 2);
	o[0] = (t_board**)malloc(sizeof(t_board *) * n);
	o[1] = (t_board**)malloc(sizeof(t_board *) * n);
	j = 0;
	while (j < n)
	{
		o[0][j] = string_to_board(4, l[j], 'A' + j);
		o[1][j] = string_to_board(4, l[j], 'A' + j);
		j = j + 1;
	}
	freem(l);
	board_size = minimum_square_side(n);
	fillit_end(o, board_size, n);
}

int			fillit_cmon(t_state *s, t_board **set, int set_size, int m)
{
	t_state *initial_state;
	t_state *current_state;
	t_state *temporary;

	if (m == set_size)
		return (print_board(s->current_board));
	initial_state = s;
	current_state = generate_next_state(s, set[m]);
	while (current_state)
	{
		if (fillit_cmon(current_state, set, set_size, m + 1) == 1)
		{
			wipe_state(&current_state);
			return (1);
		}
		else
		{
			temporary = current_state;
			current_state = generate_next_state(current_state, set[m]);
			wipe_state(&temporary);
			if (!current_state)
				return (fillit_cmon(initial_state, set, set_size, m));
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	char	**line;
	int		n;
	int		i;

	n = 0;
	if (ac == 2)
	{
		line = read_fillit(av[1]);
		if (line == NULL)
			return (0);
		while (line[n])
			n++;
		fillit(line, n);
	}
	else
		ft_putstr("usage: ./fillit file\n");
	return (0);
}
