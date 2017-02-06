/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:34:53 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/10 14:27:41 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_room_anthill(t_anthill *begin)
{
	int			i;
	int			n;
	t_anthill	*elem;

	i = 0;
	n = 0;
	elem = begin;
	while (elem)
	{
		if (elem->special == 1)
			i++;
		if (elem->special == 2)
			n++;
		elem = elem->next;
	}
	if (i == 1 && n == 1)
		return (1);
	return (0);
}
