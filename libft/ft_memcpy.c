/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:42:42 by rfernand          #+#    #+#             */
/*   Updated: 2015/11/30 13:51:49 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*str;
	unsigned char		*cpy;
	int					i;

	str = src;
	cpy = dst;
	i = n;
	while (n--)
		*cpy++ = *str++;
	return (cpy - i);
}
