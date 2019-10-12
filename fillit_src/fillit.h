/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:21:11 by dnichol           #+#    #+#             */
/*   Updated: 2019/10/10 16:42:54 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# include <fcntl.h>
# define THEORETICAL_MAX 13

typedef struct	s_board
{
	int			side;
	char		symbol;
	char		**state;
}				t_board;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_state
{
	t_board		*current_board;
	t_board		*checked_tiles;
	t_board		*current_item;
}				t_state;

void			absolutely_useless(t_board **set, int n);
void			swap_strings_wow(void *set, int j, int k);
int				minimum_square_side(int number_of_items);
t_point			*new_point(int x, int y);
t_point			*closest_unchecked_dumb(t_board *board);
t_board			*new_board(int side, char symbol);
void			reset_board(t_board **board);
void			wipe_board(t_board **board);
void			wipe_state(t_state **state);
t_board			*wipe_and_resize(t_board **board, int new_size);
t_board			*wipe_resize_and_set(t_board **board,
		int new_size, char symbol);
t_board			*copy_board(t_board *old_board);
t_board			*string_to_board(int side, const char *string, char symbol);
int				place_on_the_board(t_board **board,
		t_board *item, t_point *point, char c);
int				print_board(t_board *board);
int				permute_new(void *set, int size,
		void (swap)(void *, int, int), int reset);

t_board			**copy_set(t_board **set, int size);
t_state			*new_state(t_board *current_board,
		t_board *checked_tiles, t_board *current_item);
t_state			*generate_next_state(t_state *state, t_board *item);
int				fillit_cmon(t_state *state, t_board **set, int set_size, int m);

char			**ft_error(void);
char			**check_tetr(char **line);
int				check_valfile(char **line);
int				check_valfile_p2(char **line);
int				check_valfile_p3(char **line);
char			**read_fillit(char *str);
void			freem(char **line);

#endif
