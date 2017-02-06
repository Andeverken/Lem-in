/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:25:02 by rfernand          #+#    #+#             */
/*   Updated: 2015/11/26 17:34:11 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[j] && n)
	{
		while ((s1[j + i] == s2[i]) && n-- && s2[i])
			i++;
		if (!s2[i])
			return ((char*)s1 + j);
		n = n + i;
		i = 0;
		j++;
		n--;
	}
	return (NULL);
}
