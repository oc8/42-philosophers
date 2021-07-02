#include "philo_one.h"

void	print_philo(char c, int philo, t_main *main)
{
	if (c == 'f')
	{ // num
		printf("\033[32mtimestamp_in_ms \033[1m%d has taken a fork\033[0m\n", philo);
	}
	else if (c == 'e')
	{
		printf("\033[32mtimestamp_in_ms \033[1m%d is eating\033[0m\n", philo);
	}
	else if (c == 's')
	{
		printf("\033[32mtimestamp_in_ms \033[1m%d is sleeping\033[0m\n", philo);
	}
	else if (c == 't')
	{
		printf("\033[32mtimestamp_in_ms \033[1m%d is thinking\033[0m\n", philo);
	}
	else if (c == 'd')
	{
		printf("\033[31mtimestamp_in_ms \033[1m%d died\033[0m\n", philo);
	}
}
