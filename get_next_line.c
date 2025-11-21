/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:24:57 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/21 12:41:24 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_null(char **buf, char **sep)
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
	static char	*sep;
	int			size;

	buf = sep;
	size = 0;
	if (buf)
		sep = find_newline(&buf, &size);
	else
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!sep)
	{
		if (!buf)
			return (NULL);
		if (read(fd, &buf[size], BUFFER_SIZE) <= 0)
			sep = find_newline(&buf, &size);
		else
			sep = &buf[size + 1];
	}
	if (check_null(&buf, &sep))
		return (NULL);
	size = sep - buf;
	if (*sep)
		sep = ft_strdup(sep + 1);
	buf[size + 1] = 0;
	return (buf);
}
