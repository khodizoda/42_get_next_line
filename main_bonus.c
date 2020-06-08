/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:30:39 by gkhodizo          #+#    #+#             */
/*   Updated: 2020/06/07 21:24:56 by gkhodizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

/* BONUS MULTIPLE FDS */

int	main(void)
{
	int		count;
	int		fd1, fd2, fd3;
	int		gnl1, gnl2, gnl3;
	char	*line1, *line2, *line3;

	fd1 = open("./src/numbers.txt", O_RDWR);
	fd2 = open("./src/example.txt", O_RDWR);
	fd3 = open("./src/empty.txt", O_RDWR);
	for (count = 0; count <= 5; count++)
	{
		// fd1 && gnl1
		gnl1 = get_next_line(fd1, &line1);
		printf("[fd: %d] gnl %d: %s\n\n", fd1, gnl1, line1);
		free(line1);

		// fd2 && gnl2
		gnl2 = get_next_line(fd2, &line2);
		printf("[fd: %d] gnl %d: %s\n\n", fd2, gnl2, line2);
		free(line2);

		// fd2 && gnl2
		gnl3 = get_next_line(fd3, &line3);
		printf("[fd: %d] gnl %d: %s\n\n", fd3, gnl3, line3);
		free(line3);
	}
	system ("leaks gnl");
}
