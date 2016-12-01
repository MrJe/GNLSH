/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:49:34 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/04 16:55:54 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
