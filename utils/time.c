#include "philo.h"

struct timeval	get_time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time);
}

size_t	get_time_diff_ms(struct timeval start)
{
	struct timeval	end;

	end = get_time_now();
	return ((end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) \
		/ 1000);
}
