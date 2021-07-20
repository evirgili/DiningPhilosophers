#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
#include <stdlib.h>
# include <sys/time.h>
# include <string.h>
typedef struct s_philos
{
	pthread_t		philo;
	uint64_t		time;
	int				pos;
	int				d;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_meals;
	int				count_meals;
	int				last_meal;
	uint64_t		st_time;
	pthread_mutex_t		*forks[2];
	pthread_mutex_t		*print;
}				t_philos;

typedef struct s_indata
{
	int		num_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_times_eat;
	uint64_t	start_time;
	t_philos	*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	int		dead_philo;

}		t_indata;

void	start_pthread(t_indata *in_data);
void	init_philo(t_indata *indata);
int		ft_atoi(const char *s);
size_t	ft_strlen(const char *s);
uint64_t	time_creation(void);
uint64_t	time_cur(uint64_t start_time);


#endif
