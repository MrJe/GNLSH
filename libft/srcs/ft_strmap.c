/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:38:47 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/07 11:34:28 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char		*str;
	size_t		i;

	str = (char*)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
