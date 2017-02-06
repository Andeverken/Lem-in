/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_anthill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:55:52 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/10 22:10:49 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../libft/libft.h"

t_anthill		*create_begin(t_anthill *begin)
{
	begin = (t_anthill *)malloc(sizeof(t_anthill));
	begin->next = NULL;
	begin->pipe = NULL;
	begin->name = NULL;
	begin->special = 0;
	begin->filled = 0;
	begin->weight = 0;
	begin->checked = 0;
	begin->best_path = 0;
	return (begin);
}

t_anthill		*create_elem(t_anthill *begin)
{
	t_anthill *elem;

	elem = begin;
	while (elem->next)
		elem = elem->next;
	elem->next = (t_anthill *)malloc(sizeof(t_anthill));
	elem = elem->next;
	elem->next = NULL;
	elem->pipe = NULL;
	elem->name = NULL;
	elem->special = 0;
	elem->filled = 0;
	elem->weight = 0;
	elem->checked = 0;
	elem->best_path = 0;
	return (elem);
}

void			cpy_lst(t_anthill **dst, t_anthill **src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
}
