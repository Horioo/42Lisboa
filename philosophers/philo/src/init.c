/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:18:18 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/26 18:34:48 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	assign_forks(t_philo *philo, t_fork *forks, int philo_pos)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	
	if(philo->id % 2 == 0)
	{
		philo->first_fork =  &forks[philo_pos - 1];
		philo->second_fork = &forks[(philo_pos + 1) % philo_nbr];
	}
	else
	{ 
		philo->first_fork =  &forks[(philo_pos + 1) % philo_nbr];
		philo->second_fork = &forks[philo_pos - 1];
	}
}

void	init_philo(t_table *table)
{
	int i;
	t_philo *philo;
	i = -1;
	while(++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}
}

void	table_init(t_table *table)
{
	int i;

	i = -1;
	table->end_sim = false;
	table->all_threads_ready = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = safe_malloc(sizeof(t_fork) * table->philo_nbr);
	while(++i < table->philo_nbr)
	{
		safe_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	init_philo(&table);
}