/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnichol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:58:11 by dnichol           #+#    #+#             */
/*   Updated: 2019/10/03 16:19:34 by dnichol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	freem(char **line)
{
   	int i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

char	**ft_error(void)
{
	ft_putstr_fd("error", 1);
	ft_putchar_fd('\n', 1);
	return (NULL);
}

int		check_valfile(char **line)
{
	int	i;
	int	j;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
	{
		j = 0;
		while (line[i][j] != '\0')
		{
			if (line[i][j] != '.' && line[i][j] != '#')
				return (0);
			j++;
		}
		if ((i - 4) % 5 != 0)
			if (j != 4)
				return (0);
		if ((i - 4) % 5 == 0)
			if (j != 0)
				return (0);
		i++;
	}
	return (1);
}

int		check_valfile_p2(char **line)
{
	int	i;
	int	j;
	int ch;

	i = 0;
	ch = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] == '#')
				ch++;
			j++;
		}
		i++;
		if ((i - 4) % 5 == 0)
		{
			if (ch != 4)
				return (0);
			else
				ch = 0;
		}
	}
	return (1);
}
