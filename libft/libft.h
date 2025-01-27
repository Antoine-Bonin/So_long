/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:25:15 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/14 15:34:11 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
# define HEXA_CAPS "0123456789ABCDEF"
# define HEXA_MIN "0123456789abcdef"

int					ft_printf(const char *format, ...);
int					ft_specifier(char specifier, va_list ap);
char				*ft_strchr(const char *s, int c);
;
int					ft_putstr_fd(char *s, int fd);
int					ft_putchar_fd(char c, int fd);
int					ft_specifier(char specifier, va_list ap);
int					ft_printdecimal(long int n);
int					ft_printhexa(unsigned long int n, char hex);
int					ft_printpointer(void *s);

#endif