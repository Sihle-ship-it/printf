#include <stdarg.h>
#include <stdio.h>

/**
* print_binary - Converts an unsigned int to binary and prints it
* @n: unsigned int to be converted to binary
*
* Return: Number of characters printed
*/
int print_binary(unsigned int n)
{
int binary[32] = {0};
int i = 0;
int count = 0;

while (n > 0)
{
binary[i] = n % 2;
n /= 2;
i++;
}

for (i = i - 1; i >= 0; i--)
{
putchar(binary[i] + '0');
count++;
}

return (count);
}

/**
* _printf - Custom printf function
* @format: format string
*
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *p;

va_start(args, format);

for (p = format; *p != '\0'; p++)
{
if (*p != '%')
{
putchar(*p);
count++;
continue;
}

switch (*++p)
{
case 'b':
{
unsigned int n = va_arg(args, unsigned int);
count += print_binary(n);
break;
}

default:
putchar(*p);
count++;
break;
}
}

va_end(args);

return (count);
}

