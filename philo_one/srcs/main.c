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
	if (i > 10)
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

}

void	*philo(void *p)
{
	t_main		*main;
	t_thread	*thread;

	thread = (t_thread *)p;
	main = thread->main;
	main->die_flag = thread->id;
	return (NULL);
}

void	create_philo(t_main *main)
{
	size_t		i;
	t_thread	*thread;
	pthread_t	*threads;

	thread = ft_calloc(main->number_of_philosophers, sizeof(t_thread));
	threads = ft_calloc(main->number_of_philosophers, sizeof(pthread_t));
	i = 0;
	while (i < main->number_of_philosophers)
	{
		thread[i] = (t_thread){main, i};
		if (pthread_create(&threads[i], NULL, &philo, &thread[i]))
			quit("pthread_creat() error", main);
			// printf("error\n");
		i++;
	}
	i = -1;
	while (++i < main->number_of_philosophers)
		pthread_join(threads[i], NULL);
}

int	main(int argc, char *argv[])
{
	t_main	main;

	if (argc != 5 && argc != 6)
	{
		printf("4 or 5 arguments are required\n");
		return (-1);
	}
	ft_bzero(&main, sizeof(main));
	set_args(argc, argv, &main);
	create_philo(&main);
	while (!main.die_flag)
		;
	printf("\033[31mtimestamp_in_ms \033[1m%d died\033[0m\n", main.die_flag);
	return (0);
}
