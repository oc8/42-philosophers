#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	mutex;
}				t_philo;


typedef struct	s_main
{
	size_t			number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			number_of_times_each_philosopher_must_eat;
	size_t			die_flag;
	t_philo			philo;
	// int				fork_nbr;
	pthread_mutex_t	*mutex;
	// pthread_t	*thread;
}				t_main;

typedef struct	s_thread
{
	t_main	*main;
	int		id;
}				t_thread;

void	*philo(void *p);
void	print_philo(char c, int philo);

/*
**	utils
*/
void	quit(char *error, t_main *main);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nbr, size_t size);
int		ft_atoi(const char *str);

#endif
