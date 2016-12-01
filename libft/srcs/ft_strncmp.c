/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:04:39 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/07 16:24:31 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((unsigned char)*s1 == (unsigned char)*s2 && *s1 && n > 0)
	{
		s1++;
		s2++;
		n--;
		if (n == 0)
		{
			s1--;
			s2--;
		}
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
