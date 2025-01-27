/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:44:21 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/12 17:26:19 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == ' ' || !*(format + 1)))
			return (-1);
		if (*format == '%' && *(format + 1))
		{
			count += ft_specifier(*(++format), ap);
		}
		else
			count += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
