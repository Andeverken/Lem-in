/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:51:02 by rfernand          #+#    #+#             */
/*   Updated: 2015/12/18 14:24:12 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *elem;
	t_list *next;

	elem = *alst;
	next = (*alst)->next;
	while (elem->next)
	{
		del(elem->content, elem->content_size);
		free(elem);
		elem = next;
		next = next->next;
	}
	del(elem->content, elem->content_size);
	free(elem);
	*alst = NULL;
}
