#include "philo_one.h"

void	ft_test(char ***test)
{
	free(*test);
	*test = 0;
}

int	main()
{
	char	**test;

	test = malloc(10);
	printf("%p\n", test);
	ft_test(&test);
	printf("%p\n", test);
	return (0);
}
