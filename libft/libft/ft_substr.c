/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:01:45 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/10 15:45:41 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ressource/libft.h"
#include <stdlib.h>

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	i;
	size_t			str_len;

	if (!str)
		return (0);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	newstr = malloc(len + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = str[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
