#include "philo.h"

void	check_philo(t_main *main)
{
	size_t	i;
	t_philo	*philo;

	i = 0;
	while (i < main->number_of_philosophers)
	{
		philo = &main->philo[i];
		philo->time_last_eat = ft_time_now();
		i++;
	}
	while (42)
	{
		i = 1;
		while (i < 2)
		{
			philo = &main->philo[i];
			if (ft_time_diff_ms(ft_time_now(), philo->time_last_eat) > main->time_to_die)
			{
				print_philo('d', i + 1, main);
				printf("%f\n", ft_time_diff_ms(ft_time_now(), philo->time_last_eat));
				i = -1;
				while (++i < main->number_of_philosophers)
					pthread_mutex_destroy(&main->mutex[i]);
				return ;
			}
			i++;
		}
	}
}
