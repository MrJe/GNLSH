/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:39:31 by jmichaud          #+#    #+#             */
/*   Updated: 2017/06/22 12:16:22 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h> // open
#include <stdlib.h> // malloc && free

int					get_next_line(const int fd, char **line);

static int			while_gnl(int fd)
{
	int			ret;
	char		*line;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		ft_putstr("->");
		ft_putstr(line);
		ft_putendl("<-");
		free(line);
	}
	return (1);
}

int					main(int argc, const char *argv[])
{
	int			i;
	int			ret;
	int			*fd;
	char		*line;

	if (argc == 1 && !while_gnl(0))
			return (1);
	else
	{
		fd = (int *)malloc(sizeof(*fd) * (argc - 1));
		for (i = 0; i < argc - 1; i++)
		{
			if ((fd[i] = open(argv[i + 1], O_RDONLY)) == -1)
			{
				ft_putstr_fd("open() failed\n", 2);
				return (1);
			}
		}
		for (i = 0; i < 2; i++)
		{
			if ((ret = get_next_line(fd[0], &line)) != -1 &&
				ret != 0)
			{
				ft_putstr("0->");
				ft_putstr(line);
				ft_putendl("<-");
				free(line);
			}
			if (ret == -1)
			{
				ft_putstr_fd("Error\n", 2);
				free(line);
				return (1);
			}
			if ((ret = get_next_line(fd[1], &line)) != -1 &&
				ret != 0)
			{
				ft_putstr("1->");
				ft_putstr(line);
				ft_putendl("<-");
				free(line);
			}
			if (ret == -1)
			{
				ft_putstr_fd("Error\n", 2);
				free(line);
				return (1);
			}
			if ((ret = get_next_line(fd[0], &line)) != -1 &&
				ret != 0)
			{
				ft_putstr("0->");
				ft_putstr(line);
				ft_putendl("<-");
				free(line);
			}
			if (ret == -1)
			{
				ft_putstr_fd("Error\n", 2);
				free(line);
				return (1);
			}
			if ((ret = get_next_line(fd[2], &line)) != -1 &&
				ret != 0)
			{
				ft_putstr("2->");
				ft_putstr(line);
				ft_putendl("<-");
				free(line);
			}
			if (ret == -1)
			{
				ft_putstr_fd("Error\n", 2);
				free(line);
				return (1);
			}
			if ((ret = get_next_line(fd[1], &line)) != -1 &&
				ret != 0)
			{
				ft_putstr("1->");
				ft_putstr(line);
				ft_putendl("<-");
				free(line);
			}
			if (ret == -1)
			{
				ft_putstr_fd("Error\n", 2);
				free(line);
				return (1);
			}
		}
		for (i = 0; i < argc - 1; i++)
			if (!while_gnl(fd[i]))
				return (1);
		for (i = 0; i < argc - 1; i++)
		{
			if (close(fd[i]) == -1)
			{
				ft_putstr_fd("close() failed\n", 2);
				return (1);
			}
		}
		free(fd);
	}
	return (0);
}
