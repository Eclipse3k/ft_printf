#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

// * FUNCION PARA APRENDER NUMERO ARGUMENTOS VARIABLEs

double avarage(int num_args, ...)
{
	double	value = 0;
	int x;
	va_list args;
	printf("number of args: %d\n", num_args);
	va_start(args, num_args);
	for (int i = 0; i < num_args; i++)
	{
		value += va_arg(args, int);
		printf("x: %f\n", value);
	}
	va_end(args);
	return(value/num_args);
}

int		count(char *str)
{
	int	i = 0;
	while (*str)
	{
		if (*str == '%')
			i++;
		str++;
	}
	return i;
}

char	*name(char *str, ...)
{
	int num_args = 0;

	num_args = count(str);

	va_list args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str += 2;
			int x = va_arg(args, int);
			printf("%d", x);
		}
		write(1, &(*str), 1);
		str++;
	}
    va_end(args);
}

int main(int argc, char const *argv[])
{
	name("Tengo %d años %d y vivo en un %d\nPablo tiene %d hermanos", 19, 7, 5);
	return 0;
}
