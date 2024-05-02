/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:09:38 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/05/02 17:44:22 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		parsing(&table, av);
		table_init(&table);
		dinner_start(&table);
		clean(&table);
	}
	else
		error_exit("Wrong Input:\n"
			G"Correct is: ./philo 5 800 200 200 [5]\n"RST);
}
