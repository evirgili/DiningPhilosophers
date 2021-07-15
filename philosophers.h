#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
#include <stdlib.h>
# include <sys/time.h>

typedef struct s_philos
{
	pthread_t		philo;
}	t_philos;

typedef struct s_indata
{
	int		num_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_times_eat;
	t_philos	*philos;
	unsigned long	start_time;
	int		dead_philo;

}		t_indata;

void	start_pthread(t_indata *in_data);
void	init_philo(t_indata *indata);
int		ft_atoi(const char *s);
int		time_creation(t_indata *in_data);


#endif
