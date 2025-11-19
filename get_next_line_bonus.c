/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:24:57 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/19 12:58:37 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	check_buf(char **buf, char ***sep, int fd)
{
	if (!**buf)
	{
		free(*buf);
		*sep[fd] = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*sep[1024];
	int			size;

	buf = sep[fd];
	if (buf)
		sep[fd] = find_newline(&buf);
	else
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!sep[fd])
	{
		if (!buf)
			return (NULL);
		size = ft_strlen(buf);
		if (read(fd, &buf[size], BUFFER_SIZE) <= 0)
			sep[fd] = &buf[size];
		else
			sep[fd] = find_newline(&buf);
	}
	if (check_buf(&buf, &sep[fd], fd))
		return (NULL);
	size = sep[fd] - buf;
	sep[fd] = ft_strdup(sep[fd] + 1);
	buf[size + 1] = 0;
	return (buf);
}
