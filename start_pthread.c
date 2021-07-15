#include "philosophers.h"

void	*start_simulation(void *arg)
{
	


	// printf("qwewqeqweqwe\n");
	// return (NULL);
}

void	init_philo(t_indata *indata)
{
	indata->philos = (t_philos *) malloc(sizeof(t_philos) * indata->num_philo);
}

int		time_creation(t_indata *in_data)
{
	return (gettimeofday(&in_data->start_time, NULL));
}

void	start_pthread(t_indata *in_data)
{
	int i = -1;
	while (++i < in_data->num_philo)
		pthread_create(&(in_data->philos[i].philo), NULL, start_simulation, &in_data->philos[i]);
	time_creation(&in_data);
	while (1)
	// {
	// 	if (philo_dead())
	// 	{
	// 		in_data->dead_philo = i + 1;
	// 		return (0)
	// 	}
	// }
	sleep(5);
}
