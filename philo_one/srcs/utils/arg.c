#include "philo.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	pars(char *str, t_main *main)
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
	main->number_of_philo = pars(argv[1], main);
	main->time_to_die = pars(argv[2], main);
	main->time_to_eat = pars(argv[3], main);
	main->time_to_sleep = pars(argv[4], main);
	if (argc == 6)
		main->number_of_times_each_philosopher_must_eat = pars(argv[5], main);
}
