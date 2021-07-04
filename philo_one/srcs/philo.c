#include "philo.h"

static size_t	nbr_loop(int *loop_nbr_defined, t_main *main)
{
	size_t		loop_nbr;

	*loop_nbr_defined = 0;
	if (main->number_of_times_each_philosopher_must_eat)
	{
		loop_nbr = main->number_of_times_each_philosopher_must_eat;
		*loop_nbr_defined = 1;
	}
	else
		loop_nbr = 42;
	return (loop_nbr);
}

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
	loop_nbr = nbr_loop(&loop_nbr_defined, main);
	while (loop_nbr)
	{
		philo_take_fork(thread->id, main);
		philo_eat(thread->id, main);
		philo_sleep(thread->id, main);
		philo_thinking(thread->id, main);
		if (loop_nbr_defined)
			loop_nbr--;
	}
	philo->end = 1;
	return (NULL);
}
