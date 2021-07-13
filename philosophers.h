#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
#include <stdlib.h>

typedef struct s_philos
{
    pthread_t		philo;
}   t_philos;

typedef struct s_inter_data
{
    int     num_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     num_times_eat;
    t_philos   *philos;

}   t_inter_data;

void	start(t_inter_data *in_data);


#endif
