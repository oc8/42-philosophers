#include "philo.h"

void	create_philo(t_main *main)
{
	size_t		i;
	t_thread	*thread;

	main->mutex = ft_calloc(main->number_of_philosophers, sizeof(pthread_mutex_t));
	i = -1;
	while (++i < main->number_of_philosophers)
		// main->mutex[i] = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(&main->mutex[i], NULL);
	thread = ft_calloc(main->number_of_philosophers, sizeof(t_thread));
	main->philo = ft_calloc(main->number_of_philosophers, sizeof(t_philo));
	i = -1;
	while (++i < main->number_of_philosophers)
	{
		thread[i] = (t_thread){main, i};
		print_philo('f', i + 1, main);
		if (pthread_create(&main->philo[i].thread, NULL, &philo, &thread[i]))
			quit("pthread_creat() error", main);
	}
	// i = -1;
	// while (++i < main->number_of_philosophers)
	// 	pthread_join(threads[i], NULL);
}
