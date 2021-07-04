#include "philo.h"

void	philo_sleep(size_t i, t_main *main)
{
	print_philo('s', i, main);
	usleep(main->time_to_sleep * 1000);
}

void	philo_eat(size_t i, t_main *main)
{
	// if (i % 2)
	// while (get_time_diff_ms(main->philo[i].time_last_eat) < main->time_to_die - 15)
	// 	;
	print_philo('e', i, main);
	main->philo[i].time_last_eat = get_time_now();
	usleep(main->time_to_eat * 1000);
	pthread_mutex_unlock(&main->mutex[i]);
	if (i || main->number_of_philosophers == 1)
		pthread_mutex_unlock(&main->mutex[i - 1]);
	else
		pthread_mutex_unlock(&main->mutex[main->number_of_philosophers - 1]);
}

void	philo_thinking(size_t i, t_main *main)
{
	print_philo('t', i, main);
}

void	philo_take_fork(size_t i, t_main *main)
{
	if (i || main->number_of_philosophers == 1)
		pthread_mutex_lock(&main->mutex[i - 1]);
	else
		pthread_mutex_lock(&main->mutex[main->number_of_philosophers - 1]);
	print_philo('f', i, main);
	pthread_mutex_lock(&main->mutex[i]);
	print_philo('f', i, main);
}
