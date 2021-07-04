#include "philo.h"

int	ft_atoi(const char *str)
{
	long long	rs;
	int			i;
	int			neg;

	neg = 1;
	rs = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rs = rs * 10 + (str[i++] - '0') * neg;
		if (rs > INT_MAX)
			return (INT_MAX);
		else if (rs < INT_MIN)
			return (INT_MIN);
	}
	return (rs);
}
