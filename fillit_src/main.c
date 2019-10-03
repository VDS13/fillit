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
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**line;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
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
	printf("GOOD");
	return (0);
}
