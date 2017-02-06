/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:05:09 by rfernand          #+#    #+#             */
/*   Updated: 2015/12/18 14:16:30 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *buff;
	t_list *buff2;

	if (!lst || !f)
		return (NULL);
	buff2 = f(lst);
	if ((begin = ft_lstnew(buff2->content, buff2->content_size)))
	{
		buff = begin;
		lst = lst->next;
		while (lst)
		{
			buff2 = f(lst);
			if (!(buff->next = ft_lstnew(buff2->content, buff2->content_size)))
				return (NULL);
			lst = lst->next;
			buff = buff->next;
		}
	}
	return (begin);
}
