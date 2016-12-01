/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:57:30 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/07 11:29:35 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t		len;
	char		*str;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = 0;
	while (s[len])
		len++;
	if (len > 0)
		len--;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	str = ft_strsub(s, 0, len + 1);
	return (str);
}
