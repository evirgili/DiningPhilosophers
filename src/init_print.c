#include "philosophers.h"

void	print_mess(t_philos	*philo, char *str)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d %s\n", time_cur(philo->st_time), philo->pos, str);
	pthread_mutex_unlock(philo->print);
}

void	death_print(t_philos	*philo, char *str)
{
	pthread_mutex_lock(philo->print);
	printf("\033[0;31m");
	printf("%lld %d %s\n", time_cur(philo->st_time), philo->pos, str);
}

void	meals_print(t_indata *in_data, char *str)
{
	pthread_mutex_lock(&in_data->print);
	printf("\x1b[33m");
	printf("%s\n", str);
}
