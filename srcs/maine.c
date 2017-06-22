/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:39:31 by jmichaud          #+#    #+#             */
/*   Updated: 2017/06/22 17:46:02 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h> // open
#include <stdlib.h> // malloc && free

int					get_next_line(const int fd, char **line);

static int			return_error(const char *str, int ret)
{
	ft_putstr_fd(str, 1);
	return (ret);
}

static int			while_gnl(int fd)
{
	int			ret;
	char		*line;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (return_error("gnl() failed\n", 0));
		ft_putstr("->");
		ft_putstr(line);
		ft_putendl("<-");
		free(line);
	}
	return (1);
}

static int			one_gnl(int fd, int nb)
{
	int			ret;
	char		*line;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (return_error("gnl() failed\n", 0));
	if (!ret)
		return (1);
	ft_putnbr(nb);
	ft_putstr("->");
	ft_putstr(line);
	ft_putendl("<-");
	free(line);
	return (1);
}

int					main(int argc, const char *argv[])
{
	int			i;
	int			*fd;

	if (argc == 1 && !while_gnl(0))
			return (1);
	else
	{
		one_gnl(42, 0);
		if (!(fd = (int *)malloc(sizeof(*fd) * (argc - 1))))
			return (return_error("malloc() failed\n", 1));
		for (i = 0; i < argc - 1; i++)
			if ((fd[i] = open(argv[i + 1], O_RDONLY)) == -1)
				return (return_error("open() failed\n", 1));
		if (!one_gnl(fd[0], 0))
			return (1);
		for (i = 0; i < argc - 1; i++)
			if (close(fd[i]) == -1)
				return (return_error("close() failed\n", 1));
		one_gnl(fd[0], 0);
		free(fd);
	}
	return (0);
}
