/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:16:30 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/10 21:26:48 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../libft/libft.h"

int			check_first_line(char *str)
{
	int i;

	i = 0;
	if (str[0] == '#')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int			check_start_end(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (1);
	else if (!ft_strcmp(line, "##end"))
		return (2);
	return (0);
}

int			check_room(char **split)
{
	int i;

	i = 0;
	if (!split[1] || !split[2] || split[3])
		return (0);
	while (split[1][i])
	{
		if (!ft_isdigit(split[1][i]))
			return (0);
		i++;
	}
	i = 0;
	while (split[2][i])
	{
		if (!ft_isdigit(split[2][i]))
			return (0);
		i++;
	}
	return (1);
}

int			check_name(t_anthill *begin, char *name)
{
	t_anthill *elem;

	elem = begin;
	while (elem)
	{
		if (!elem->name)
			return (1);
		if (!ft_strcmp(elem->name, name))
			return (0);
		elem = elem->next;
	}
	return (1);
}

int			check_pipe(t_anthill *begin, char *line)
{
	char		**split;
	t_anthill	*elem;
	int			i;

	if (!line || !ft_strchr(line, '-'))
		return (0);
	i = 0;
	elem = begin;
	split = ft_strsplit(line, '-');
	if (ft_strchr(line, ' '))
		return (0);
	if (!split[1] || !split[0] || split[2] || !elem->name)
		return (0);
	while (i != 2 && elem)
	{
		if (!ft_strcmp(elem->name, split[0]))
			i++;
		if (!ft_strcmp(elem->name, split[1]))
			i++;
		elem = elem->next;
	}
	if (i == 2)
		return (1);
	return (0);
}
