#include "philo_one.h"

void	quit(char *error, t_main *main)
{
	(void)main;
	if (error)
		exit(1);
	exit(0);
}