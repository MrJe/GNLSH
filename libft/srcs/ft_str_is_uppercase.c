/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:06:44 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/08 17:06:57 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (!ft_isupper(*str))
			return (0);
		str++;
	}
	return (1);
}
