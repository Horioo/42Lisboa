/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:09:38 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/17 13:17:47 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table	table;
	if(ac == 5 || ac == 6)
	{
		parsing(&table, av);

		//2) Initialization of the Data on table
		
		//3) Dinner Start

		//4) Leak Solving
	}
	else
		error_exit("Wrong Input:\n"
		G"Correct is: ./philo 5 800 200 200 [5]\n"RST);
}