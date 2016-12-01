/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:40:38 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/03 14:01:29 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void			ft_putnbr(int n)
{
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		write(1, "-", 1);
		if (n < -9)
			ft_putnbr(n / -10);
	}
	else if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 * sign + '0');
}
