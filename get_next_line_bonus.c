/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:24:57 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/24 14:09:29 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*search_sep(char **buf, int *size, int fd)
{
	int		ret;

	if (!*buf)
		return ("");
	ret = read(fd, &(*buf)[*size], BUFFER_SIZE);
	if (ret == -1)
	{
		free(*buf);
		*buf = NULL;
		return (NULL);
	}
	if (ret == 0)
		return (&(*buf)[*size]);
	return (find_newline(buf, size));
}

static int	check_null(char **buf, char **sep)
{
	if (!*buf || !**buf)
	{
		free(*buf);
		*sep = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*sep[1025];
	int			size;

	if (fd > 1024 || fd < 0)
		return (NULL);
	buf = sep[fd];
	size = 0;
	if (buf)
		sep[fd] = find_newline(&buf, &size);
	else
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!sep[fd])
		sep[fd] = search_sep(&buf, &size, fd);
	if (check_null(&buf, &sep[fd]))
		return (NULL);
	if (*sep[fd])
		sep[fd] = ft_strdup(sep[fd] + 1);
	else
		sep[fd] = NULL;
	buf[size + 1] = 0;
	return (buf);
}
