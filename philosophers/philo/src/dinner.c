/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:47:00 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/30 15:41:29 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* 
	TODO
	Parsing:

	Input - ./philo 5 800 200 200 [5]
	
	0 - If no meals (av[5]), return (0)
	0.1 - If only 1 Philo -> Function to handle it
	1 - Create all philos (Threads)
	2 - Create monitor Thread - Searching for any occurance of Death
	3 - Syncronize the beggining of the simulation
		When Pthread_create is used the Philo will start running (We dont want this)
		We want every Philo starting at the same time
	4 - JOIN every Thread
*/

void	*one_philo(void *data)
{
	t_philo *philo;
	
	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECONDS));
	increment_long(&philo->table->table_mutex, &philo->table->nbr_threads_running);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while(!simulation_finished(philo->table))
		usleep(200);
	return (NULL);
}

void	thinking(t_philo *philo)
{
	write_status(THINKING, philo, DEBUG_MODE);
}

void	eat(t_philo *philo)
{
	safe_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	safe_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECONDS));
	philo->meals_counter++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->table->time_to_eat, philo->table);
	if(philo->table->nbr_limit_meals > 0 && philo->meals_counter == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	safe_mutex(&philo->first_fork->fork, UNLOCK);
	safe_mutex(&philo->second_fork->fork, UNLOCK);
}

void	*dinner_simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECONDS));
	increment_long(&philo->table->table_mutex, &philo->table->nbr_threads_running);
	while(!simulation_finished(philo->table))
	{
		if(get_bool(&philo->philo_mutex, &philo->full))
			break ;
		eat(philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if(table->nbr_limit_meals == 0)
		return ;
	else if(table->philo_nbr == 1)
		 safe_thread(&table->philos[0].thread_id, one_philo, &table->philos[0], CREATE);
	{
		while(++i < table->philo_nbr)
			safe_thread(&table->philos[i].thread_id, dinner_simulation, &table->philos[i], CREATE);
	}
	safe_thread(&table->monitor, monitor_dinner, table, CREATE);
	table->start_sim = gettime(MILLISECONDS);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = -1;
	while(++i < table->philo_nbr)
		safe_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&table->table_mutex, &table->end_sim, true);
}
