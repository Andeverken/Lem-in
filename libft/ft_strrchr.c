/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:10:05 by rfernand          #+#    #+#             */
/*   Updated: 2015/11/27 11:55:28 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	if (!c)
		return ((char*)s);
	while (i && *s != c)
	{
		s--;
		i--;
	}
	if (*s && *s == c)
		return ((char*)s);
	else
		return (NULL);
}
