/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:24:00 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/04 17:43:44 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_itoa(int n)
{
	int			len;
	int			sign;
	char		*str;

	sign = (n < 0) ? -1 : 1;
	len = ft_intlen(n * sign);
	if (sign < 0)
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (--len > 0)
	{
		str[len] = ((n % 10) * sign) + '0';
		n /= 10;
	}
	if (sign < 0)
		str[len] = '-';
	else
		str[len] = ((n % 10) * sign) + '0';
	return (str);
}
