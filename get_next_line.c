/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:52:55 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/28 11:54:54 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

/*
** This function searches "fd" in the list and returns the matching element.
** If "fd" isn't found, a new element is created and added to the list.
*/

t_fdlist		*get_current_fd(const int fd, t_fdlist **start)
{
	t_fdlist	*cfd;
	t_fdlist	*current;

	current = *start;
	while (current && current->next && current->fd != fd)
		current = current->next;
	if (current && current->fd == fd)
		return (current);
	cfd = (t_fdlist *)malloc(sizeof(t_fdlist));
	if (cfd)
	{
		cfd->fd = fd;
		cfd->save = NULL;
		cfd->next = NULL;
	}
	if (!*start)
		*start = cfd;
	else if (!(current->next))
		current->next = cfd;
	return (cfd);
}

/*
** This function will read BUFF_SIZE characteres in the file.
** These characteres are then added to the backup "save".
*/

int				read_once(const int fd, char **save)
{
	char		*buf;
	int			ret;
	char		*tmp;

	buf = (char *)malloc(sizeof(*buf) * (BUFF_SIZE + 1));
	if (!buf)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	else if (ret == 0)
		return (0);
	buf[ret] = '\0';
	if (!*save)
		*save = ft_strdup(buf);
	else
	{
		tmp = *save;
		*save = ft_strjoin(tmp, buf);
		if (!*save)
			return (-1);
		free(tmp);
	}
	free(buf);
	return (1);
}

/*
** This function allows to clean an element of the list when the read is over.
** The element is freed and pointers are ajusted in consequence.
*/

void			clean_fdlist(t_fdlist **start, t_fdlist *cfd)
{
	t_fdlist	*tmp;

	if (*start == cfd)
	{
		*start = (*start)->next;
		free(cfd);
	}
	else
	{
		tmp = *start;
		while (tmp->next && tmp->next != cfd)
			tmp = tmp->next;
		if (tmp->next == cfd)
		{
			tmp->next = tmp->next->next;
			free(cfd);
		}
	}
}

/*
** This function uses a pointer on the next '\n' to create the line.
** Then, the backup "save" is ajusted to the character after the actual '\n'.
*/

int				malloc_line(char **line, char **save, char **ptr)
{
	if (*ptr)
	{
		*line = ft_strsub(*save, 0, *ptr - *save);
		*ptr = ft_strdup(*ptr + 1);
		if (!*line || !*ptr)
			return (-1);
		free(*save);
		*save = *ptr;
	}
	else if (!*ptr && *save)
	{
		*line = ft_strsub(*save, 0, ft_strlen(*save));
		if (!*line)
			return (-1);
		free(*save);
		*save = NULL;
	}
	return (1);
}

/*
** Main function : 1- get the current fd; 2- read_once if first time fd;
** 3- eventually clean the list; 4- search a '\n' or read until find a '\n';
** 5- malloc the line and ajust the backup "save";
*/

int				get_next_line(const int fd, char **line)
{
	static t_fdlist		*start = NULL;
	t_fdlist			*c_fd;
	int					ret;
	char				*ptr;

	c_fd = get_current_fd(fd, &start);
	if (!c_fd)
		return (-1);
	if (!(c_fd->save) && (ret = read_once(fd, &(c_fd->save))) == -1)
		return (-1);
	if (!(c_fd->save) && ret == 0)
	{
		clean_fdlist(&start, c_fd);
		return (0);
	}
	ret = 1;
	while ((ptr = ft_strchr(c_fd->save, CHAR)) == NULL && ret != 0)
		if ((ret = read_once(fd, &(c_fd->save))) == -1)
			return (-1);
	if (ptr || (!ptr && *(c_fd->save)))
		return (malloc_line(line, &(c_fd->save), &ptr));
	return (0);
}
