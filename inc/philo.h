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
	pthread_mutex_t	*fork[2];
	char			status;
	int				end;
	struct timeval	time_last_eat;
	pthread_t		thread;
}				t_philo;

struct	s_thread;

typedef struct s_main
{
	size_t			number_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			number_of_times_each_philosopher_must_eat;
	t_philo			*philo;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print_mutex;
	struct timeval	time_start;
	struct s_thread	*threads;
}				t_main;

typedef struct s_thread
{
	t_main	*main;
	size_t	id;
}				t_thread;

/*
**	philo
*/
void			*philo(void *p);
void			philo_sleep(size_t i, t_main *main);
void			philo_eat(size_t i, t_main *main);
void			philo_thinking(size_t i, t_main *main);
void			philo_take_fork(size_t i, t_main *main);

void			print_philo(char c, size_t philo, t_main *main);
void			create_philo(t_main *main);
void			check_philo(t_main *main);

/*
**	utils
*/
void			quit(char *error, t_main *main);
void			ft_bzero(void *s, size_t n);
void			set_args(int argc, char *argv[], t_main *main);
void			*ft_calloc(size_t nbr, size_t size);
int				ft_atoi(const char *str);
struct timeval	get_time_now(void);
void			my_sleep(size_t time);
size_t			get_time_diff_ms(struct timeval start);

#endif
