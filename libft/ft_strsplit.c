/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:00:10 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/10 17:34:41 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	nbsplit(char const *s, char c)
{
	int i;

	i = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s != c)
			i++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (i);
}

static int	lensplit(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tstr;
	int		i;
	int		n;
	int		u;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	u = nbsplit(s, c);
	tstr = (char **)malloc((u + 1) * sizeof(char *));
	if (!tstr)
		return (0);
	tstr[u] = NULL;
	while (u > i)
	{
		while (*s == c)
			s++;
		tstr[i] = (char *)malloc((lensplit(s, c) + 1) * sizeof(char));
		while (*s != c && *s)
			tstr[i][n++] = *s++;
		tstr[i++][n] = '\0';
		n = 0;
	}
	return (tstr);
}
