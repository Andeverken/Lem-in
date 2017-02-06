/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:48:21 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/10 20:36:49 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		attrib_weight(t_anthill *elem, int weight)
{
	elem->checked = 1;
	elem->weight = weight;
	return (0);
}

int		return_path(int n, int u)
{
	if (u == -1)
		return (-1);
	if (n == 1)
		return (1);
	return (0);
}

int		find_path(t_anthill *elem, t_anthill *prev, int depth, int weight)
{
	int i;
	int n;
	int	u;

	i = 0;
	n = 0;
	u = -1;
	if (elem->checked == 1 && depth == 0)
		return (-1);
	if (elem->special == 1)
		return (1);
	if (elem->checked == 0)
		return (attrib_weight(elem, weight));
	while ((elem->pipe)[i] && n != 1)
	{
		if ((elem->pipe)[i] != prev)
		{
			n = find_path((elem->pipe)[i], elem, depth - 1, weight);
			if (u == -1)
				u = n;
		}
		i++;
	}
	return (return_path(n, u));
}

int		resolve(t_anthill *begin)
{
	t_anthill	*elem;
	int			i;
	int			n;

	elem = begin;
	i = 1;
	while (elem->special != 2)
		elem = elem->next;
	elem->weight = -1;
	elem->checked = 1;
	if (!elem->pipe)
		return (0);
	while (!(n = find_path(elem, NULL, i, i)))
		i++;
	if (n == -1)
		return (0);
	return (1);
}
