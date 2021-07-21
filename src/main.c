#include "philosophers.h"

int	valid_arg(int argc, char **argv)
{
	int	i;

	if ((argc < 5) && (argc > 6))
		return (0);
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	if (argc == 6 && (ft_atoi(argv[argc - 1]) < 1))
		return (0);
	return (1);
}

void	init_data(t_indata *indata, int argc, char **argv)
{
	indata->num_philo = ft_atoi(argv[1]);
	indata->time_to_die = ft_atoi(argv[2]);
	indata->time_to_eat = ft_atoi(argv[3]);
	indata->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		indata->num_times_eat = ft_atoi(argv[5]);
	else
		indata->num_times_eat = -1;
	indata->philos = (t_philos *) malloc(sizeof(t_philos) * indata->num_philo);
	indata->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) \
						* indata->num_philo);
	check_allocation(indata->philos);
	check_allocation(indata->forks);
}

void	init_philo(t_indata *in_data)
{
	int	i;

	i = -1;
	while (++i < in_data->num_philo)
		pthread_mutex_init(&(in_data->forks[i]), NULL);
	i = -1;
	pthread_mutex_init(&in_data->print, NULL);
	while (++i < in_data->num_philo)
	{
		memset(&in_data->philos[i], 0, sizeof(t_philos));
		in_data->philos[i].pos = i + 1;
		in_data->philos[i].d = (in_data->philos[i].pos % 2 == 1);
		in_data->philos[i].time_die = in_data->time_to_die;
		in_data->philos[i].time_eat = in_data->time_to_eat;
		in_data->philos[i].time_sleep = in_data->time_to_sleep;
		in_data->philos[i].num_meals = in_data->num_times_eat;
		in_data->philos[i].count_meals = 0;
		in_data->philos[i].meal_d = 0;
		in_data->philos[i].forks[0] = &in_data->forks[i];
		in_data->philos[i].forks[1] = &in_data->forks[(i + 1) \
					% in_data->num_philo];
		in_data->philos[i].print = &in_data->print;
	}
}

int	main(int argc, char **argv)
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
