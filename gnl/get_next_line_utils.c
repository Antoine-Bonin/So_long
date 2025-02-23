/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:15:17 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/23 14:32:00 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\n' && str[i] != 0)
			i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;
	size_t	line_length;

	line_length = 0;
	while (src[line_length] != '\n' && src[line_length] != 0)
		line_length++;
	if (src[line_length] == '\n')
		line_length++;
	dest = malloc(sizeof(char) * (line_length + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < line_length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dest)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && (i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin2(char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	len_s2 = 0;
	while (s2[len_s2] != '\n' && s2[len_s2] != 0)
		len_s2++;
	if (s2[len_s2] == '\n')
		len_s2++;
	len_s1 = (ft_strlen(s1));
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (free(s1), NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcpy(str + len_s1, s2, len_s2 + 1);
	return (free(s1), str);
}
