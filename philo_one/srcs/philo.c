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
	// philo->time_last_eat = get_time_now();
	loop_nbr_defined = 0;
	if (main->number_of_times_each_philosopher_must_eat)
	{
		loop_nbr = main->number_of_times_each_philosopher_must_eat;
		loop_nbr_defined = 1;
	}
	else
		loop_nbr = 42;
	while (loop_nbr)
	{
		philo_take_fork(thread->id, main);
		philo_eat(thread->id, main);
		philo_sleep(thread->id, main);
		philo_thinking(thread->id, main);
		if (loop_nbr_defined)
			loop_nbr--;
		// if (main->number_of_philosophers % 2)
		// 	usleep(1000);
	}
	philo->end = 1;
	// printf("end\n");//
	return (NULL);
}
