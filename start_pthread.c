#include "philosophers.h"

void	*start_simulation(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	philo->last_meal = time_cur(philo->st_time);
	if (philo->d)
		timer(philo->time_eat);
	while (philo->num_meals)
	{
		take_forks(philo);
		if (!philo_eat(philo))
			return (NULL);
		philo_sleep(philo);
		print_mess(philo, "is thinking");
	}
	return (NULL);
}

void	stop_simulation(t_indata *in_data)
{
	int	i;

	i = -1;
	usleep(100);
	while (++i < in_data->num_philo)
		pthread_detach(in_data->philos[i].philo);
	pthread_mutex_destroy(&in_data->print);
	i = -1;
	while (++i < in_data->num_philo)
		pthread_mutex_destroy(&(in_data->forks[i]));
	i = -1;
	free(in_data->forks);
	free(in_data->philos);
}

// void	check_cycl(t_indata *in_data)
// {
// 	int	i;
// 	int	meals;

// 	i = 0;
// 	meals = 1;
// 	while (i < in_data->num_philo)
// 	{
// 		meals += in_data->philos[i].meal_d;
// 		if (!in_data->philos[i].meal_d && time_cur(in_data->start_time)
// 			- in_data->philos[i].last_meal > in_data->time_to_die)
// 		{
// 			death_print(&in_data->philos[i], "died");
// 			stop_simulation(in_data);
// 			return ;
// 		}
// 		i++;
// 	}
// 	if (meals == in_data->num_philo)
// 	{
// 		meals_print(in_data, "lunch over");
// 		stop_simulation(in_data);
// 		return ;
// 	}
// }

void	start_pthread(t_indata *in_data)
{
	int		i;

	in_data->start_time = time_creation();
	i = -1;
	while (++i < in_data->num_philo)
	{
		in_data->philos[i].st_time = in_data->start_time;
		pthread_create(&(in_data->philos[i].philo), NULL, \
			start_simulation, (void *)&(in_data->philos[i]));
	}
	timer(10);
	while (1)
	{
		// check_cycl(in_data);
		i = 0;
		int meals = 0;
		while (i < in_data->num_philo)
		{
			meals += in_data->philos[i].meal_d;
			if (!in_data->philos[i].meal_d && time_cur(in_data->start_time) \
				- in_data->philos[i].last_meal > (uint64_t)in_data->time_to_die)
			{
				death_print(&in_data->philos[i], "died");
				stop_simulation(in_data);
				return ;
			}
			i++;
		}
		if (meals == in_data->num_philo)
		{
			meals_print(in_data, "lunch over");
			stop_simulation(in_data);
			return ;
		}
	}
}
