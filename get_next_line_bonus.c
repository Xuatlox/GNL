/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:24:57 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/19 14:20:10 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	check_buf(char **buf, char **sep)
{
	if (!**buf)
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
	char		*sep;
	static char	**seps;
	int			size;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	if (!seps)
		seps = ft_calloc(1024, sizeof(char *));
	sep = seps[fd];
	buf = sep;
	if (buf)
		sep = find_newline(&buf);
	else
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!sep)
	{
		if (!buf)
			return (NULL);
		size = ft_strlen(buf);
		if (read(fd, &buf[size], BUFFER_SIZE) <= 0)
			sep = &buf[size];
		else
			sep = find_newline(&buf);
	}
	if (check_buf(&buf, &sep))
		return (NULL);
	size = sep - buf;
	seps[fd] = ft_strdup(sep + 1);
	buf[size + 1] = 0;
	return (buf);
}
