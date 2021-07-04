#include "philo.h"

static void	set_time(t_main *main)
{
	size_t	i;
	t_philo	*philo;

	i = 0;
	while (i < main->number_of_philo)
	{
		philo = &main->philo[i];
		philo->time_last_eat = get_time_now();
		i++;
	}
}

void	check_philo(t_main *main)
{
	size_t	i;
	t_philo	*philo;
	size_t	end;

	set_time(main);
	while (42)
	{
		end = 0;
		i = 0;
		while (i < main->number_of_philo)
		{
			philo = &main->philo[i];
			if (philo->end)
				end++;
			else if (get_time_diff_ms(philo->time_last_eat) > main->time_to_die)
			{
				print_philo('d', i, main);
				return ;
			}
			i++;
		}
		if (end == main->number_of_philo)
			return ;
	}
}
