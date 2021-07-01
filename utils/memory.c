#include "philo_one.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = -1;
	while (n != 0)
	{
		str[++i] = '\0';
		n--;
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
		str[n] = (char)c;
	return (str);
}

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*ptr;

	if (nbr == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(nbr * size);
	if (!ptr)
		return (0);
	ft_memset((unsigned char *)ptr, 0, nbr * size);
	return (ptr);
}
