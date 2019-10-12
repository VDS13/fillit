/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:14:53 by dnichol           #+#    #+#             */
/*   Updated: 2019/10/10 19:20:50 by dnichol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	size_mat(size_t size)
{
	if (size <= 20)
		return (5);
	else
		return (size / 4 + size / 16 - 1);
}

static size_t	size_file(char *str)
{
	size_t	size;
	char	c[BUFF_SIZE + 1];
	int		fd;
	int		n;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	size = 0;
	while ((n = read(fd, c, 1)) > 0)
	{
		size = size + (size_t)n;
		if (size + 1 < size)
			return (0);
	}
	close(fd);
	return (size);
}

static char		**read_from_file(const int fd, size_t size)
{
	char	**buff;
	int		i;
	int		n;

	i = 0;
	n = 1;
	buff = (char**)malloc(sizeof(char*) * size_mat(size));
	while (n)
	{
		n = get_next_line(fd, &buff[i]);
		if (n == -1)
		{
			ft_freemat(buff, i);
			return (NULL);
		}
		i++;
	}
	buff[i - 1] = NULL;
	return (buff);
}

char			**read_fillit(char *str)
{
	int		fd;
	size_t	size;
	char	**line;
	char	**dest;

	line = NULL;
	size = size_file(str);
	if (size)
	{
		fd = open(str, O_RDONLY);
		if (fd < 0)
			return (ft_error());
		line = read_from_file(fd, size);
		if (line == NULL)
			return (ft_error());
		if (!check_valfile(line) || !check_valfile_p2(line) ||
				!check_valfile_p3(line) || !(dest = check_tetr(line)))
			return (ft_error());
	}
	else
		return (ft_error());
	freem(line);
	return (dest);
}
