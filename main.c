/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:18:03 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/18 14:23:25 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int	main(void)
{
	int	fd = open("test", O_RDONLY);
	char *str = " ";
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
}
