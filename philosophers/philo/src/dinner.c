#include "inc/philo.h"

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


