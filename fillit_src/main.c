/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnichol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:51:58 by dnichol           #+#    #+#             */
/*   Updated: 2019/10/03 16:19:05 by dnichol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

board **copy_set(board **set, int size)
{
    int j = 0;
    board **new_set = malloc(sizeof(board *) * size);
    while (j < size)
    {
        new_set[j] = copy_board(set[j]);
        j = j + 1;
    }
    return (new_set);
}

int	main(int ac, char **av)
{
	char	**line;
	int		n;

	n = 0;
	if (ac != 2)
	{
		ft_error();
		return (0);
	}
	else
	{
		line = read_fillit(av[1]);
		if (line == NULL)
			return (0);
	}
	while (line[n])
		n++;
	int board_size = minimum_square_side(n);
    board **set = malloc(sizeof(board *) * n);
    board **original_set = malloc(sizeof(board *) * n);
    int j = 0;
    while (j < n)
    {
        set[j] = string_to_board(4, line[j], 'A' + j);
        original_set[j] = string_to_board(4, line[j], 'A' + j);
        j = j + 1;
    }    
    board *current_board = new_board(board_size, 'X');
    board *checked_tiles = new_board(board_size, 'x');
    point *current_point;
    int m; 
    while (board_size < THEORETICAL_MAX)
    {
        current_board = wipe_and_resize(&current_board, board_size);
        checked_tiles = wipe_and_resize(&checked_tiles, board_size);
        permute_new(NULL, 0, NULL, 1);
        set = copy_set(original_set, n);
        while (permute_new(set, n, swap_strings_wow, 0))
        {
            m = 0;
            reset_board(&current_board);
            reset_board(&checked_tiles);
            while (1)
            {
                if (m == n)
                {
                    print_board(current_board);
                    return (1);
                }
                current_point = closest_unchecked(current_board, checked_tiles);
                if (current_point)
                    checked_tiles->state[current_point->x][current_point->y] = 'x';
                else
                {
                    break ;
                }
                if(!place_on_the_board(&current_board, set[m], current_point, (set[m])->symbol))
                {
                    checked_tiles->state[current_point->x][current_point->y] = 'x';
                    continue ;
                }
                m = m + 1;
            }
        }
        board_size = board_size + 1;
    }
	return (0);
}
