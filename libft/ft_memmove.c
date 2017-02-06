/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:42:42 by rfernand          #+#    #+#             */
/*   Updated: 2015/12/19 13:36:52 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*cpy;
	char	*str;
	char	*tab;

	i = 0;
	cpy = dst;
	str = (char *)src;
	tab = (char *)malloc((len + 1) * sizeof(char));
	while (len > i)
	{
		tab[i] = str[i];
		i++;
	}
	i = 0;
	while (len--)
	{
		cpy[i] = tab[i];
		i++;
	}
	return (dst);
}
