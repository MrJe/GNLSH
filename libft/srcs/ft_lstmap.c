/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:10:14 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/28 11:47:28 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*start;
	t_list		*wait;
	t_list		*new;

	start = NULL;
	if (lst)
	{
		wait = (*f)(lst);
		new = ft_lstnew(wait->content, wait->content_size);
		start = new;
		lst = lst->next;
	}
	while (lst)
	{
		wait = (*f)(lst);
		new->next = ft_lstnew(wait->content, wait->content_size);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
