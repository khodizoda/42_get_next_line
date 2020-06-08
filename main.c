/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:30:39 by gkhodizo          #+#    #+#             */
/*   Updated: 2020/06/07 21:24:43 by gkhodizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int	gnl;
	char	*line;

	fd = open("./src/example.txt", O_RDONLY);
	
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("gnl is %d: %s\n", gnl, line);
		free(line);
	}
	printf("gnl is %d: %s\n", gnl, line);
	free(line);

	system ("leaks gnl");
	return (0);
}