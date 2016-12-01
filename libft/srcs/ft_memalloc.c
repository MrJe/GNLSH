/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:43:22 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/04 11:37:28 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void		*mem;

	mem = malloc(sizeof(*mem) * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
