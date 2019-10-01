/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnichol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:37:36 by dnichol           #+#    #+#             */
/*   Updated: 2019/10/01 18:14:51 by dnichol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const char *g_slates[19] = {"####............", "#...#...#...#...",
	".#..###.........", "#...##..#.......", ".#..##...#......",
	"###..#..........", "##..##..........", "#...#...##......",
	"..#.###.........", "##...#...#......", "###.#...........",
	".##.##..........", "#...##...#......", ".#...#..##......",
	"###...#.........", "##..#...#.......", "#...###.........",
	"##...##.........", ".#..##..#......."};

static int	check_last(const char *str, char **line, int i, int j)
{
	int l;
	int m;

	l = 0;
	m = 0;
	while (line[i] && i < 4)
	{
		j = 0;
		while (line[i][j] && str[l])
		{
			if (str[l] == line[i][j++])
			{
				if (str[l] == '#')
					m++;
				l++;
			}
			else
				break ;
		}
		if (j != 4)
			break ;
		i++;
	}
	if (m == 4)
		return (1);
	return (0);
}

static int	check_p(const char *str, char **line)
{
	int	i;
	int	j;
	int l;

	i = 0;
	l = 0;
	while (line[i] && i < 4)
	{
		j = 0;
		while (line[i][j] && str[l])
		{
			if (str[l] == line[i][j])
				if (check_last(str, line, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_one(char **line)
{
	int	k;

	k = 0;
	while (g_slates[k])
	{
		if (!check_p(g_slates[k], line))
			k++;
		else
			return (1);
	}
	return (0);
}

int			check_tetr(char **line)
{
	int	i;
	int	k;

	i = 0;
	while (line[i])
		i++;
	k = (i + 1) / 5;
	i = 0;
	while (i < k)
	{
		if (!check_one(line + 4 * i + i))
			break ;
		i++;
	}
	if (i != k)
		return (0);
	return (1);
}
