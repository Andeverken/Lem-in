/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:37:13 by rfernand          #+#    #+#             */
/*   Updated: 2015/11/28 10:33:16 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	str = (void *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
