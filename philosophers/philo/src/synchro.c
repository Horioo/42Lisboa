/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:47:16 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/30 14:55:06 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	wait_all_threads(t_table *table)
{
	while(!get_bool(&table->table_mutex, &table->all_threads_ready))
		;
}

bool	all_threads_running(t_mtx *mtx, long *threads, long philo_nbr)
{
	bool ret;

	ret = false;
	safe_mutex(mtx, LOCK);
	if(*threads == philo_nbr)
		ret = true;
	safe_mutex(mtx, UNLOCK);
	return (ret);
}

void	increment_long(t_mtx *mtx, long *value)
{
	safe_mutex(mtx, LOCK);
	(*value)++;
	safe_mutex(mtx, UNLOCK);
}