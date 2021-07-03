#include "philo.h"

struct timeval	ft_time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time);
}

float	ft_time_diff_ms(struct timeval t1, struct timeval t0)
{
	return ((t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) \
		/ 1000.0f);
}
