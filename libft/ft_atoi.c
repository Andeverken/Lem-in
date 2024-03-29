/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:06:33 by rfernand          #+#    #+#             */
/*   Updated: 2015/11/26 17:14:09 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int result;

	result = 0;
	while (*str == '\n' || *str == ' ' || *str == '\t' || *str == '\r' ||
			*str == '\v' || *str == '\f')
		str++;
	if (*str != '-' && *str != '+' && (*str < '0' || *str > '9'))
		return (0);
	if (*str == '-')
	{
		str++;
		while (*str >= '0' && *str <= '9' && *str)
			result = result * 10 + *str++ - 48;
		result = -result;
	}
	else
	{
		if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9' && *str)
			result = result * 10 + *str++ - 48;
	}
	return (result);
}
