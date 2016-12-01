/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:07:05 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/08 17:08:39 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!ft_islower(*str))
			return (0);
		str++;
	}
	return (1);
}
