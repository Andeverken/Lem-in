/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:19:14 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/11 13:35:46 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "get_next_line.h"
#include "../libft/libft.h"

int		print_map(void)
{
	int		i;
	char	*line;

	i = 1;
	line = NULL;
	while (i)
		i = get_next_line(0, &line);
	return (write(1, "Error\n", 6));
}

int		main(void)
{
	t_anthill	*begin;
	char		*line;

	begin = NULL;
	begin = create_begin(begin);
	if (!(line = get_anthill(begin)))
		return (print_map());
	if (!check_room_anthill(begin))
		return (print_map());
	if (!get_pipe(begin, line))
		return (print_map());
	if (!resolve(begin))
		return (print_map());
	print_path(begin);
	return (0);
}
