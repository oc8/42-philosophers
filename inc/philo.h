#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	char		status;
	struct timeval	time_last_eat;
	pthread_t	thread;
}				t_philo;


typedef struct	s_main
{
	size_t			number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			number_of_times_each_philosopher_must_eat;
	t_philo			*philo;
	// int				fork_nbr;
	pthread_mutex_t	*mutex;
	// pthread_t	*thread;
}				t_main;

typedef struct	s_thread
{
	t_main	*main;
	size_t	id;
}				t_thread;

/*
**	philo
*/
void	*philo(void *p);
void	print_philo(char c, size_t philo, t_main *main);
void	create_philo(t_main *main);
void	check_philo(t_main *main);

/*
**	utils
*/
void	quit(char *error, t_main *main);
void	ft_bzero(void *s, size_t n);
void	set_args(int argc, char *argv[], t_main *main);
void	*ft_calloc(size_t nbr, size_t size);
int		ft_atoi(const char *str);
struct timeval	ft_time_now(void);
float	ft_time_diff_ms(struct timeval t1, struct timeval t0);

#endif
