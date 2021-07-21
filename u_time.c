#include "philosophers.h"

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

void	timer(uint64_t time)
{
	uint64_t	start;

	start = time_creation();
	while (time_cur(start) < time)
		usleep(100);
}
