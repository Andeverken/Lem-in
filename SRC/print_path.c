/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 18:47:15 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/10 21:28:16 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../libft/libft.h"

void		print_ant(t_anthill *start, int n, int weight)
{
	t_anthill	*elem;
	int			u;

	elem = start;
	u = 0;
	while (u < n && u <= weight)
	{
		if (elem->best_path <= n + 1 && elem->best_path != 1)
		{
			u++;
			write(1, "L", 1);
			ft_putnbr(n - elem->best_path + 2);
			write(1, "-", 1);
			ft_putstr(elem->name);
			if (u < n && u <= weight)
				write(1, " ", 1);
		}
		elem = (elem->pipe)[find_best_path(elem)];
	}
	write(1, "\n", 1);
}

void		print_second_ant(t_anthill *start, int weight, int i, int n)
{
	t_anthill	*elem;
	int			u;
	int			l;

	if (weight >= n)
		u = i + n - 1;
	else
		u = weight + i;
	weight = weight + i;
	elem = start;
	l = 0;
	while (elem->best_path > n + 1)
		elem = (elem->pipe)[find_best_path(elem)];
	while (l <= weight && l < n + i)
	{
		write(1, "L", 1);
		ft_putnbr(i + n - u + l);
		write(1, "-", 1);
		l++;
		ft_putstr(elem->name);
		if (l <= weight + 1)
			write(1, " ", 1);
		elem = (elem->pipe)[find_best_path(elem)];
	}
	write(1, "\n", 1);
}

void		get_path(t_anthill *elem)
{
	int i;

	i = 1;
	write(1, "\n\n", 2);
	while (elem->special != 2)
	{
		elem->best_path = i;
		elem = (elem->pipe)[find_point(elem)];
		i++;
	}
	elem->best_path = i;
}

void		print_path2(t_anthill *elem, int i, int n, int weight)
{
	int u;

	u = i;
	while (u)
	{
		if (n >= weight)
			u--;
		n++;
		i--;
		if (i >= 0)
			print_ant(elem, n, weight);
		else
			print_second_ant(elem, weight, i, n);
	}
}

void		print_path(t_anthill *begin)
{
	int			i;
	int			n;
	int			weight;
	t_anthill	*elem;

	elem = begin;
	while (elem->special != 1)
		elem = elem->next;
	get_path(elem);
	i = elem->filled;
	n = 0;
	weight = (elem->pipe[find_point(elem)])->weight;
	if (weight == -1)
		weight = 0;
	elem = begin;
	while (elem->special != 2)
		elem = elem->next;
	print_path2(elem, i, n, weight);
}
