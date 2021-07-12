#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>

typedef struct s_philo
{
 int  num_philo;
 int  time_to_die;
 int  time_to_eat;
 int  time_to_sleep;
 int  num_times_eat;
} t_philo;

#endif