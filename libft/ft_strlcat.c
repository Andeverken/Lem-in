/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:22:23 by rfernand          #+#    #+#             */
/*   Updated: 2015/12/18 13:18:02 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int n;
	int j;
	int u;

	i = ft_strlen(dst);
	n = ft_strlen(src);
	j = size;
	size--;
	u = 0;
	if (i > (int)size)
		return (j + n);
	while (dst[u] && size--)
		u++;
	if (j == i + n)
		while (size-- && *src)
			dst[u++] = *src++;
	else
		while (size--)
			dst[u++] = *src++;
	dst[u] = '\0';
	return (i + n);
}
