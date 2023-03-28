#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
* _printf - prints a formatted string to the console
* @format: the format string to print
* @...: zero or more additional arguments to print
*
* Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list arg_list;
va_start(arg_list, format);

while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'u':
printed_chars += print_u(va_arg(arg_list, unsigned int), 10, 0);
break;
case 'o':
printed_chars += print_o(va_arg(arg_list, unsigned int));
break;
case 'x':
printed_chars += print_x(va_arg(arg_list, unsigned int), 0);
break;
case 'X':
printed_chars += print_x(va_arg(arg_list, unsigned int), 1);
break;
default:
putchar('%');
putchar(*format);
printed_chars += 2;
break;
}
}
else
{
putchar(*format);
printed_chars++;
}

format++;
}
va_end(arg_list);
return (printed_chars);
}

/**
* print_u - prints an unsigned int in the specified base
* @n: the unsigned int to print
* @base: the base to print the number in (default 10)
* @is_uppercase: whether to print hex digits in uppercase (0 or 1)
*
* Return: the number of characters printed
*/

int print_u(unsigned int n, int base, int is_uppercase)
{
char buf[21];
int i = 0;
int printed_chars = 0;

do {
buf[i++] = (n % base) + (n % base < 10 ? '0' :
(is_uppercase ? 'A' : 'a') - 10);
n /= base;
} while (n > 0);

while (i > 0)
{
putchar(buf[--i]);
printed_chars++;
}

return (printed_chars);
}

/**
* print_o - prints an unsigned int in octal format
* @n: the unsigned int to print
*
* Return: the number of characters printed
*/

int print_o(unsigned int n)
{
char buf[12];
int i = 0;
int printed_chars = 0;

do {
buf[i++] = (n % 8) + '0';
n /= 8;
} while (n > 0);

while (i > 0)
{
putchar(buf[--i]);
printed_chars++;
}

return (printed_chars);
}

/**
* print_x - Prints an unsigned integer in hexadecimal notation.
* @n: The unsigned integer to print.
* @is_uppercase: Whether to use uppercase letters for hexadecimal notation.
*
* Return: The number of characters printed.
*/

int print_x(unsigned int n, int is_uppercase)
{
char buf[9];
const char *hex_chars = is_uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
int i = 0;
int printed_chars = 0;

do {
buf[i++] = hex_chars[n % 16];
n /= 16;
} while (n > 0);

while (i > 0)
{
putchar(buf[--i]);
printed_chars++;
}

return (printed_chars);
}

