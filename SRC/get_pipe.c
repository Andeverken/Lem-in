/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:46:30 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/10 17:23:16 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "get_next_line.h"
#include "../libft/libft.h"

void			add_point(t_anthill *elem, t_anthill *point)
{
	int			i;
	t_anthill	**new;

	i = 0;
	if (!elem->pipe)
	{
		elem->pipe = (t_anthill **)malloc(2 * sizeof(t_anthill *));
		(elem->pipe)[0] = point;
		(elem->pipe)[1] = NULL;
	}
	else
	{
		while ((elem->pipe)[i])
			i++;
		new = (t_anthill **)malloc((i + 2) * sizeof(t_anthill *));
		new[i + 1] = NULL;
		new[i] = point;
		cpy_lst(new, elem->pipe);
		free(elem->pipe);
		elem->pipe = new;
	}
}

int				add_pipe(t_anthill *begin, char *line)
{
	char		**split;
	t_anthill	*elem1;
	t_anthill	*elem2;

	elem1 = begin;
	elem2 = begin;
	split = ft_strsplit(line, '-');
	if (check_name(begin, split[0]) || check_name(begin, split[1]))
		return (0);
	while (ft_strcmp(elem1->name, split[0]))
		elem1 = elem1->next;
	while (ft_strcmp(elem2->name, split[1]))
		elem2 = elem2->next;
	add_point(elem1, elem2);
	add_point(elem2, elem1);
	return (1);
}

int				get_pipe(t_anthill *begin, char *line)
{
	if (!add_pipe(begin, line))
		return (0);
	while (line[0])
	{
		get_next_line(0, &line);
		if (!line)
			return (1);
		while (line && line[0] == '#' && line[1] != '#')
			get_next_line(0, &line);
		if (!line)
			return (1);
		if (line[0] == '#' && line[1] == '#')
		{
			if (check_start_end(line))
				return (0);
		}
		else if (check_pipe(begin, line))
			add_pipe(begin, line);
		else
			return (0);
	}
	return (1);
}
