/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:33:11 by rfernand          #+#    #+#             */
/*   Updated: 2015/12/17 13:20:26 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = (void *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (start--)
		s++;
	while (len--)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
