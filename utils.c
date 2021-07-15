#include "philosophers.h"

int		ft_atoi(const char *s)
{
	int			i;
	long long	num;
	int			min;

	i = 0;
	num = 0;
	min = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
	i++;
	if (s[i] == '-' || s[i] == '+')
	{
	min += -2 * (s[i] == '-');
	i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
	num = num * 10 + (s[i] - '0');
	i++;
	}
	num = num * min;
	return (num);
}

