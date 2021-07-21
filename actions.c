#include "philosophers.h"

void	take_forks(t_philos *philo)
{
	pthread_mutex_lock(philo->forks[philo->d]);
	print_mess(philo, "has taken a fork");
	pthread_mutex_lock(philo->forks[!(philo->d)]);
	print_mess(philo, "has taken a fork");
}

void	*philo_eat(t_philos *philo)
{
	philo->last_meal = time_cur(philo->st_time);
	print_mess(philo, "is eating");
	timer(philo->time_eat);
	philo->num_meals--;
	philo->meal_d += (!philo->num_meals);
	pthread_mutex_unlock(philo->forks[philo->d]);
	pthread_mutex_unlock(philo->forks[!(philo->d)]);
	if (philo->meal_d)
		return (NULL);
	return ((void *)philo);
}

void	philo_sleep(t_philos *philo)
{
	print_mess(philo, "is sleeping");
	timer(philo->time_sleep);
}
