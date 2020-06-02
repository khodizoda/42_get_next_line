/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:28:55 by gkhodizo          #+#    #+#             */
/*   Updated: 2020/06/01 20:25:23 by gkhodizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define MAX_FD 10240
# define MAX_INT 2147483647

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(char *s1);
char	*ft_strchr(const char *s, int c);
size_t	line_len(char *str);
size_t	buff_len(char *str);

#endif
