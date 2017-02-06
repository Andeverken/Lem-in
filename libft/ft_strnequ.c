/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:28:14 by rfernand          #+#    #+#             */
/*   Updated: 2015/11/27 16:16:46 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t size)
{
	if (!s2 || !size)
		return (1);
	while ((*s1 == *s2) && size--)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2 && size)
		return (0);
	return (1);
}
