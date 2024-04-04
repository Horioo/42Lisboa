/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:25:34 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/10/26 17:24:04 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

int	ft_str_aux(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	else
		return (ft_putstr_fd(str, 1));
}

int	ft_check_conversion(va_list *args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar_fd(va_arg(*args, int), 1);
	else if (format == 's')
		len += ft_str_aux(va_arg(*args, char *));
	else if (format == 'p')
		len += ft_putpt(va_arg(*args, unsigned long int), len);
	else if (format == 'i' || format == 'd')
		len += ft_putnbr_fd(va_arg(*args, int), 1, len);
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(*args, unsigned int), len);
	else if (format == 'X')
		len += ft_print_hex(va_arg(*args, unsigned int), HEX_UP);
	else if (format == 'x')
		len += ft_print_hex(va_arg(*args, unsigned int), HEX_LOW);
	else if (format == '%')
		len += write(1, "%", 1);
	return (len);
}

static int	is_possible(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			len;
	int			i;

	if (!s)
		return (-1);
	len = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && is_possible("cspdiuxX%", s[i + 1]))
		{
			i++;
			len += ft_check_conversion(&args, s[i]);
		}
		else
			len += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
