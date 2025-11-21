/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:36:58 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/21 11:06:18 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*resize(char *s, int *size, const int i)
{
	char	*str;

	str = ft_calloc(i + BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (*size < i)
	{
		str[*size] = s[*size];
		(*size)++;
	}
	free(s);
	return (str);
}

char	*find_newline(char **s, int *size)
{
	int		i;

	i = 0;
	while ((*s)[i])
	{
		if ((*s)[i] == '\n')
			return (*s + i);
		i++;
	}
	*s = resize(*s, size, i);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i])
		i++;
	dup = ft_calloc((i + 1), sizeof(char));
	if (!dup)
		return (NULL);
	i--;
	while (i >= 0)
	{
		dup[i] = s[i];
		i--;
	}
	return (dup);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	if (size != 0 && nmemb * size / size != nmemb)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}
