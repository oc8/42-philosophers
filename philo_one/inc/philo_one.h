#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>

typedef struct	s_main
{
	float		number_of_philosophers;
	float		time_to_die;
	float		time_to_eat;
	float		time_to_sleep;
	float		number_of_times_each_philosopher_must_eat;
	int			die_flag;
	// pthread_t	*thread;
}				t_main;

typedef struct	s_thread
{
	t_main	*main;
	int		id;
}				t_thread;

void	*philo(void *p);

/*
**	utils
*/
void	quit(char *error, t_main *main);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nbr, size_t size);
int		ft_atoi(const char *str);

#endif
