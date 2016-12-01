/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:53:00 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/04 16:31:07 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strrchr(const char *s, int c)
{
	size_t		len;

	len = 0;
	while (s[len])
		len++;
	while (s[len] != (char)c && len > 0)
		len--;
	if (s[len] == (char)c)
		return (&((char*)s)[len]);
	else
		return (NULL);
}
