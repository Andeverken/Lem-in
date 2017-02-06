/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:48:20 by rfernand          #+#    #+#             */
/*   Updated: 2015/12/17 15:15:19 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*empty_string(char *str)
{
	str = (char *)malloc(1 * sizeof(char));
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		u;
	char	*str;

	i = 0;
	u = 0;
	str = NULL;
	while ((s[u] == ' ' || s[u] == '\n' || s[u] == '\t') && s[u])
		u++;
	if (!s[u])
		return (empty_string(str));
	while (s[u++])
		i++;
	u--;
	i++;
	while ((s[u] == ' ' || s[u] == '\n' || s[u] == '\t' || s[u] == '\0') && i--)
		u--;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
		str[i--] = s[u--];
	return (str);
}
