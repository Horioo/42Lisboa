/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:54:26 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/10/26 14:50:34 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long int n, int fd, int total)
{
	if (n == -2147483648)
		total += write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			total += write(fd, "-", 1);
			n = -n;
			total = ft_putnbr_fd(n, fd, total);
		}
		else if (n > 9)
		{
			total = ft_putnbr_fd(n / 10, fd, total);
			total = ft_putnbr_fd(n % 10, fd, total);
		}
		else
			total += ft_putchar_fd(n + '0', 1);
	}
	return (total);
}
