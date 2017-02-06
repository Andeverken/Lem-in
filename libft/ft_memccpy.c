/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:57:07 by rfernand          #+#    #+#             */
/*   Updated: 2015/12/18 13:33:45 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*str;
	char		*cpy;
	int			p;

	str = src;
	cpy = dst;
	p = 0;
	while (n-- && (str[p] != c))
		*cpy++ = str[p++];
	if (str[p] == c)
		*cpy++ = str[p++];
	n++;
	if (!n)
		return (NULL);
	else
		return (dst + p);
}
