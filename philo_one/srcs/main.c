#include "philo.h"

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
	main.time_start = get_time_now();
	create_philo(&main);
	check_philo(&main);
	quit(0, &main);
	return (0);
}
