/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:30:39 by gkhodizo          #+#    #+#             */
/*   Updated: 2020/06/07 16:57:08 by gkhodizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*-----------------------------*/
/* tests to read a single line */
/*-----------------------------*/

/* test_1: RANDOM FD */
void test_case_1()
{
	int		fd;
	int		a_gnl;
	int		e_gnl;
	char	*a_line;
	char	*e_line;

	fd = 101;
	a_gnl = get_next_line(fd, &a_line);

	e_gnl = -1;
	e_line = "";
	
	if (a_gnl == e_gnl && (strcmp(a_line, e_line) == 0))
	{
		bold_green();
		printf("|OK|\n");
	}
	else
	{
		bold_red();
		printf("|KO|");
		yellow();
		printf(" Expected gnl return is %d and line is %s\n"
			"Actual gnl return is %d and line is %s\n",
			e_gnl, e_line, a_gnl, a_line);
		reset();

	}
	free(a_line);
}

/* test_2: EXAMPLE.TXT */
void test_case_2()
{
	/* library function */
	FILE	*e_fd;
	ssize_t	e_gnl;
	size_t	n = 1;
	char	*e_line = NULL;
	
	e_fd = fopen("./src/example.txt", "r");
	e_gnl = getline(&e_line, &n, e_fd);
	if (e_gnl > 0 && (strchr(e_line, EOF) == NULL))
		e_gnl = 1;
	else
		e_gnl = 0;

	e_line = strtok(e_line, "\n");
	
	/* my function */
	int		a_fd;
	int		a_gnl;
	char	*a_line;

	a_fd = open("./src/example.txt", O_RDONLY);
	a_gnl = get_next_line(a_fd, &a_line);
	
	/* compare outputs */
	if (a_gnl == e_gnl && (strcmp(a_line, e_line) == 0))
	{
		bold_green();
		printf("|OK|\n");
	}
	else
	{
		bold_red();
		printf("|KO|");
		yellow();
		printf(" Expected gnl return is %zd and line is %s\n"
			"Actual gnl return is %d and line is %s\n",
			e_gnl, e_line, a_gnl, a_line);
		reset();

	}
	free(e_line);
	free(a_line);
}

/* test_3: NUMBERS.TXT */
void test_case_3()
{
	/* library function */
	FILE	*e_fd;
	ssize_t	e_gnl;
	size_t	n = 1;
	char	*e_line = NULL;
	
	e_fd = fopen("./src/numbers.txt", "r");
	e_gnl = getline(&e_line, &n, e_fd);
	if (e_gnl > 0 && (strchr(e_line, EOF) == NULL))
		e_gnl = 1;
	else
		e_gnl = 0;

	e_line = strtok(e_line, "\n");
	
	/* my function */
	int		a_fd;
	int		a_gnl;
	char	*a_line;

	a_fd = open("./src/numbers.txt", O_RDONLY);
	a_gnl = get_next_line(a_fd, &a_line);
	
	/* compare outputs */
	if (a_gnl == e_gnl && (strcmp(a_line, e_line) == 0))
	{
		bold_green();
		printf("|OK|\n");
	}
	else
	{
		bold_red();
		printf("|KO|");
		yellow();
		printf(" Expected gnl return is %zd and line is %s\n"
			"Actual gnl return is %d and line is %s\n",
			e_gnl, e_line, a_gnl, a_line);
		reset();

	}
	free(e_line);
	free(a_line);
}

/* test_4: SHORT.TXT */
void test_case_4()
{
	/* library function */
	FILE	*e_fd;
	ssize_t	e_gnl;
	size_t	n = 1;
	char	*e_line = NULL;
	
	e_fd = fopen("./src/short.txt", "r");
	e_gnl = getline(&e_line, &n, e_fd);
	if (e_gnl > 0 && (strchr(e_line, EOF) == NULL))
		e_gnl = 1;
	else
		e_gnl = 0;

	e_line = strtok(e_line, "\n");
	
	/* my function */
	int		a_fd;
	int		a_gnl;
	char	*a_line;

	a_fd = open("./src/short.txt", O_RDONLY);
	a_gnl = get_next_line(a_fd, &a_line);
	
	/* compare outputs */
	if (a_gnl == e_gnl && (strcmp(a_line, e_line) == 0))
	{
		bold_green();
		printf("|OK|\n");
	}
	else
	{
		bold_red();
		printf("|KO|");
		yellow();
		printf(" Expected gnl return is %zd and line is %s\n"
			"Actual gnl return is %d and line is %s\n",
			e_gnl, e_line, a_gnl, a_line);
		reset();

	}
	free(e_line);
	free(a_line);
}

