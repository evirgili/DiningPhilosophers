#include "philosophers.h"

void	*asd(void *arg) {
	printf("qwewqeqweqwe\n");
	return (NULL);
}

void	start(t_inter_data *in_data) {
	int i = -1;
	while (++i < in_data->num_philo) {
		pthread_create(&(in_data->philos[i].philo), NULL, asd, &in_data->philos[i]);
	}
	sleep(5);
}
