/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 21:20:43 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/10 21:28:36 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			find_best_path(t_anthill *elem)
{
	int i;

	i = 0;
	while ((elem->pipe[i])->best_path != elem->best_path - 1)
		i++;
	return (i);
}

int			find_point(t_anthill *elem)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while ((elem->pipe)[i])
	{
		if (((elem->pipe[i])->weight < (elem->pipe[n]->weight)
				&& (elem->pipe[i])->weight != 0) || !(elem->pipe[n])->weight)
			n = i;
		i++;
	}
	return (n);
}
