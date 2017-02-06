/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anthill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:00:56 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/11 14:15:28 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "get_next_line.h"
#include "../libft/libft.h"

int			get_room(t_anthill *begin, t_anthill *elem, char *line)
{
	char	**split;

	if (check_pipe(begin, line) && begin != elem)
		return (1);
	split = ft_strsplit(line, ' ');
	if (!check_room(split))
		return (0);
	if (!check_name(begin, split[0]))
		return (0);
	elem->name = (char *)malloc((ft_strlen(split[0]) + 1) * sizeof(char));
	ft_strcpy(elem->name, split[0]);
	return (1);
}

int			get_first_room(t_anthill *begin)
{
	char *line;

	get_next_line(0, &line);
	while (!begin->name)
	{
		while (line[0] == '#' && ft_strcmp(line, "##start") &&
				ft_strcmp(line, "##end"))
			get_next_line(0, &line);
		if (line[0] == '\0')
			return (0);
		if (line[0] == '#')
		{
			begin->special = check_start_end(line);
			get_next_line(0, &line);
		}
		if (!get_room(begin, begin, line))
			return (0);
	}
	return (1);
}

char		*get_other_room(t_anthill *begin)
{
	t_anthill	*elem;
	char		*line;

	elem = begin;
	line = NULL;
	while (elem->next)
		elem = elem->next;
	while (!check_pipe(begin, line))
	{
		get_next_line(0, &line);
		elem->next = create_elem(begin);
		elem = elem->next;
		while (line[0] == '#' && ft_strcmp(line, "##start") &&
				ft_strcmp(line, "##end") && line[0] != '\0')
			get_next_line(0, &line);
		if (line[0] == '#')
		{
			elem->special = check_start_end(line);
			get_next_line(0, &line);
		}
		if (line[0] == '\0' || !get_room(begin, elem, line))
			return (0);
	}
	return (line);
}

void		add_ants(t_anthill *begin, int ants)
{
	t_anthill *elem;

	elem = begin;
	while (elem->special != 1 && elem->next->next)
		elem = elem->next;
	elem->filled = ants;
	while (elem->next->next)
		elem = elem->next;
	free(elem->next);
	elem->next = NULL;
}

char		*get_anthill(t_anthill *begin)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	while (line[0] == '#')
		get_next_line(0, &line);
	i = ft_atoi(line);
	if (!check_first_line(line) || i <= 0)
		return (0);
	if (!get_first_room(begin))
		return (0);
	if (!(line = get_other_room(begin)))
		return (0);
	add_ants(begin, i);
	return (line);
}
