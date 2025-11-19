/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:36:58 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/19 12:47:47 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*resize(char *s)
{
	char	*str;
	int		size;

	size = ft_strlen(s);
	str = ft_calloc(size + BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (NULL);
	size--;
	while (size >= 0)
	{
		str[size] = s[size];
		size--;
	}
	free(s);
	return (str);
}

char	*find_newline(char **s)
{
	int		i;

	i = 0;
	while ((*s)[i])
	{
		if ((*s)[i] == '\n')
			return (*s + i);
		i++;
	}
	*s = resize(*s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
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
