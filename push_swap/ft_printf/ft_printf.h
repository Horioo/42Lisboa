/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:58:32 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/10/26 14:38:09 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>

int	ft_print_unsigned(unsigned int u, int len);
int	ft_print_hex(unsigned long int hex, char *base);
int	ft_putpt(unsigned long int p, int len);
int	ft_printf(const char *s, ...);
int	ft_check_conversion(va_list *args, const char format);

#endif