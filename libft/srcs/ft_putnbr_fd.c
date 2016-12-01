/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:15:08 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/07 11:33:22 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		write(fd, "-", 1);
		if (n < -9)
			ft_putnbr_fd(n / -10, fd);
	}
	else if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 * sign + '0', fd);
}
