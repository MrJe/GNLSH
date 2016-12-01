/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:00:07 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/07 11:26:58 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char		**bigtab;
	size_t		nbwords;
	size_t		i;

	nbwords = ft_nbwords(s, c);
	bigtab = (char**)malloc(sizeof(*bigtab) * (nbwords + 1));
	if (!bigtab)
		return (NULL);
	i = 0;
	while (i < nbwords)
	{
		while (*s == c)
			s++;
		bigtab[i] = ft_strsub(s, 0, ft_wordlen(s, c));
		if (!bigtab[i])
			return (NULL);
		while (*s != c && *s)
			s++;
		i++;
	}
	bigtab[i] = 0;
	return (bigtab);
}
