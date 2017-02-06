/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:18:23 by rfernand          #+#    #+#             */
/*   Updated: 2015/12/16 17:32:23 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	int i;

	i = 0;
	if (!(*s2 || n))
		return (s1);
	while (s1[i])
		i++;
	while (n-- && *s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}