#include "philosophers.h"

void	print_mess(t_philos	*philo, char *str)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d %s\n", time_cur(philo->st_time), philo->pos, str);
	pthread_mutex_unlock(philo->print);
}

void	take_forks(t_philos *philo)
{
	pthread_mutex_lock(philo->forks[philo->d]);
	print_mess(philo, "has taken a fork");
	pthread_mutex_lock(philo->forks[!(philo->d)]);
	print_mess(philo, "has taken a fork");
}

void	timer(uint64_t time)
{
	uint64_t	start;

	start = time_creation();
	while (time_cur(start) < time)
		usleep(500);
}

void	philo_eat(t_philos *philo)
{
	philo->last_meal = time_cur(philo->st_time);
	philo->count_meals++;
	print_mess(philo, "is eating");
	timer(philo->time_eat);
	pthread_mutex_unlock(philo->forks[philo->d]);
	pthread_mutex_unlock(philo->forks[!(philo->d)]);
}

void	philo_sleep(t_philos *philo)
{
	print_mess(philo, "is sleeping");
	timer(philo->time_sleep);
}

void	*start_simulation(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	philo->last_meal = time_cur(philo->st_time);
	while (1)
	{
		print_mess(philo, "is thinking");
		take_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
		if (philo->num_meals == philo->count_meals)
			break ;
	}
	// usleep(1000);
	return (NULL);
}

void	init_philo(t_indata *in_data)
{
	int i;

	i = -1;
	while (++i < in_data->num_philo)
		pthread_mutex_init(&(in_data->forks[i]), NULL);
	i = -1;
	pthread_mutex_init(&in_data->print, NULL);
	while (i++ < in_data->num_philo)
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
		in_data->philos[i].print = &in_data->print;
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

void	death_print(t_philos	*philo, char *str)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d %s\n", time_cur(philo->st_time), philo->pos, str);
}

void	start_pthread(t_indata *in_data)
{
	int i = -1;
	in_data->start_time = time_creation();
	while (++i < in_data->num_philo)
	{
		in_data->philos[i].st_time = in_data->start_time;
		pthread_create(&(in_data->philos[i].philo), NULL, start_simulation, (void *)&(in_data->philos[i]));
	}
	// i = 0;
	// // while (1)
	// // {
	// 	while (i < in_data->num_philo)
	// 	{
	// 		printf("start = %llu\n mael = %d\n die = %d\n", time_cur(in_data->start_time), in_data->philos[i].last_meal, in_data->time_to_die);
	// 		if (time_cur(in_data->start_time) - in_data->philos[i].last_meal > in_data->time_to_die)
	// 				death_print(&in_data->philos[i], "is dead");
	// 		i++;
	// 	}
	// 	i = 0;
	// // }
}
