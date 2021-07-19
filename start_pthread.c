#include "philosophers.h"

void	*start_simulation(void *arg)
{
	printf("qwewqeqweqwe\n");
	return (NULL);
}

void	init_philo(t_indata *in_data)
{
	int i;

	i = -1;
	while (++i < in_data->num_philo)
		pthread_mutex_init(&(in_data->forks[i]), NULL);
	i = 0;
	while (i < in_data->num_philo)
	{
		memset(&in_data->philos[i], 0, sizeof(t_philos));
		in_data->philos[i].pos = i + 1;
		in_data->philos[i].d = (in_data->philos[i].pos % 2 == 1);
		in_data->philos[i].time_die = in_data->time_to_die;
		in_data->philos[i].time_eat = in_data->time_to_eat;
		in_data->philos[i].time_sleep = in_data->time_to_sleep;
		in_data->philos[i].num_meals = in_data->num_times_eat;
		in_data->philos[i].count_meals = 0;
		in_data->philos[i].forks[0] = &in_data->forks[i];
		in_data->philos[i].forks[1] = &in_data->forks[(i + 1) % in_data->num_philo];
		i++;
	}
}

uint64_t	time_creation(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec * 0.001);
}

uint64_t	time_cur(uint64_t start_time)
{
	return (time_creation() - start_time);
}

void	start_pthread(t_indata *in_data)
{
	int i = -1;
	while (++i < in_data->num_philo)
		pthread_create(&(in_data->philos[i].philo), NULL, start_simulation, &in_data->philos[i]);
	in_data->start_time = time_creation();
	printf("time: %llu\n", time_cur(in_data->start_time));
	sleep(5);
}
