/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:27:44 by gkhodizo          #+#    #+#             */
/*   Updated: 2020/06/07 16:53:14 by gkhodizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	len;
	char	*dup;

	if (!s1)
		return (NULL);
	i = 0;
	len = buff_len(s1);
	if (!(dup = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int		is_nl(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

size_t	line_len(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}

size_t	buff_len(char *str)
{
	size_t blen;

	if (!str)
		return (0);
	blen = 0;
	while (str[blen] != '\0')
		blen++;
	return (blen);
}
