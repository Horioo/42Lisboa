/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:43:19 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/17 13:17:23 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(char *str)
{
	long	ret;
	int		i;
	
	ret = 0;
	i = 0;
	while(is_space(str[i]))
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			error_exit("The Numbers can't be Negative");
		i++;
	}
	while(is_digit(str[i]))
	{
		ret = ret * 10 + str[i++] - '0';
		if(ret > INT_MAX)
			error_exit("Value bigger than INT_MAX\n");
	}
	return (ret);
}

void	parsing(t_table *table, char **av)
{
	table->philo_nbr = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1000;
	table->time_to_eat = ft_atol(av[3]) * 1000;
	table->time_to_sleep = ft_atol(av[4]) * 1000;
	if(table->time_to_die < 60000
		|| table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
		error_exit("Timers have to be bigger than 60ms\n");
	if(av[5])
		table->nbr_limit_meals = ft_atol(av[5]);
	else
		table->nbr_limit_meals = -1;
}