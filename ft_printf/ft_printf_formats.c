/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:49:58 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/10/26 14:37:56 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_unsigned(unsigned int u, int len)
{
	if (u == 0)
		len += write(1, "0", 1);
	else
		len = ft_putnbr_fd(u, 1, len);
	return (len);
}

int	ft_print_hex(unsigned long int hex, char *base)
{
	char	c;
	int		len;

	len = 0;
	if (hex > 15)
	{
		len += ft_print_hex(hex / 16, base);
		len += ft_print_hex(hex % 16, base);
	}
	else
	{
		c = base[hex];
		len += write(1, &c, 1);
	}
	return (len);
}

int	ft_putpt(unsigned long int p, int len)
{
	if (!p)
		len += ft_putstr_fd("(nil)", 1);
	else 
	{
		len += write(1, "0x", 2);
		len += ft_print_hex(p, HEX_LOW);
	}
	return (len);
}
