/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:55:29 by rfernand          #+#    #+#             */
/*   Updated: 2015/11/26 17:49:26 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while ((unsigned char)*s2 == (unsigned char)*s1 && *s1 && *s2)
	{
		s2++;
		s1++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
