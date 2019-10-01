/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnichol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:24:51 by dnichol           #+#    #+#             */
/*   Updated: 2019/09/11 13:29:55 by dnichol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 != NULL && s2 != NULL)
	{
		dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (dest != NULL)
		{
			while (s1[i] != '\0')
			{
				dest[i] = s1[i];
				i++;
			}
			while (s2[j] != '\0')
				dest[i++] = s2[j++];
			return (dest);
		}
		else
			return (NULL);
	}
	return (NULL);
}
