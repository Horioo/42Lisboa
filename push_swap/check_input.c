/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:41:56 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 12:41:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verificar se o os argumentos sao numeros

static int	is_number(char *av)
{
	int	i;

	i = 0;
	if(is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while(av[i] && is_digit(av[i]))
		i++;
	if(av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

// Verificar se temos duplicados nos argumentos

static int	has_dups(char **av)
{
	int i;
	int j;

	i = 1;
	while(av[i])
	{
		j = 1;
		while(av[j])
		{
			if(i != j && nbr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Verificar se os argumentos nao sao só 0's para evitar duplicados de 0 (000, +00, -00000)

static int is_zero(char *av)
{
	int	i;

	i = 0;
	if(is_sign(av[i]))
		i++;
	while(av[i] && av[i] == 0)
		i++;
	if(av[i] != '\0')
		return (0);
	return (1);
}

// Verificamos o input com as funções feitas anteriormente

int 	is_correct_input(char **av)
{
	int	i;
	int zeros;

	zeros = 0;
	i = 1;
	while(av[i])
	{
		if(!is_number(av[i]))
			return (0);
		zeros += is_zero(av[i]);
		i++;
	}
	if(zeros > 1)
		return (0);
	if(has_dups(av))
		return (0);
	return (1);
}

