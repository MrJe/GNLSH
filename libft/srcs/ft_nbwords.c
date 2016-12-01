/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:48:59 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/04 17:53:07 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t			ft_nbwords(const char *str, char c)
{
	size_t		nb;

	nb = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != c && *str)
			nb++;
		while (*str != c && *str)
			str++;
	}
	return (nb);
}
