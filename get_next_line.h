/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:53:07 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/28 12:27:05 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE	32
# define CHAR		'\n'

# if BUFF_SIZE <= 0
#  error "invalide size for BUFF_SIZE"
# endif

typedef struct	s_fdlist
{
	int				fd;
	char			*save;
	struct s_fdlist	*next;
}				t_fdlist;

int				get_next_line(const int fd, char **line);

#endif
