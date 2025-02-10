/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:30:14 by pauldepetri       #+#    #+#             */
/*   Updated: 2025/02/10 17:29:58 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
}

int	check_end_line(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_next_line(char *str)
{
	size_t	i;
	size_t	str_len;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	str_len = ft_strlen(str + i);
	ft_strlcpy(str, str + i, str_len + 1);
	ft_bzero(str + str_len);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "\0";
	ssize_t		bytes_read;
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_strdup(buf);
	bytes_read = 1;
	while (bytes_read && check_end_line(buf) == 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(str), ft_bzero(buf), NULL);
		buf[bytes_read] = '\0';
		str = ft_strjoin2(str, buf);
		if (!str)
			return (NULL);
	}
	if (str[0] == '\0')
		return (free(str), NULL);
	ft_next_line(buf);
	return (str);
}
