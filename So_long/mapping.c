/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:22:10 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/16 13:50:18 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "so_long.h"

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
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
		perror("Error mapping file");
		close(fd);
	}
	return (tab);
}
