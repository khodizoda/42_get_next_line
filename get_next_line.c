/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:28:11 by gkhodizo          #+#    #+#             */
/*   Updated: 2020/06/07 17:42:05 by gkhodizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** get_next_line() returns a line read from a text_file descriptor.
** The return value can be 1, 0 or -1 depending on whether a line has been
** read, when the reading has been completed, or if an error has happened.
*/

#include "get_next_line.h"

static char		*clean_buff(char *text)
{
	size_t	i;
	size_t	llen;
	size_t	nlen;
	char	*tmp;

	llen = line_len(text);
	nlen = buff_len(text) - llen;
	if (nlen > 0)
	{
		if (!(tmp = (char *)malloc((nlen + 1) * sizeof(char))))
			return (NULL);
		i = 0;
		while (text[llen] != '\0')
			tmp[i++] = text[++llen];
		tmp[i] = '\0';
		free(text);
		return (tmp);
	}
	free(text);
	text = NULL;
	return (text);
}

static int		save_to_line(char **line, char *text)
{
	size_t len;

	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	len = line_len(text);
	if (!(*line = (char *)malloc((len + 1) * sizeof(char))))
		return (-1);
	(*line)[len] = '\0';
	if (text)
	{
		ft_strncpy(*line, text, len);
		if (text[len] == '\n')
			return (1);
	}
	return (0);
}

static char		*realloc_append_buff(char *mid, char *tmp)
{
	size_t	i;
	size_t	mlen;
	size_t	tlen;
	char	*new;

	mlen = buff_len(mid);
	tlen = buff_len(tmp);
	if (!(new = (char *)malloc((mlen + tlen + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < mlen)
	{
		new[i] = mid[i];
		i++;
	}
	i = 0;
	while (i < tlen)
	{
		new[mlen] = tmp[i];
		i++;
		mlen++;
	}
	new[mlen] = '\0';
	return (new);
}

static char		*read_append(int fd, char *text, char *tmp)
{
	ssize_t	bytes_read;
	char	*mid;

	while ((bytes_read = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[bytes_read] = '\0';
		mid = text;
		text = realloc_append_buff(mid, tmp);
		free(mid);
		if (is_nl(tmp))
			break ;
	}
	return (text);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		tmp[BUFFER_SIZE + 1];
	static char	*text;

	if (!line
		|| !(*line = ft_strdup(""))
		|| fd < 0 || BUFFER_SIZE <= 0
		|| (read(fd, tmp, 0) < 0))
		return (-1);
	text = read_append(fd, text, tmp);
	if (text == NULL)
		return (0);
	ret = save_to_line(line, text);
	text = clean_buff(text);
	return (ret);
}
