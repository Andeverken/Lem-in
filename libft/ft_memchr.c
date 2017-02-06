/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:15:27 by rfernand          #+#    #+#             */
/*   Updated: 2015/11/27 15:32:59 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	int					i;

	str = s;
	i = 0;
	while (n-- && (str[i] != (unsigned char)c))
		i++;
	n++;
	if (n == 0)
		return (NULL);
	else
		return ((void*)s + i);
}
