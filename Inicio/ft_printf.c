//#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int	has_flags(const char *format)
{
	if (*format == ' ' || *format == '+' || *format == '#')
		return (1); //LLamar a la funcion desde aqui y devolver el string
	return (0);
}
int	has_width(const char *format)
{
	int	width;

	width = 0;
	if (*format >= '0' && *format <= '9')
		width = printf_width(format);
	return (width);
}
int	has_width(const char *format)
{
	int	precision;

	precision = -1;
	if (*format >= '0' && *format <= '9')
	{
		format++;
		precision = printf_precision(format);
	}
	return (precision);
}
int	*printf_flags(const char *format)
{
	int	flags[3];
	/*
		0 -> '#'
		1 -> ' '
		2 -> '+'
	*/
	//ft_memset 		//Inicializar a 0 el array
	while (*format == ' ' || *format == '+' || *format == '#')
	{
		if (*format == '#')
			flags[0] = 1;
		if (*format == ' ')
			flags[1] = 1;
		if (*format == '+')
			flags[2] = 1;
		format++;
	}
	return (flags);
}
int	printf_width(const char *format)
{
	int	width;

	width = 0;
	while (*format >= '0' && *format <= '9')
	{
		width == width * 10 + (*format - '0');
		format++;
	}
	return (width);
}

int	printf_precision(const char *format)
{
	int	precision;

	precision = 0;
		while (*format >= '0' && *format <= '9')
	{
		precision ==precision * 10 + (*format - '0');
		format++;
	}
	return (precision);
}