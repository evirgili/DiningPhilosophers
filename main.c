#include "philosophers.h"

int  valid_arg(int argc, char **argv)
{
	int		i;

	if ((argc < 5) && (argc > 6))
	return (0);
	i = 1;
	while(i < argc - 1)
	{
	if (ft_atoi(argv[i]) <= 0)
	return (0);
	i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_indata	indata;

	if (!valid_arg(argc, argv))
	{
		printf("Invalid argument!\n");
		return (0);
	}
	indata.num_philo = ft_atoi(argv[1]);
	indata.time_to_die = ft_atoi(argv[2]);
	indata.time_to_eat = ft_atoi(argv[3]);
	indata.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		indata.num_times_eat = ft_atoi(argv[5]);
	init_philo(&indata);
	start_pthread(&indata);
}
