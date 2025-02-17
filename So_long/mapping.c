/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:22:10 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/17 17:55:57 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../libft/ressource/libft.h"
#include "so_long.h"

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

char	**mapping(int fd, size_t lines)
{
	char	**tab;
	char	*buffer;
	size_t	y;

	y = 0;
	if (fd < 0)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!tab)
		return (NULL);
	buffer = get_next_line(fd);
	while (buffer != NULL && y < lines)
	{
		tab[y] = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
		if (!tab[y])
			return (free(buffer), free_tab(tab), NULL);
		ft_strlcpy(tab[y], buffer, ft_strlen(buffer) + 1);
		free(buffer);
		buffer = get_next_line(fd);
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

char	**load_map(int fd, size_t lines)
{
	char	**tab;

	tab = mapping(fd, lines);
	if (!tab)
	{
		ft_putendl_fd("Error\nLoading map", 2);
		close(fd);
	}
	return (tab);
}
