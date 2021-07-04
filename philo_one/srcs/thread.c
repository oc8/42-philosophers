#include "philo.h"

void	create_philo(t_main *main)
{
	size_t		i;
	t_thread	*thread;

	main->mutex = ft_calloc(main->number_of_fork, sizeof(pthread_mutex_t));//free
	i = -1;
	while (++i < main->number_of_fork)
		// main->mutex[i] = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(&main->mutex[i], NULL);
	pthread_mutex_init(&main->print_mutex, NULL);
	thread = ft_calloc(main->number_of_philosophers, sizeof(t_thread));//free
	main->philo = ft_calloc(main->number_of_philosophers, sizeof(t_philo));//free
	i = 0;
	while (i < main->number_of_philosophers)
	{
		thread[i] = (t_thread){main, i};
		usleep(100);
		if (pthread_create(&main->philo[i].thread, NULL, &philo, &thread[i]))
			quit("pthread_creat() error", main);
		i++;
	}
	// usleep(500);
	// i = 1;
	// while (i < main->number_of_philosophers)
	// {
	// 	thread[i] = (t_thread){main, i};
	// 	if (pthread_create(&main->philo[i].thread, NULL, &philo, &thread[i]))
	// 		quit("pthread_creat() error", main);
	// 	i += 2;
	// }
	// i = -1;
	// while (++i < main->number_of_philosophers)
	// 	pthread_join(threads[i], NULL);
}
