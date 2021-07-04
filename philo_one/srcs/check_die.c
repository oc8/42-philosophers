#include "philo.h"

void	check_philo(t_main *main)
{
	size_t	i;
	t_philo	*philo;
	size_t	end;

	i = 0;
	while (i < main->number_of_philosophers)
	{
		philo = &main->philo[i];
		philo->time_last_eat = get_time_now();
		i++;
	}
	while (42)
	{
		end = 0;
		i = 0;
		while (i < main->number_of_philosophers)
		{
			philo = &main->philo[i];
			// printf("philo: %zu last_eat: %zu\n", i+1, get_time_diff_ms(philo->time_last_eat));
			if (philo->end)
				end++;
			else if (get_time_diff_ms(philo->time_last_eat) > main->time_to_die)
			{
				print_philo('d', i, main);
				printf("philo: %zu last_eat: %zu\n", i+1, get_time_diff_ms(philo->time_last_eat));
				return ;
			}
			i++;
		}
		if (end == main->number_of_philosophers)
			return ;
	}
}
