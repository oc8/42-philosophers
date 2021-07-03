#include "philo.h"

void	print_philo(char c, size_t philo, t_main *main)
{
	main->philo[philo].status = c;
	if (c == 'f')
		printf("\033[33mtimestamp_in_ms \033[1m%zu has taken a fork\033[0m\n", philo);
	else if (c == 'e')
		printf("\033[32mtimestamp_in_ms \033[1m%zu is eating\033[0m\n", philo);
	else if (c == 's')
		printf("\033[34mtimestamp_in_ms \033[1m%zu is sleeping\033[0m\n", philo);
	else if (c == 't')
		printf("\033[36mimestamp_in_ms \033[1m%zu is thinking\033[0m\n", philo);
	else if (c == 'd')
		printf("\033[31mtimestamp_in_ms \033[1m%zu died\033[0m\n", philo);
}
