/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:55:50 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/04 17:58:26 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t			ft_wordlen(const char *str, char c)
{
	size_t		len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}
