/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:39:31 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/28 16:56:59 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h> // open
#include <stdlib.h> // malloc && free

int					get_next_line(const int fd, char **line);

int					main(int argc, const char *argv[])
{
	int			i;
	int			ret;
	int			*fd;
	char		*line;

	if (argc == 1)
	{
		while ((ret = get_next_line(0, &line)) != 0 &&
				ret != -1)
		{
			ft_putstr("->");
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
		for (i = 0; i < 5; i++)
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
		}
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
