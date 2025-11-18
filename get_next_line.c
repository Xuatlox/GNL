/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:24:57 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/18 18:15:06 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*sep;
	int			size;

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
	if (!buf[0])
	{
		free(buf);
		return (NULL);
	}
	size = sep - buf;
	sep = ft_strdup(sep + 1);
	buf[size + 1] = 0;
	return (buf);
}
