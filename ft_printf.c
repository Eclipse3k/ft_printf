#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

size_t  count_param(char const *format)
{
    size_t  cont;

    cont = 0;
    while (*format)
    {
        //Esto habrá que cambiarlo más adelante para que no cuente por 2 si aparece %%
        if (*format == '%')
        {
            cont++;
        }
        format++;
    }
    return (cont);
}

int ft_printf(char const *format, ...){
    size_t  len;

    len = count_param(format);
    va_list args;

    va_start (args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format += 2;
            int x = va_arg(args, int);
            printf("%d", x);
        }
        write(1, &(*format), 1);
        format++;
    }
    va_end(args);
    return (1);
}

int main()
{
    ft_printf("Hola soy Jorge, tengo %d años y soy del %d", 19, 2004);
}






