/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:59:33 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/07 12:03:04 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strstr(const char *big, const char *little)
{
	size_t		i;

	if (*little == '\0')
		return ((char*)big);
	while (*big)
	{
		i = 0;
		while (big[i] == little[i] && little[i])
			i++;
		if (little[i] == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
