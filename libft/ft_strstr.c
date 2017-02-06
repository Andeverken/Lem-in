/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:15:58 by rfernand          #+#    #+#             */
/*   Updated: 2015/11/26 17:35:29 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[j])
	{
		while ((s1[j + i] == s2[i]) && s2[i])
			i++;
		if (!s2[i])
			return ((char*)s1 + j);
		i = 0;
		j++;
	}
	return (NULL);
}
