#include "ft_printf.h"

int ft_printstr(const char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free (num);
	return (len);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printpercent()
{
	write(1, "%", 1);
	return (1);
}