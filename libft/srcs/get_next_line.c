/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnichol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:45:02 by dnichol           #+#    #+#             */
/*   Updated: 2019/09/21 12:25:09 by dnichol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_modstrdup(char **line, char **dest, const int fd)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (dest[fd][i] != '\n' && dest[fd][i] != '\0')
		i++;
	if (dest[fd][i] == '\n')
	{
		*line = ft_strsub(dest[fd], 0, i);
		temp = ft_strsub(dest[fd], i + 1, ft_strlen(dest[fd]) - i);
		free(dest[fd]);
		dest[fd] = ft_strdup(temp);
		free(temp);
	}
	else
	{
		*line = ft_strdup(dest[fd]);
		ft_strdel(&dest[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char *dest[256];
	int			n;
	char		c[BUFF_SIZE + 1];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((n = read(fd, c, BUFF_SIZE)) > 0)
	{
		c[n] = '\0';
		if (dest[fd] == NULL)
			dest[fd] = ft_strnew(1);
		temp = ft_strjoin(dest[fd], c);
		free(dest[fd]);
		dest[fd] = temp;
		if (ft_strchr(dest[fd], '\n'))
			break ;
	}
	if (n == -1)
		return (-1);
	if (n == 0 && (dest[fd] == NULL || dest[fd][0] == '\0'))
		return (0);
	return (ft_modstrdup(line, dest, fd));
}
