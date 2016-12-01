/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:27:49 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/07 15:37:58 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst && (*alst)->next)
		ft_lstdel(&(*alst)->next, (*del));
	ft_lstdelone(&(*alst), (*del));
}
