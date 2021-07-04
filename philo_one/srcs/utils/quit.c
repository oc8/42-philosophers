#include "philo.h"

void	quit(char *error, t_main *main)
{
	size_t	i;

	(void)main;
	if (error)
		printf("\033[31m%s\033[0m\n", error);
	if (main->mutex)
	{
		i = -1;
		while (++i < main->number_of_philo)
			pthread_mutex_destroy(&main->mutex[i]);
		pthread_mutex_destroy(&main->print_mutex);
		free(main->philo);
		free(main->mutex);
		free(main->threads);
	}
	if (error)
		exit(1);
	exit(0);
}
