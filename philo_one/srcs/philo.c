#include "philo.h"

void	*philo(void *p)
{
	t_main		*main;
	t_thread	*thread;
	size_t		loop_nbr;
	int			loop_nbr_defined;
	t_philo		*philo;

	thread = (t_thread *)p;
	main = thread->main;
	philo = &main->philo[thread->id];
	// philo->time_last_eat = ft_time_now();
	loop_nbr_defined = 0;
	if (main->number_of_times_each_philosopher_must_eat)
	{
		loop_nbr = main->number_of_times_each_philosopher_must_eat;
		loop_nbr_defined = 1;
	}
	else
		loop_nbr = 42;
	if (thread->id % 2 == 0)
		usleep(100);
	while (loop_nbr)
	{
		pthread_mutex_lock(&main->mutex[thread->id]);
		if (thread->id)
			pthread_mutex_lock(&main->mutex[thread->id + 1]);
		else
			pthread_mutex_lock(&main->mutex[main->number_of_philosophers - 1]);
		print_philo('e', thread->id + 1, main);
		philo->time_last_eat = ft_time_now();
		usleep(main->time_to_eat);
		print_philo('t', thread->id + 1, main);
		pthread_mutex_unlock(&main->mutex[thread->id]);
		if (thread->id)
			pthread_mutex_unlock(&main->mutex[thread->id + 1]);
		else
			pthread_mutex_unlock(&main->mutex[main->number_of_philosophers - 1]);
		print_philo('s', thread->id + 1, main);
		usleep(main->time_to_sleep);
		if (loop_nbr_defined)
			loop_nbr--;
	}
	printf("end\n");
	return (NULL);
}
