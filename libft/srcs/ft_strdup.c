/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnichol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:23:26 by dnichol           #+#    #+#             */
/*   Updated: 2019/09/21 12:58:55 by dnichol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char *dest;

	if (!(dest = ft_strnew(ft_strlen(src))))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
