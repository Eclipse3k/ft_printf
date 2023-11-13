#include "ft_printf.h"
#include <stdio.h>

int	ft_formats(va_list args, char type)
{
	int count;

	count = 0;
	if (type == 'c')
		count += ft_printchar(va_arg(args, int));	
	if (type == 's')
		count += ft_printstr(va_arg(args,const char *));
	if (type == 'p')
	 	count += ft_printptr(va_arg(args, void *));
	if (type == 'd' || type == 'i')
		count += ft_printnbr(va_arg(args, int));
	if (type == 'u')
	 	count += ft_print_unsigned(va_arg(args, unsigned int));
	if (type == 'x')
	 	count += ft_printhex(va_arg(args, unsigned int), 0);
	if (type == 'X')
	 	count += ft_printhex(va_arg(args, unsigned int), 1);
	if (type == '%')
	 	count += ft_printpercent();	
	return (count);
}
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	count;
	int	i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			count += ft_printchar(format[i]);
		format++;
	}
	va_end(args);
	return (count);
}
// int main()
// {
// 	void *pointer_to_main = (void *) main;

// 	printf("Stdio: %c\t", 'E');
// 	ft_printf("Print a character: %c, Done!\n", 'E');
// 	printf("Stdio: %s\t", "Soy Jorge");
// 	ft_printf("Print a string: %s, Done!\n", "Soy Jorge");
// 	printf("Stdio: %d\t", 19);
// 	ft_printf("Print an integer: %d, Done!\n", 19);
// 	printf("Stdio: %i\t", -19);
// 	ft_printf("Print a negative integer: %i, Done!\n", -19);
// 	printf("Stdio: %u\t", __UINT32_MAX__);
// 	ft_printf("Print an unsigned integer: %u, Done!\n", __UINT32_MAX__);
// 	printf("Stdio: %%\t");
// 	ft_printf("Print a percent sign: %%, Done!\n");
// 	printf("Stdio: %p\t", pointer_to_main);
// 	ft_printf("Print a pointer: %p, Done!\n", pointer_to_main);
// 	printf("Stdio: %x\t", 1631);
// 	ft_printf("Print a lowercase hex: %x, Done!\n", 1631);
// 	printf("Stdio %X\t", 1631);
// 	ft_printf("Print an uppercase hex: %X, Done!\n", 1631);
// }