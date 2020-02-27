/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:12:39 by epines-s          #+#    #+#             */
/*   Updated: 2020/02/26 19:28:43 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*new_line(char *storage_fd)
{
	char	*newline;
	int		i;

	i = 0;
	while (storage_fd[i] != '\0' && storage_fd[i] != '\n')
		i++;
	newline = ft_strsub(storage_fd, 0, i);
	newline[i] = '\0';
	return (newline);
}

static char		*store_this(char *storage_fd)
{
	char	*res;
	int		i;

	i = 0;
	while (storage_fd[i] != '\0' && storage_fd[i] != '\n')
		i++;
	res = &storage_fd[i + 1];
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static char	*storage[1024];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			readres;

	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	while ((readres = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!storage[fd])
			storage[fd] = ft_strnew(0);
		buf[readres] = '\0';
		temp = ft_strjoin(storage[fd], buf);
		free(storage[fd]);
		storage[fd] = temp;
		if (ft_strchr(storage[fd], '\n'))
			break ;
	}
	*line = new_line(storage[fd]);
	storage[fd] = store_this(storage[fd]);
	if (storage[fd] && *storage[fd] == '\0')
		return (0);
	return (1);
}
