/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:59:48 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/09 12:24:18 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;

	if (*little == '\0')
		return ((char*)big);
	while (*big && len > 0)
	{
		i = 0;
		while (big[i] == little[i] && little[i] && (len - i) > 0)
			i++;
		if (little[i] == '\0')
			return ((char*)big);
		len--;
		big++;
	}
	return (NULL);
}
