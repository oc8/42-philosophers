#include "philo.h"

static void	init_philo(t_main *main)
{
	size_t		i;
	t_philo		*philo;

	main->philo = ft_calloc(main->number_of_philo, sizeof(t_philo));
	i = -1;
	while (++i < main->number_of_philo)
	{
		philo = &main->philo[i];
		philo->fork[0] = &main->mutex[i];
		if (i)
			philo->fork[1] = &main->mutex[i - 1];
		else
			philo->fork[1] = &main->mutex[main->number_of_philo - 1];
	}
}

void	create_philo(t_main *main)
{
	size_t		i;
	t_thread	*threads;

	main->mutex = ft_calloc(main->number_of_philo, sizeof(pthread_mutex_t));
	i = -1;
	while (++i < main->number_of_philo)
		pthread_mutex_init(&main->mutex[i], NULL);
	pthread_mutex_init(&main->print_mutex, NULL);
	threads = ft_calloc(main->number_of_philo, sizeof(t_thread));
	init_philo(main);
	i = 0;
	while (i < main->number_of_philo)
	{
		threads[i] = (t_thread){main, i};
		usleep(100);
		if (pthread_create(&main->philo[i].thread, NULL, &philo, &threads[i]))
			quit("pthread_creat() error", main);
		i++;
	}
	main->threads = threads;
}
