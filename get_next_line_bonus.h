/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:28:55 by gkhodizo          #+#    #+#             */
/*   Updated: 2020/06/07 21:07:55 by gkhodizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 4096

int		get_next_line(int fd, char **line);
char	*ft_strncpy(char *dst, char *src, size_t len);
char	*ft_strdup(char *s1);
int		is_nl(char *s);
size_t	line_len(char *str);
size_t	buff_len(char *str);

#endif
