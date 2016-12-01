/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:29:31 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/09 11:45:56 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char*)s1 != *(unsigned char*)s2)
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
