/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnichol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:21:11 by dnichol           #+#    #+#             */
/*   Updated: 2019/10/03 16:11:09 by dnichol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# define THEORETICAL_MAX 13

typedef struct  board
{
	int         side;
    char        symbol;
	char        **state;
}               board;

typedef struct  point
{
    int x;
    int y;
}               point;


void    swap_letters(void *set, int j, int k);
void    swap_strings_wow(void *set, int j, int k);
int     get_int_array(int **array, int size);
int     permute(void *set, int size, void (*swap)(void *, int, int), int reset);

int     minimum_square_side(int number_of_items);
point   *new_point(int x, int y);
point   *closest_unchecked(board *board, struct board *checked_cells);

board   *new_board(int side, char symbol);
void    reset_board(board **board);
void    wipe_board(board **board);
board   *wipe_and_resize(board **board, int new_size);
board   *copy_board(board *old_board);
board   *string_to_board(int side, const char *string, char symbol);
int     place_on_the_board(board **board, struct board *item, point *point, char c);

void    print_board(board *board);

void    how_about_that(char *set, int size);
void    how_about_this(char *set, int size);
void    maybe_this(char *set, int size, char **permutation, int depth, char *original);
int     permute_new(void *set, int size, void (swap)(void *, int, int), int reset);

char	**ft_error(void);
char	**check_tetr(char **line);
int		check_valfile(char **line);
int		check_valfile_p2(char **line);
char	**read_fillit(char *str);
void	freem(char **line);

#endif
