/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:02:10 by rfernand          #+#    #+#             */
/*   Updated: 2015/11/27 13:39:20 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((unsigned char)*s2 == (unsigned char)*s1 && *s1 && *s2 && n)
	{
		s2++;
		s1++;
		n--;
	}
	if (!n)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
