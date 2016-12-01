/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:03:32 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/08 17:03:50 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!ft_isprint(*str))
			return (0);
		str++;
	}
	return (1);
}
