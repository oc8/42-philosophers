#include "philo.h"

void	quit(char *error, t_main *main)
{
	(void)main;
	printf("\033[31m%s\033[0m\n", error);
	if (error)
		exit(1);
	exit(0);
}