/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:33:54 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/07 13:44:28 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		lendst;
	size_t		i;

	lendst = 0;
	while (lendst < size && dst[lendst])
		lendst++;
	i = 0;
	size -= lendst;
	while (src[i] != '\0' && size - i > 1)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	if (i > 0)
		dst[lendst + i] = '\0';
	return (lendst + ft_strlen(src));
}
