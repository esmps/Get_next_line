/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:12:39 by epines-s          #+#    #+#             */
/*   Updated: 2020/02/25 20:16:52 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"

char	pointtothis();
{
}


int		get_next_line(const int fd, char **line)
{
	static char	*temp[1023];
	char		buf[BUFF_SIZE + 1];
	int			readres;


	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	while (readres = read(fd, buf, BUFF_SIZE) > 0)
	{


	}
	*line = pointtothis( );
	temp = therestofthestring();
	return (1);
}
