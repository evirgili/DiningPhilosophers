#include "philosophers.h"

int ft_atoi(const char *s)
{
 int   i;
 long long num;
 int   min;

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

int  valid_arg(int argc, char **argv)
{
 int i;

 if (argc < 5 && argc > 6)
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
 t_philo philo;

 if (!valid_arg(argc, argv))
 {
  printf("Invalid argument!\n");
  return (0);
 }
 philo.num_philo = ft_atoi(argv[1]);
 philo.time_to_die = ft_atoi(argv[2]);
 philo.time_to_eat = ft_atoi(argv[3]);
 philo.time_to_sleep = ft_atoi(argv[4]);
 if (argc == 6)
  philo.num_times_eat = ft_atoi(argv[5]);
 printf("num_philo = %d\n", philo.num_philo);
 printf("time_to_die = %d\n", philo.time_to_die);
 printf("time_to_eat = %d\n", philo.time_to_eat);
 printf("time_to_sleep = %d\n", philo.time_to_sleep);
 printf("num_times_eat = %d\n", philo.num_times_eat);
}