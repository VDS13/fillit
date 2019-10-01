/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnichol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:58:11 by dnichol           #+#    #+#             */
/*   Updated: 2019/10/01 16:08:31 by dnichol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_error(void)
{
	ft_putstr_fd("error", 2);
	ft_putchar_fd('\n', 1);
	return (NULL);
}

int		check_filename(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (str[i] != '.')
		i++;
	i++;
	dest = ft_strdup("fillit");
	while (dest[j])
	{
		if (dest[j] != str[i])
			return (0);
		i++;
		j++;
	}
	free(dest);
	return (1);
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
		while (line[i][j] != '\0')
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
