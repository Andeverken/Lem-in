/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:37:02 by rfernand          #+#    #+#             */
/*   Updated: 2016/06/11 13:11:24 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_anthill
{
	struct s_anthill	*next;
	struct s_anthill	**pipe;
	char				*name;
	int					special;
	int					filled;
	int					weight;
	int					checked;
	int					best_path;
}						t_anthill;

t_anthill				*create_begin(t_anthill *begin);
t_anthill				*create_elem(t_anthill *begin);
void					print_list(t_anthill *begin);
void					cpy_lst(t_anthill **dst, t_anthill **src);
void					print_pipe(t_anthill *begin);

char					*get_anthill(t_anthill *begin);
int						get_pipe(t_anthill *begin, char *line);
int						resolve(t_anthill *begin);
void					print_path(t_anthill *begin);

int						check_first_line(char *str);
int						check_start_end(char *line);
int						check_room(char **split);
int						check_pipe(t_anthill *begin, char *line);
int						check_name(t_anthill *begin, char *name);
int						check_room_anthill(t_anthill *begin);

int						find_best_path(t_anthill *elem);
int						find_point(t_anthill *elem);

#endif
