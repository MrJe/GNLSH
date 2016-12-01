/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:15:00 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/08 18:08:12 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcapitalize(char *str)
{
	size_t		i;
	int			up;

	i = 0;
	up = 1;
	str = ft_strlowcase(str);
	while (str[i])
	{
		if (!up && !ft_isalnum(str[i]))
			up = 1;
		if (str[i] && up && ft_isalnum(str[i]))
		{
			up = 0;
			str[i] = ft_toupper(str[i]);
		}
		i++;
	}
	return (str);
}
