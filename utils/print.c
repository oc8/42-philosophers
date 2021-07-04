#include "philo.h"

void	print_philo(char c, size_t philo, t_main *main)
{
	main->philo[philo].status = c;
	// philo++;
	pthread_mutex_lock(&main->print_mutex);
	if (c == 'f')
		printf("\033[33m%zu \033[1m%zu has taken a fork\033[0m\n", get_time_diff_ms(main->time_start), philo);
	else if (c == 'e')
		printf("\033[32m%zu \033[1m%zu is eating\033[0m\n", get_time_diff_ms(main->time_start), philo);
	else if (c == 's')
		printf("\033[34m%zu \033[1m%zu is sleeping\033[0m\n", get_time_diff_ms(main->time_start), philo);
	else if (c == 't')
		printf("\033[36m%zu \033[1m%zu is thinking\033[0m\n", get_time_diff_ms(main->time_start), philo);
	else if (c == 'd')
		printf("\033[31m%zu \033[1m%zu died\033[0m\n", get_time_diff_ms(main->time_start), philo);
	pthread_mutex_unlock(&main->print_mutex);
}
