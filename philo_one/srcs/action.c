#include "philo.h"

void	philo_sleep(size_t i, t_main *main)
{
	print_philo('s', i, main);
	my_sleep(main->time_to_sleep);
}

void	philo_eat(size_t i, t_main *main)
{
	print_philo('e', i, main);
	main->philo[i].time_last_eat = get_time_now();
	my_sleep(main->time_to_eat);
	pthread_mutex_unlock(main->philo[i].fork[1]);
	pthread_mutex_unlock(main->philo[i].fork[0]);
}

void	philo_thinking(size_t i, t_main *main)
{
	print_philo('t', i, main);
}

void	philo_take_fork(size_t i, t_main *main)
{
	pthread_mutex_lock(main->philo[i].fork[1]);
	print_philo('f', i, main);
	pthread_mutex_lock(main->philo[i].fork[0]);
	print_philo('f', i, main);
}
