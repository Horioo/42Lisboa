/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:07:22 by ajorge-p          #+#    #+#             */
/*   Updated: 2023/10/16 15:55:23 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int	neg;
	int	ret;

	neg = 1;
	ret = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			neg = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		ret = ret * 10 + *s - '0';
		s++;
	}
	return (ret * neg);
}
/*
int	main(void)
{
    printf("%d\n", ft_atoi("+213asdaskl123d2ad2"));
    printf("%d", atoi("+213asdaskl123d2ad2"));
}
*/