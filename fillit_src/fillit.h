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

char	**ft_error(void);
char	**check_tetr(char **line);
int		check_valfile(char **line);
int		check_valfile_p2(char **line);
char	**read_fillit(char *str);
void	freem(char **line);

#endif
