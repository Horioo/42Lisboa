/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:06:37 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/04/26 18:34:16 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

# include <sys/time.h>
# include <limits.h>
# include <errno.h>

// ./philo 5 800 200 200 [5]
// ./phile nbr_philo time_to_die time_to_eat time_to_sleep [nbr_of_meals_eaten]
typedef pthread_mutex_t	t_mtx;
typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;
typedef struct s_table	t_table;
typedef enum e_opcode	t_opcode;

# define RST   "\x1B[0m"
# define R     "\x1B[1;31m"
# define G   "\x1B[1;32m"

enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
};

struct	s_fork
{
	t_mtx	fork;
	int		fork_id;
};

struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_table		*table;
};

struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_limit_meals;
	long		start_sim;
	bool		end_sim;
	bool		all_threads_ready;
	t_fork		*forks;
	t_philo		*philos;
};

void	error_exit(char *error);
void	parsing(t_table *table, char **av);
void	*safe_malloc(size_t bytes);
void	safe_thread(pthread_t *thread, void *(*foo)(void *), 
		void *data, t_opcode opcode);
void	safe_mutex(t_mtx *mutex, t_opcode opcode);
void	table_init(t_table *table);

#endif