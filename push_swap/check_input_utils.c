/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:41:40 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 12:41:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_sign(char c)
{
	return (c == '+' || c == '-');
}

// Comparamos duas strings de numeros para verificar se sao iguais, se forem devolvemos 0 se nao devolvemos a diferença do seu valor ascii

int		nbr_cmp(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if(s1[i] == '+')
	{
		if(s2[j] == '+')
			i++;
	}
	else
	{
		if(s2[j] == '+')
			j++;
	}
	while(s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

