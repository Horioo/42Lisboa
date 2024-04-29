/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:29:38 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/29 18:59:50 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	gettime(t_time_code time_code)
{
	struct timeval tv;
	if(gettimeofday(&tv, NULL))
		error_exit("Error on GTOD");
	if(time_code == MILLISECONDS)
		return ((tv.tv_sec * 1000) +  (tv.tv_usec / 1000));
	else if (time_code == MICROSECONDS)
		return ((tv.tv_sec * 1000000) + tv.tv_usec);
	else
		error_exit("Wrong input to gettime");
	return (42);
}

void	precise_usleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;
	long	rem;
	
	start = gettime(MICROSECONDS);
	while(gettime(MICROSECONDS) - start < usec)
	{
		if(simulation_finished(table))
			break;
		elapsed = gettime(MICROSECONDS) - start;
		rem = usec - elapsed;
		if(rem > 1000)
			usleep(rem / 2);
		else
			while(gettime(MICROSECONDS) - start < usec)
				;
	}
}

void	error_exit(char *error)
{
	printf(R "%s"RST, error);
	exit(EXIT_FAILURE);
}