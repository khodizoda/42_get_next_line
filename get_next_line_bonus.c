/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:28:11 by gkhodizo          #+#    #+#             */
/*   Updated: 2020/05/21 01:16:09 by gkhodizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** get_next_line() returns a line read from a text_file descriptor.
** The return value can be 1, 0 or -1 depending on whether a line has been
** read, when the reading has been completed, or if an error has happened.
*/

#include "get_next_line_bonus.h"

static char		*clean_buff(char *buff)
{
	size_t	i;
	size_t	lin_len;
	size_t	clean_buf_len;
	char	*tmp;

	lin_len = line_len(buff);
	clean_buf_len = buff_len(buff) - lin_len;
	if (!(tmp = (char *)malloc((clean_buf_len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (buff[lin_len] != '\0')
		tmp[i++] = buff[++lin_len];
	tmp[i] = '\0';
	free(buff);
	buff = ft_strdup(tmp);
	free(tmp);
	return (buff);
}

static int		save_to_line(char **line, char *main_buff)
{
	size_t len;

	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	len = line_len(main_buff);
	if (!(*line = (char *)malloc((len + 1) * sizeof(char))))
		return (-1);
	if (main_buff)
	{
		ft_memcpy(*line, main_buff, len);
		(*line)[len] = '\0';
		if (main_buff[len] == '\n')
			return (1);
	}
	return (0);
}

static char		*realloc_append_buff(char *mid_buff, char *tmp_buff)
{
	size_t	i;
	size_t	mid_len;
	size_t	tmp_len;
	char	*new;

	mid_len = buff_len(mid_buff);
	tmp_len = buff_len(tmp_buff);
	if (!(new = (char *)malloc((mid_len + tmp_len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < mid_len)
	{
		new[i] = mid_buff[i];
		i++;
	}
	i = 0;
	while (i < tmp_len)
	{
		new[mid_len] = tmp_buff[i];
		i++;
		mid_len++;
	}
	new[mid_len] = '\0';
	return (new);
}

static char		*read_append(int fd, char *main_buff, char *tmp_buff)
{
	int		bytes_read;
	char	*mid_buff;

	bytes_read = 0;
	while ((bytes_read = read(fd, tmp_buff, BUFFER_SIZE)) > 0)
	{
		tmp_buff[bytes_read] = '\0';
		mid_buff = ft_strdup(main_buff);
		free(main_buff);
		main_buff = realloc_append_buff(mid_buff, tmp_buff);
		free(mid_buff);
		if (ft_strchr(tmp_buff, '\n'))
			break ;
	}
	return (main_buff);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	char		tmp_buff[BUFFER_SIZE + 1];
	static char	*main_buff[MAX_FD];

	if (!line
		|| fd < 0 || fd > MAX_FD
		|| BUFFER_SIZE <= 0 || BUFFER_SIZE >= MAX_INT
		|| (read(fd, tmp_buff, 0) < 0)
		|| !(*line = ft_strdup("")))
		return (-1);
	if (!main_buff[fd])
		if (!(main_buff[fd] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (-1);
	main_buff[fd] = read_append(fd, main_buff[fd], tmp_buff);
	if (main_buff[fd][0] == '\0')
		return (0);
	ret = save_to_line(line, main_buff[fd]);
	main_buff[fd] = clean_buff(main_buff[fd]);
	return (ret);
}
