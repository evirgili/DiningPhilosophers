#include "philosophers.h"

int  valid_arg(int argc, char **argv)
{
	int		i;

	if ((argc < 5) && (argc > 6))
		return (0);
	i = 1;
	while(i < argc - 2)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (0);
			i++;
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[argc - 1]) < 1)
			return (0);
	}
	return (1);
}

int		errors(t_indata *in_data, char *str)
{
	free(in_data);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	return (0);
}

void	init_data(t_indata *indata, int argc, char **argv)
{
	indata->num_philo = ft_atoi(argv[1]);
	indata->time_to_die = ft_atoi(argv[2]);
	indata->time_to_eat = ft_atoi(argv[3]);
	indata->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		indata->num_times_eat = ft_atoi(argv[5]);
	indata->philos = (t_philos *) malloc(sizeof(t_philos) * indata->num_philo); //check NULL
	indata->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * indata->num_philo); // check NULL
}

int main(int argc, char **argv)
{
	t_indata	indata;

	if (!valid_arg(argc, argv))
	{
		printf("Invalid argument!\n");
		return (0);
	}
	init_data(&indata, argc, argv);
	init_philo(&indata);
	start_pthread(&indata);
}
