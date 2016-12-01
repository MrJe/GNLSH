/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:27:57 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/04 13:42:50 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strdup(const char *s1)
{
	char		*str;

	str = (char*)malloc(sizeof(*str) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	return (str);
}
