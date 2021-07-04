#include "philo.h"

void	quit(char *error, t_main *main)
{
	size_t	i;

	(void)main;
	printf("\033[31m%s\033[0m\n", error);
	i = -1;
	while (++i < main->number_of_fork)
		pthread_mutex_destroy(&main->mutex[i]);
	pthread_mutex_destroy(&main->print_mutex);
	if (error)
		exit(1);
	exit(0);
}