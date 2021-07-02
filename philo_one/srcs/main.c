#include "philo_one.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	pars(char *str, t_main *main)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_num(str[i]))
			quit("arg is not a number", main);
		i++;
	}
	if (i > 10) // check num
		quit("arg is not a integer", main);
	return (ft_atoi(str));

}

void	set_args(int argc, char *argv[], t_main *main)
{
	main->number_of_philosophers = pars(argv[1], main);
	main->time_to_die = pars(argv[2], main);
	main->time_to_eat = pars(argv[3], main);
	main->time_to_sleep = pars(argv[4], main);
	if (argc == 6)
		main->number_of_times_each_philosopher_must_eat = pars(argv[5], main);
	// main->fork_nbr = main->number_of_philosophers * 2;

}

void	*philo(void *p)
{
	t_main		*main;
	t_thread	*thread;

	thread = (t_thread *)p;
	main = thread->main;
	while (42)
	{
		pthread_mutex_lock(&main->mutex[thread->id]);
		if (thread->id)
			pthread_mutex_lock(&main->mutex[thread->id + 1]);
		else
			pthread_mutex_lock(&main->mutex[main->number_of_philosophers - 1]);
		print_philo('e', thread->id);
		usleep(main->number_of_times_each_philosopher_must_eat);
		print_philo('t', thread->id);
		pthread_mutex_unlock(&main->mutex[thread->id]);
		if (thread->id)
			pthread_mutex_unlock(&main->mutex[thread->id + 1]);
		else
			pthread_mutex_unlock(&main->mutex[main->number_of_philosophers - 1]);
		print_philo('s', thread->id);
	}
	main->die_flag = thread->id;
	return (NULL);
}

void	create_philo(t_main *main)
{
	size_t		i;
	t_thread	*thread;
	pthread_t	*threads;

	main->mutex = ft_calloc(main->number_of_philosophers, sizeof(pthread_mutex_t));
	i = -1;
	while (++i < main->number_of_philosophers)
		// main->mutex[i] = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(&main->mutex[i], NULL);
	thread = ft_calloc(main->number_of_philosophers, sizeof(t_thread));
	threads = ft_calloc(main->number_of_philosophers, sizeof(pthread_t));
	i = 1;
	while (++i < main->number_of_philosophers)
	{
		thread[i] = (t_thread){main, i};
		if (pthread_create(&threads[i], NULL, &philo, &thread[i]))
			quit("pthread_creat() error", main);
	}
	while (!main->die_flag)
		;
	print_philo('d', main->die_flag);
	// i = -1;
	// while (++i < main->number_of_philosophers)
	// 	pthread_join(threads[i], NULL);
	i = -1;
	while (++i < main->number_of_philosophers)
		pthread_mutex_destroy(&main->mutex[i]);
}

int	main(int argc, char *argv[])
{
	t_main	main;

	if (argc != 5 && argc != 6)
	{
		printf("4 or 5 arguments are required\n");
		return (-1);
	} // un seul philo ?
	ft_bzero(&main, sizeof(main));
	set_args(argc, argv, &main);
	create_philo(&main);
	return (0);
}