/* test_5: LONG.TXT */
void test_case_5()
{
	/* library function */
	FILE	*e_fd;
	ssize_t	e_gnl;
	size_t	n = 1;
	char	*e_line = NULL;
	
	e_fd = fopen("./src/long.txt", "r");
	e_gnl = getline(&e_line, &n, e_fd);
	if (e_gnl > 0 && (strchr(e_line, EOF) == NULL))
		e_gnl = 1;
	else
		e_gnl = 0;

	e_line = strtok(e_line, "\n");
	
	/* my function */
	int		a_fd;
	int		a_gnl;
	char	*a_line;

	a_fd = open("./src/long.txt", O_RDONLY);
	a_gnl = get_next_line(a_fd, &a_line);
	
	/* compare outputs */
	if (a_gnl == e_gnl && (strcmp(a_line, e_line) == 0))
	{
		bold_green();
		printf("|OK|\n");
	}
	else
	{
		bold_red();
		printf("|KO|");
		yellow();
		printf(" Expected gnl return is %zd and line is %s\n"
			"Actual gnl return is %d and line is %s\n",
			e_gnl, e_line, a_gnl, a_line);
		reset();

	}
	free(e_line);
	free(a_line);
}

/* test_6: EMPTY.TXT */
void test_case_6()
{
	int		fd;
	int		a_gnl;
	int		e_gnl;
	char	*a_line;
	char	*e_line;

	fd = open("./src/empty.txt", O_RDONLY);
	a_gnl = get_next_line(fd, &a_line);

	e_gnl = 1;
	e_line = "";
	if (a_gnl == e_gnl && (strcmp(a_line, e_line) == 0))
	{
		bold_green();
		printf("|OK|\n");
	}
	else
	{
		bold_red();
		printf("|KO|");
		yellow();
		printf(" Expected gnl return is %d and line is %s\n"
			"Actual gnl return is %d and line is %s\n",
			e_gnl, e_line, a_gnl, a_line);
		reset();

	}
	free(a_line);
}

/*-----------------------------------*/
/* tests to read the entire document */
/*-----------------------------------*/

/* test_7: MULTIPLE LONG LINES FROM LONG.TXT */
void test_case_7()
{
	FILE	*e_fd;
	ssize_t	e_gnl;
	size_t	n = 1;
	char	*e_line = NULL;

	int		a_fd;
	int		a_gnl;
	char	*a_line;
	
	e_fd = fopen("./src/long.txt", "r");
	a_fd = open("./src/long.txt", O_RDONLY);

	while ((e_gnl = getline(&e_line, &n, e_fd)) > 0)
	{
		// library function
		if (e_gnl > 0 && (strchr(e_line, '\n')))
			e_gnl = 1;
		else
			e_gnl = 0;
		
		e_line = strtok(e_line, "\n");

		// my function
		a_gnl = get_next_line(a_fd, &a_line);

		// compare outputs
		if (a_gnl == e_gnl)
		{
			if ((strcmp(a_line, "") == 0 && e_line == NULL) ||
				(strcmp(a_line, e_line) == 0))
			{
				bold_green();
				printf("|OK|\n");
			}
		}
		else
		{
			bold_red();
			printf("|KO|");
			yellow();
			printf(" Expected gnl return is %zd and line is %s\n"
				"Actual gnl return is %d and line is %s\n",
				e_gnl, e_line, a_gnl, a_line);
			reset();

		}
		free(a_line);
	}
	free(e_line);
}

/* test_8: MULTIPLE SHORT LINES FROM SHORT.TXT */
void test_case_8()
{
	FILE	*e_fd;
	ssize_t	e_gnl;
	size_t	n = 1;
	char	*e_line = NULL;

	int		a_fd;
	int		a_gnl;
	char	*a_line;
	
	e_fd = fopen("./src/short.txt", "r");
	a_fd = open("./src/short.txt", O_RDONLY);

	while ((e_gnl = getline(&e_line, &n, e_fd)) > 0)
	{
		// library function
		if (e_gnl > 0 && (strchr(e_line, '\n')))
			e_gnl = 1;
		else
			e_gnl = 0;
		
		e_line = strtok(e_line, "\n");

		// my function
		a_gnl = get_next_line(a_fd, &a_line);

		// compare outputs
		if (a_gnl == e_gnl)
		{
			if ((strcmp(a_line, "") == 0 && e_line == NULL) ||
				(strcmp(a_line, e_line) == 0))
			{
				bold_green();
				printf("|OK|\n");
			}
		}
		else
		{
			bold_red();
			printf("|KO|");
			yellow();
			printf(" Expected gnl return is %zd and line is %s\n"
				"Actual gnl return is %d and line is %s\n",
				e_gnl, e_line, a_gnl, a_line);
			reset();

		}
		free(a_line);
	}
	free(e_line);
}
