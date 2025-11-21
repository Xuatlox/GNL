/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:10:20 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/21 11:26:53 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line_bonus.h"

int	main()
{
	int	fd = open("test", O_RDONLY);
	char	*buf;

	while ((buf = get_next_line(fd)))
	{
		printf("%s", buf);
		free(buf);
	}
}
